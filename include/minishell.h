/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <egoncalv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 21:00:43 by egoncalv          #+#    #+#             */
/*   Updated: 2023/02/27 23:20:08 by egoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINISHELL_H
# define MINISHELL_H

# include <sys/wait.h>
# include <stdio.h>
# include <dirent.h>
# include <errno.h>
# include <signal.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_data
{
	char	*cur_line;
}				t_data;

typedef struct			s_command
{
	char				**args;
}						t_command;

struct typedef struct			s_shell_env
{
	char				**argv;
	char				**env;
	t_command			*command;
    int                 fd_in;
    int                 fd_out; 
}	

char	*give_prompt();

#endif
