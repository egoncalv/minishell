/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 21:00:43 by egoncalv          #+#    #+#             */
/*   Updated: 2023/02/25 21:00:43 by egoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINISHELL_H
# define MINISHELL_H

# include <sys/wait.h>
# include <stdio.h>
# include <dirent.h>
# include <errno.h>
# include <signal.h>


typedef struct			s_command
{
	char				**args;
}						t_command;

struct typedef struct			s_shell_env
{
	char				**argv;
	char				**env;
	t_command			*command;
    int                 fd_in;
    int                 fd_out; 
}	