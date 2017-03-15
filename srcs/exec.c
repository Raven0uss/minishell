/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 18:58:04 by sbelazou          #+#    #+#             */
/*   Updated: 2017/03/14 19:12:55 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

// CREATION CHEMIN ABSOLU AVEC RECHERCHE DU PATH POUR EXECVE

int		exec_cmd(char **cmd, char **envp)
{
	if (access(cmd[0], X_OK | F_OK) == 0)
	{
		if (fork() == 0)
			execve(cmd[0], cmd, envp);
		wait(NULL);
	}
	else
	{
		ft_putstr(cmd[0]);
		ft_putendl(": command not found");
	}
	return (0);
}
