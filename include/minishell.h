/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <egoncalv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 21:00:43 by egoncalv          #+#    #+#             */
/*   Updated: 2023/03/10 12:45:40 by egoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
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
	struct s_command	*next;
}						t_command;

typedef struct			s_shell_env
{
	char				**argv;
	char				**env;
	t_command			*command;
    int                 fd_in;
    int                 fd_out; 
}						t_shell_env;

char	*give_prompt();
int		parse_line(t_data *data);
int		tokenize_line(t_data *data);

#endif
