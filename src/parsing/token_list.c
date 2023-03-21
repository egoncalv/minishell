/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <egoncalv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 10:33:01 by egoncalv          #+#    #+#             */
/*   Updated: 2023/03/21 10:34:27 by egoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_token	*new_token(char *content)
{
	t_token	*new;

	new = malloc(sizeof(t_token));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	new->type = 0;
	new->prev = NULL;
	return (new);
}

void	insert_token(t_token **list, t_token *new)
{
	t_token	*current_node;

	if (*list == NULL)
		*list = new;
	else
	{
		current_node = *list;
		while (current_node->next != NULL)
			current_node = current_node->next;
		current_node->next = new;
		new->prev = current_node;
	}
}
