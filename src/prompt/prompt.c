/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <egoncalv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 21:42:33 by egoncalv          #+#    #+#             */
/*   Updated: 2023/03/06 19:16:21 by egoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// This function gives the prompt to the user, saves
// the input to the history and returns it.
char	*give_prompt()
{
	char	*input_line;

	input_line = readline("Minishell > ");
	if (input_line && *input_line)
		add_history(input_line);
	return (input_line);
}
