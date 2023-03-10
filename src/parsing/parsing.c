/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <egoncalv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:35:22 by egoncalv          #+#    #+#             */
/*   Updated: 2023/03/10 13:45:38 by egoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	parse_line(t_data *data)
{
	tokenize_line(data);
	
	return (0);
}

int	tokenize_line(t_data *data)
{
	
	return(0);
}

int	arg_count(char *s)
{
	int	i;
	int	cntr;

	i = 0;
	cntr = 0;
	while (s[i])
	{
		while (s[i] == ' ' || s[i] == '\t')
			
		i++;
	}
}

char	**split_args(char *s)
{
	char	**args;
}
