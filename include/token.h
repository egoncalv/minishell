/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <egoncalv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:31:05 by egoncalv          #+#    #+#             */
/*   Updated: 2023/03/21 11:18:18 by egoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

//Redirections > >> < <<
# define R_INPUT 50
# define R_OUTPUT 51
# define R_DELIMITER 52
# define R_APPEND 53

//Pipes |
# define PIPE 54

//Env Variables $
# define ENV_VAR 55

//Built-ins
# define BUILTIN 56

//CMD options -
#define CMD_OPTIONS 57

//Exit status $?
#define EXIT_STATUS 58

typedef struct s_token
{
	struct s_token	*prev;
	int				type;
	char			*content;
	struct s_token	*next;
}				t_token;

t_token	*new_token(char *content);
void	insert_token(t_token **list, t_token *new);
t_token	*token_last(t_token *lst);

#endif
