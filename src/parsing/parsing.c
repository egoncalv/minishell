/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <egoncalv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:35:22 by egoncalv          #+#    #+#             */
/*   Updated: 2023/03/13 15:47:20 by egoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	parse_line(t_data *data)
{
	char	**args;

	args = split_args(data->cur_line);
	tokenize_line(args);
	return (0);
}

int	tokenize_line(char **args)
{
	(void)args;
	return (0);
}
