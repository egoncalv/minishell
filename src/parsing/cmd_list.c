/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <egoncalv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:26:31 by egoncalv          #+#    #+#             */
/*   Updated: 2023/04/27 15:43:23 by egoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../include/minishell.h"

t_command	*new_cmd(char *command)
{
	t_command *new;

	new = malloc(sizeof(t_command));
	if (!new)
		return (NULL);
	new->command = command;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	insert_cmd(t_command *list, t_command *new)
{
	t_command	*current_node;

	if (list == NULL)
		list = new;
	else
	{
		current_node = list;
		while (current_node->next != NULL)
			current_node = current_node->next;
		current_node->next = new;
		new->prev = current_node;
	}
}
