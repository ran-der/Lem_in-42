/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <rvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 17:19:17 by rvan-der          #+#    #+#             */
/*   Updated: 2017/03/01 20:43:42 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_file		*find_file(t_file **saved_files, int fd)
{
	t_file			*ret;

	ret = *saved_files;
	if (ret == NULL)
	{
		if ((ret = (t_file*)malloc(sizeof(t_file))) == NULL)
			return (NULL);
		if ((ret->line = ft_strnew(0)) == NULL)
			return (NULL);
		ret->fd = fd;
		ret->next = NULL;
		return (ret);
	}
	while (ret->next != NULL && ret->fd != fd)
		ret = ret->next;
	if (ret->fd != fd)
	{
		if ((ret->next = (t_file*)malloc(sizeof(t_file))) == NULL)
			return (NULL);
		if (((ret->next)->line = ft_strnew(0)) == NULL)
			return (NULL);
		(ret->next)->fd = fd;
		(ret->next)->next = NULL;
	}
	return (ret->fd != fd ? ret->next : ret);
}

void		delete_file(t_file **saved_files, int fd)
{
	t_file			*file;
	t_file			*tmp;

	file = *saved_files;
	if (file != NULL && file->fd == fd)
	{
		*saved_files = file->next;
		free(file->line);
		free(file);
		return ;
	}
	tmp = file;
	file = file->next;
	while (file != NULL && file->fd != fd)
	{
		tmp = file;
		file = file->next;
	}
	if (file != NULL)
	{
		tmp->next = file->next;
		free(file->line);
		free(file);
	}
}

char		*get_line(t_file **saved_files, int fd)
{
	int				i;
	char			*ret;
	t_file			*file;

	ret = NULL;
	file = *saved_files;
	while (file != NULL && file->fd != fd)
		file = file->next;
	if (file->line != NULL)
	{
		i = 0;
		while (file->line[i] != '\n' && file->line[i] != 26 && file->line[i])
			i++;
		if ((ret = (char*)malloc(sizeof(char) * (i + 1))) == NULL)
			return (NULL);
		i = -1;
		while (file->line[++i] != '\n' && file->line[i] != 26 && file->line[i])
			ret[i] = (file->line)[i];
		ret[i] = '\0';
		if ((file->line)[i] != '\0')
			file->line = ft_strcpy(file->line, (file->line) + i + 1);
		else
			ft_strclr(file->line);
	}
	return (ret);
}

int			parse_line(t_file **saved_files, int fd, char *buff)
{
	int				i;
	char			*old_line;
	t_file			*file;

	file = *saved_files;
	while (file != NULL && file->fd != fd)
		file = file->next;
	if (buff[0] != '\0')
	{
		old_line = file->line;
		file->line = ft_strjoin(file->line, buff);
		free(old_line);
	}
	i = -1;
	while ((file->line)[++i] != '\0')
		if ((file->line)[i] == '\n' || (file->line)[i] == 26)
			return (1);
	return (0);
}

int			get_next_line(int const fd, char **line)
{
	static t_file	*saved_files = NULL;
	char			buff[BUFF_SIZE + 1];
	int				ret;
	t_file			*file;

	if (fd < 0 || line == NULL)
		return (-1);
	if ((file = find_file(&saved_files, fd)) == NULL)
		return (-1);
	saved_files = (saved_files == NULL ? file : saved_files);
	ret = 0;
	buff[0] = '\0';
	while (!parse_line(&saved_files, fd, (char*)buff) &&\
			(ret = read(fd, buff, BUFF_SIZE)) != 0)
	{
		if (ret == -1)
			return (-1);
		buff[ret] = '\0';
	}
	if (ret == 0 && (file->line)[0] == '\0')
	{
		delete_file(&saved_files, fd);
		return (0);
	}
	return ((*line = get_line(&saved_files, fd)) == NULL ? -1 : 1);
}
