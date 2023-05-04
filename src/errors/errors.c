/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <egoncalv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 11:39:39 by egoncalv          #+#    #+#             */
/*   Updated: 2023/03/28 11:54:14 by egoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	print_error(int	error_code)
{
	if (error_code == SYNTAX_NL)
		printf("minishell: syntax error near unexpected token `newline'\n");

	return (0);
}
