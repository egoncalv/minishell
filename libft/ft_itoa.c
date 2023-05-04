/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:01:58 by egoncalv          #+#    #+#             */
/*   Updated: 2021/12/22 13:42:33 by egoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_nbr(int n)
{
	int		count;
	long	res;

	res = n;
	count = 1;
	if (res < 0)
	{
		count++;
		res *= (-1);
	}
	while (res >= 10)
	{
		count++;
		res /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	res;
	int		i;

	i = 0;
	str = (char *)malloc(sizeof(char) * count_nbr(n) + 1);
	if (!str)
		return (NULL);
	if (n < 0)
		str[0] = '-';
	res = n;
	if (res < 0)
		res *= (-1);
	str[count_nbr(n) - i++] = '\0';
	while (res >= 10)
	{
		str[count_nbr(n) - i++] = (res % 10) + '0';
		res /= 10;
	}
	str[count_nbr(n) - i++] = (res % 10) + '0';
	return (str);
}
