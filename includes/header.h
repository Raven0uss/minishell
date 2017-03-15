/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 20:16:53 by sbelazou          #+#    #+#             */
/*   Updated: 2017/03/14 19:11:29 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <sys/wait.h>
# include "libft/libft.h"

int			ft_echo(int ac, char **av, int fd);
int			ft_cd(int ac, char **av);
int			ft_env(char **envp);
int			ft_setenv(int ac, char **av, char **envp);
int			exec_cmd(char **cmd, char **envp);

#endif
