/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <egoncalv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 13:54:14 by egoncalv          #+#    #+#             */
/*   Updated: 2023/03/21 10:39:39 by egoncalv         ###   ########.fr       */
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
				i = skip_letters(s, i);
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

t_token	**split_args(char *s)
{
	int		i;
	int		j;
	t_token	**args;

	args = ft_calloc(sizeof(t_token), arg_count(s) + 1);
	i = 0;
	while (s[i])
	{
		i = skip_spaces(s, i);
		j = i;
		if (s[i] == '"')
			i = skip_quotes(s, i);
		else
			i = skip_letters(s, i);
		if (i > j)
			insert_token(args, new_token(ft_strndup(&s[j], i - j)));
	}
	return (args);
}
