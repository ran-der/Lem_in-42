/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 18:54:32 by rvan-der          #+#    #+#             */
/*   Updated: 2017/03/29 20:34:19 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				ant_nb(t_map *map, int fd)
{
	char		*buf;
	int			i;
	int			ret;

	if (!get_next_line(fd, &buf))
		return (-1);
	map->output = ft_strdup((const char*)buf);
	i = 0;
	while (ft_isdigit(buf[i]))
		i++;
	if (buf[i] != '\0')
		return (-1);
	ret = ft_atoi(buf);
	ft_memdel((void**)(&buf));
	return (ret);
}

t_map			*init_map(void)
{
	t_map		*ret;

	if ((ret = (t_map*)malloc(sizeof(t_map))) == NULL)
		return (NULL);
	ret->output = NULL;
	ret->rooms = NULL;
	ret->links = NULL;
	return (ret);
}

t_map			*read_map(int fd)
{
	t_map		*ret;
	t_room		*rlist;
	char		*fstlink;

	rlist = NULL;
	fstlink = NULL;
	ret = init_map();
	if (!ret || (ret->n = ant_nb(ret, fd)) == -1)
		return (read_error(&ret));
	if (!(rlist = read_rooms(ret, &fstlink, fd)))
		return (read_error(&ret));
	ret->r = rlist_len(rlist);
	if (!(ret->rooms = make_rtab(rlist, ret->r)))
		return (read_error(&ret));
	if (!read_links(ret, fstlink, fd))
	{
		ft_memdel((void**)(&fstlink));
		return (read_error(&ret));
	}
	ft_memdel((void**)(&fstlink));
	return (ret);
}
