/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <egoncalv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:41:42 by egoncalv          #+#    #+#             */
/*   Updated: 2023/03/21 11:19:22 by egoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	skip_quotes(char *s, int i)
{
	if (s[i] == '"')
	{
		while (s[++i] && s[i] != '"')
			;
	}
	else if (s[i] == '\'')
	{
		while (s[++i] && s[i] != '\'')
			;
	}
	i++;
	return (i);
}

int	skip_spaces(char *s, int i)
{
	while (s[i] && (s[i] == ' ' || s[i] == '\t'))
		i++;
	return (i);
}

int	skip_letters(char *s, int i)
{
	while (s[i] && s[i] != ' ' && s[i] != '\t')
		i++;
	return (i);
}
