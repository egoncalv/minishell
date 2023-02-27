/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <egoncalv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 21:42:33 by egoncalv          #+#    #+#             */
/*   Updated: 2023/02/27 23:22:16 by egoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*give_prompt()
{
	char	*input_line;

	input_line = readline("Minishell > ");
	if (input_line && *input_line)
		add_history(input_line);
	return (input_line);
}
