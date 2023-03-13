int run_functions(t_shell_env *env, t_command *cmd) {
    if (ft_strcmp(cmd->args[0], "echo") == 0) {
        return run_echo(env, cmd->args + 1);
    } else if (ft_strcmp(cmd->args[0], "cd") == 0) {
        return run_cd(env, cmd->args + 1);
    } else if (ft_strcmp(cmd->args[0], "pwd") == 0) {
        return run_pwd(env);
    } else if (ft_strcmp(cmd->args[0], "export") == 0) {
        return run_export(env, cmd->args + 1);
    } else if (ft_strcmp(cmd->args[0], "unset") == 0) {
        return run_unset(env, cmd->args + 1);
    } else if (ft_strcmp(cmd->args[0], "env") == 0) {
        return run_env(env);
    } else if (ft_strcmp(cmd->args[0], "exit") == 0) {
        return run_exit(env, cmd->args + 1);
    }
    return 0;
}


char	*get_command_path(t_shell_env *env, char *command)
{
    char	**paths = env->paths;
    char	*temp;
    char	*command_path;
    struct stat	stat_buf; //struct stat is a data structure in C. It stores information about a file system object. Stat_buf stores info about the file found at a particular path. We check here if the file at the specified path is executable and readable

    while (*paths != NULL)
    {
        temp = ft_strjoin(*paths, "/");
        command_path = ft_strjoin(temp, command); //we get smth like /usr/bin/ls This full path can then be used by the execve system call to execute the command.
        free(temp);
        if (stat(command_path, &stat_buf) == 0 && (stat_buf.st_mode & S_IXUSR)) //stat - file at the `command_path` exists and is executable//
            return (command_path);
        free(command_path);
        paths++;
    }
    return (NULL);
}

//Here we create a child process. We do it because if we execute it in the parent process, 
//the shell would lose control over the terminal until the command is completed. 
//In this case the shell can continue to run in the parent process and be ready to execute more commands from the user.

int execute_command(t_shell_env *env, t_command *cmd, char *command_path) {
    pid_t pid;
    int status;

    pid = fork(); //creates a new process by duplicating the calling process
    if (pid == -1) { //fork failed
        perror("fork");
        return 1;
    } else if (pid == 0) { //child process
        if (cmd->redirect_in != NULL) { //input redirection. We use it when the user wants to provide input to a command from a file.
        //For example, from a text file. We use "<" symbol followed by the name of the input file: "program < input.txt" will run "my_program" and provide "input.txt" as input to the program.
            int fd_in = open(cmd->redirect_in, O_RDONLY);
            if (fd_in < 0) {
                perror("open input file");
                exit(1);
            }
            dup2(fd_in, STDIN_FILENO); //copy the fd for the input file (fd_in) to the file descriptor for standard input  
            //any input operations in the child process will read from the input file NOT the keyboard. 
            close(fd_in);
        } else if (env->fd_in != STDIN_FILENO) { //if the input was previously redirected, restore it (we already have the fd_in in STDIN_FILENO)
            dup2(env->fd_in, STDIN_FILENO); //if we don't restore STDIN_FILENO we risk using an unintended input stream.
        }

        if (cmd->redirect_out != NULL) { //output redirection. 
            int fd_out = open(cmd->redirect_out, O_WRONLY | O_CREAT | O_TRUNC, 0644); //truncate the file to zero length before opening it.
            //the file permissions are set to 0644 - the owner of the file has read and write permissions (4 = read, 2 = write),
            if (fd_out < 0) {
                perror("open output file");
                exit(1);
            }
            dup2(fd_out, STDOUT_FILENO);
            close(fd_out);
        } else if (env->fd_out != STDOUT_FILENO) { //if the output was previously redirected, restore it
            dup2(env->fd_out, STDOUT_FILENO);
        }

        execve(command_path, cmd->args, env->env); //executes the command with the arguments and the environment variables
        perror("execve"); //execve will only return if an error occurred
        exit(1);
    } 
    else { // parent process
    int status;
    waitpid(pid, &status, 0); //wait for the child process to finish and retrieve its status
    
    while (!WIFEXITED(status) && !WIFSIGNALED(status)) { 
        waitpid(pid, &status, 0);
    }

    if (WIFEXITED(status)) { // child process terminated normally
        return WEXITSTATUS(status); // returns the status code of the child process
    } else { // child process terminated abnormally
        return 1;
    }
}
}

void execute(t_shell_env *env) 
{
    t_command *cmd = env->command; //a pointer to the 1 command in the t_shell_env struct.
    env->fd_in = dup(STDIN_FILENO); // duplicates the standard input file descriptor and stores it in the fd_in
    env->fd_out = dup(STDOUT_FILENO); // same for  output file 

    while (cmd != NULL) { //executes each command in the command list.
        if (run_functions(env, cmd) == 0) { //a built-in command or not.
            char *command_path = get_command_path(env->env, cmd->args[0]); //gets the path to the command executable file
            if (command_path == NULL) { //checks if the command executable file exists.
                printf("Command not found: %s\n", cmd->args[0]);
                env->status = 127; // sets the status code to 127 to indicate an error.
            } else {
                env->status = execute_command(env, cmd, command_path); //executes the command and stores the status code in the status
                free(command_path);
            }
        }
        dup2(env->fd_in, STDIN_FILENO); //restores the standard input file descriptor for the next command.
        dup2(env->fd_out, STDOUT_FILENO); //same for output file
        cmd = cmd->next; //moves to the next command in the list.
    }
    close(env->fd_in); // closes the duplicated standard input file descriptor.
    close(env->fd_out); //same for the duplicated standard output file descriptor.
}