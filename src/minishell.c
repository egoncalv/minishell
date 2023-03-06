/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <egoncalv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 21:00:34 by egoncalv          #+#    #+#             */
/*   Updated: 2023/03/06 19:14:42 by egoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_data	data;

	(void)argc; // Just so it can compile with flags, we can remove these lines after using the variables
	(void)argv;
	(void)env;

	while (1) // While no exit() or ctrl+c / ctrl+d
		data.cur_line = give_prompt();
	return (0);
}
