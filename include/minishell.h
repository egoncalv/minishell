/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <egoncalv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 21:00:43 by egoncalv          #+#    #+#             */
/*   Updated: 2023/04/27 15:43:38 by egoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include "token.h"
# include "errors.h"
# include <sys/wait.h>
# include <stdio.h>
# include <dirent.h>
# include <errno.h>
# include <signal.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>


typedef struct s_command
{
	struct s_command	*prev;
	char				*command;
	char				**args;
	char				*redirect_in; // input redirection file path
	char				*redirect_out; // output redirection file path
	struct s_command	*next;
}				t_command;

typedef struct s_data
{
	char	*cur_line;
	char		**argv;
	char		**env;
	t_command	*cmd_table;
	int			fd_in;
	int			fd_out;
	int			paths;
}				t_data;

char	*give_prompt(void);

int		parse_line(t_data *data);
int		tokenize_line(t_token **token_list);

int		arg_count(char *s);
char	*ft_strndup(char *str, int n);
t_token	**split_args(char *s);
int		skip_quotes(char *s, int i);
int		skip_spaces(char *s, int i);
int		skip_letters(char *s, int i);
int		is_symbol(char *str);

t_command	*new_cmd(char *command);
void		insert_cmd(t_command *list, t_command *new);

#endif
