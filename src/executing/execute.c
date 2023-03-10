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