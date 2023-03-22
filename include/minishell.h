/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <egoncalv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 21:00:43 by egoncalv          #+#    #+#             */
/*   Updated: 2023/03/21 17:13:13 by egoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "token.h"
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

typedef struct s_command
{
	char				*command;
	char				**args;
	char				*redirect_in; // input redirection file path
	char				*redirect_out; // output redirection file path
	struct s_command	*next;
}				t_command;

typedef struct s_shell_env
{
	char		**argv;
	char		**env;
	t_command	*command;
	int			fd_in;
	int			fd_out;
	int			paths;
}				t_shell_env;

char	*give_prompt(void);

int		parse_line(t_data *data);
int		tokenize_line(t_token **token_list);

int		arg_count(char *s);
char	*ft_strndup(char *str, int n);
t_token	**split_args(char *s);
int		skip_quotes(char *s, int i);
int		skip_spaces(char *s, int i);
int		skip_letters(char *s, int i);

#endif
