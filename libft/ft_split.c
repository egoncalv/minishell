/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <egoncalv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 15:22:31 by egoncalv          #+#    #+#             */
/*   Updated: 2023/03/10 12:55:12 by egoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordcntr(const char *str, char c)
{
	int	i;
	int	cntr;

	i = 0;
	cntr = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != 0)
			cntr++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (cntr);
}

static char	*ft_strndup(const char *str, int n)
{
	char	*ptr;

	ptr = (char *)malloc(sizeof(char) * n + 1);
	if (!ptr)
		return (0);
	ptr = ft_memcpy(ptr, str, n);
	ptr[n] = '\0';
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**array;

	array = (char **)malloc(sizeof(char *) * ft_wordcntr(s, c) + 1);
	if (!array)
		return (0);
	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] != c && s[i])
			i++;
		if (i > j)
		{
			array[k] = ft_strndup(&s[j], i - j);
			k++;
		}
	}
	array[k] = 0;
	return (array);
}
