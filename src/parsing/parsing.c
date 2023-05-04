/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <egoncalv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:35:22 by egoncalv          #+#    #+#             */
/*   Updated: 2023/04/27 16:23:57 by egoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"


// echo2"ola, mundo"23>2t.txt23>>|2t2.txt23>>23>>23t3.txt232wc232ls
// 

int	parse_line(t_data *data)
{
	t_token		**token_list;
	t_token		*tmp;
	data->cmd_table = NULL;

	token_list = split_args(data->cur_line);
	tokenize_line(token_list);
	tmp = *token_list;
	if (tmp->next == NULL && tmp->type >= 50 && tmp->type <= 54)
		return (print_error(SYNTAX_NL));
	if (tmp->type >= 50 && tmp->type <= 53 && tmp->next->type == 54)
		return (print_error(SYNTAX_NL));
	while (tmp)
	{
		if (tmp->type == CMD || tmp->type == BUILTIN)
		{
			insert_cmd(data->cmd_table, new_cmd(tmp->content));
		}
		tmp = tmp->next;
	}
	return (1);
}

int	tokenize_line(t_token **token_list)
{
	t_token	*tmp;

	tmp = *token_list;
	while (tmp)
	{
		if (check_symbol(tmp))
			;
		else if (check_builtin(tmp))
			;
		else if (check_quotes(tmp))
			;
		else
			tmp->type = CMD;
		tmp = tmp->next;
	}
	return (0);
}

int	check_quotes(t_token *node)
{
	int	len;

	len = ft_strlen(node->content);
	if (node->content[0] == '"' && node->content[len - 1] == '"')
		node->type = DOUBLE_QUOTES;
	else if (node->content[0] == '\'' && node->content[len - 1] == '\'')
		node->type = SINGLE_QUOTES;
	else
		return (0);
	return (1);
}

int	check_builtin(t_token *node)
{
	if (!ft_strncmp(node->content, "echo", ft_strlen(node->content)))
		node->type = BUILTIN;
	else if (!ft_strncmp(node->content, "cd", ft_strlen(node->content)))
		node->type = BUILTIN;
	else if (!ft_strncmp(node->content, "pwd", ft_strlen(node->content)))
		node->type = BUILTIN;
	else if (!ft_strncmp(node->content, "export", ft_strlen(node->content)))
		node->type = BUILTIN;
	else if (!ft_strncmp(node->content, "unset", ft_strlen(node->content)))
		node->type = BUILTIN;
	else if (!ft_strncmp(node->content, "env", ft_strlen(node->content)))
		node->type = BUILTIN;
	else if (!ft_strncmp(node->content, "exit", ft_strlen(node->content)))
		node->type = BUILTIN;
	else
		return (0);
	return (1);
}

int	check_symbol(t_token *node)
{
	if (!ft_strncmp(node->content, ">", 1))
		node->type = R_OUTPUT;
	else if (!ft_strncmp(node->content, "<", 1))
		node->type = R_INPUT;
	else if (!ft_strncmp(node->content, "<<", 2))
		node->type = R_DELIMITER;
	else if (!ft_strncmp(node->content, ">>", 2))
		node->type = R_APPEND;
	else if (!ft_strncmp(node->content, "|", 1))
		node->type = PIPE;
	else if (!ft_strncmp(node->content, "$?", 2))
		node->type = EXIT_STATUS;
	else if (!ft_strncmp(node->content, "-", 1))
	{
		if (node->prev && (node->prev->type == CMD || node->prev->type == BUILTIN))
			node->type = CMD_OPTIONS;
	}
	else if (!ft_strncmp(node->content, "$", 1))
		node->type = ENV_VAR;
	else
		return (0);
	return (1);
}
