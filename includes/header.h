/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 20:16:53 by sbelazou          #+#    #+#             */
/*   Updated: 2017/03/28 14:36:12 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <sys/wait.h>
# include "libft/libft.h"

int			ft_echo(int ac, char **av, int fd, char **envp);
int			ft_cd(int ac, char **av, char **envp);
void		replace_var(char **envp, char const *var);
int			ft_env(int ac, char **av, char **envp);
int			ft_setenv(int ac, char **av, char **envp);
int			ft_unsetenv(int ac, char **av, char **envp, int mode);
int			exec_cmd(char **cmd, char **envp);

#endif
