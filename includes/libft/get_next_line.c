/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 16:59:28 by sbelazou          #+#    #+#             */
/*   Updated: 2017/02/24 17:49:37 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*stack_aodel(char *line, char *buff, int mode)
{
	int			i;

	i = 0;
	if (mode == 1)
	{
		if (!line)
			line = ft_strdup(buff);
		else
			line = ft_strjoin(line, buff);
	}
	else if (mode == 2)
	{
		while (line[i] && line[i] != '\n')
			i++;
		while (line[i])
			line[i++] = 0;
	}
	return (line);
}

static char		*keep_afterendl(char *buff)
{
	int			i;
	int			j;
	char		*tmp;

	j = 0;
	i = 0;
	tmp = ft_memalloc(BUFF_SIZE + 1);
	while (buff[i] && buff[i] != '\n')
		i++;
	if (buff[i] == '\n')
		i++;
	while (buff[i])
		tmp[j++] = buff[i++];
	tmp[j] = 0;
	ft_strdel(&buff);
	buff = ft_strdup(tmp);
	ft_strdel(&tmp);
	return (buff);
}

static int		buff_modif(char **line, char **buff, int *flag)
{
	*flag = 0;
	*line = stack_aodel(*line, *buff, 1);
	if (ft_strchr(*line, '\n') != NULL)
	{
		*line = stack_aodel(*line, *buff, 2);
		*buff = keep_afterendl(*buff);
		return (1);
	}
	ft_strdel(buff);
	*flag = 1;
	return (0);
}

static int		only_endl(char *str)
{
	int			i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static char	*buff = NULL;
	int			ret;
	int			flag;

	flag = 0;
	if (fd < 0 || !line || read(fd, NULL, 0) == -1)
		return (-1);
	*line = NULL;
	if (buff && buff_modif(line, &buff, &flag) == 1)
		return (1);
	buff = ft_memalloc(BUFF_SIZE + 1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = 0;
		if (buff_modif(line, &buff, &flag) == 1)
			return (1);
		buff = ft_memalloc(BUFF_SIZE + 1);
	}
	ft_strdel(&buff);
	if (*line && flag && only_endl(*line))
		return (1);
	if (ret < 0)
		return (-1);
	return (0);
}
