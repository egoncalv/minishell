/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <egoncalv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:35:22 by egoncalv          #+#    #+#             */
/*   Updated: 2023/03/20 16:37:47 by egoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	parse_line(t_data *data)
{
	t_token	*token_list;

	token_list = split_args(data->cur_line);
	tokenize_line(token_list);
	return (0);
}

int	tokenize_line(t_token *token_list)
{
	(void)token_list;
	return (0);
}
