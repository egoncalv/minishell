/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <egoncalv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 13:54:14 by egoncalv          #+#    #+#             */
/*   Updated: 2023/03/10 14:32:29 by egoncalv         ###   ########.fr       */
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
		while (s[i] == ' ' || s[i] == '\t')
			i++;
		if(s[i] != 0)
			cntr++;
		while (s[i] && s[i] != ' ' && s[i] != '\t')
			i++;
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
	if (!args)
		return (0);
	i = 0;
	k = 0;
	while(s[i])
	{
		while (s[i] == ' ' || s[i] == '\t')
			i++;
		j = i;
		while (s[i] != ' ' && s[i] != '\t' && s[i])
			i++;
		if (i > j)
		{
			args[k] = ft_strndup(&s[j], i - j);
			k++;
		}
	}
	args[k] = 0;
	return (args);
}

