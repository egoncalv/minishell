/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <egoncalv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 13:54:14 by egoncalv          #+#    #+#             */
/*   Updated: 2023/03/13 13:29:12 by egoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	arg_count(char *s)
{
	int	i;
	int	cntr;

	i = 0;
	cntr = 0;
	while (s[i])
	{
		i = skip_spaces(s, i);
		if (s[i] != 0)
		{
			if (s[i] == '"')
				i = skip_quotes(s, i);
			else
				skip_spaces(s, i);
			cntr++;
		}
	}
	return (cntr);
}

char	*ft_strndup(char *str, int n)
{
	char	*arg;

	arg = (char *)malloc(sizeof(char) * n + 1);
	if (!arg)
		return (0);
	arg = ft_memcpy(arg, str, n);
	arg[n] = '\0';
	return (arg);
}

char	**split_args(char *s)
{
	int		i;
	int		j;
	int		k;
	char	**args;

	args = malloc(sizeof(char *) * (arg_count(s) + 1));
	i = 0;
	k = 0;
	while (s[i])
	{
		i = skip_spaces(s, i);
		j = i;
		if (s[i] == '"')
			i = skip_quotes(s, i);
		else
			i = skip_spaces(s, i);
		if (i > j)
		{
			args[k] = ft_strndup(&s[j], i - j);
			k++;
		}
	}
	args[k] = 0;
	return (args);
}

int	skip_quotes(char *s, int i)
{
	while (s[++i] && s[i] != '"')
		;
	i++;
	return (i);
}

int	skip_spaces(char *s, int i)
{
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	return (i);
}
