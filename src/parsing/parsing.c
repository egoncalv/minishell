/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <egoncalv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:35:22 by egoncalv          #+#    #+#             */
/*   Updated: 2023/03/21 11:33:59 by egoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	parse_line(t_data *data)
{
	t_token	**token_list;

	token_list = split_args(data->cur_line);
	tokenize_line(token_list);
	return (0);
}

int	tokenize_line(t_token **token_list)
{
	t_token	*tmp;

	tmp = *token_list;
	while (tmp)
	{
		if (is_symbol(tmp))
			;
		else if (is_builtin(tmp))
			;
		else if (is_quoted(tmp))
			;
		printf("\n%s\t%d\n", tmp->content, tmp->type);
		tmp = tmp->next;
	}
	return (0);
}

int	is_quoted(t_token *node)
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

int	is_builtin(t_token *node)
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

int	is_symbol(t_token *node)
{
	if (!ft_strncmp(node->content, ">", ft_strlen(node->content)))
		node->type = R_OUTPUT;
	else if (!ft_strncmp(node->content, "<", ft_strlen(node->content)))
		node->type = R_INPUT;
	else if (!ft_strncmp(node->content, "<<", ft_strlen(node->content)))
		node->type = R_DELIMITER;
	else if (!ft_strncmp(node->content, ">>", ft_strlen(node->content)))
		node->type = R_APPEND;
	else if (!ft_strncmp(node->content, "|", ft_strlen(node->content)))
		node->type = PIPE;
	else if (!ft_strncmp(node->content, "$?", ft_strlen(node->content)))
		node->type = EXIT_STATUS;
	else if (node->content[0] == '-')
		node->type = CMD_OPTIONS;
	else if (node->content[0] == '$')
		node->type = ENV_VAR;
	else
		return (0);
	return (1);
}
