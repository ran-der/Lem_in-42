/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 18:54:32 by rvan-der          #+#    #+#             */
/*   Updated: 2017/03/13 17:06:39 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				ant_nb(t_map *map)
{
	char		*buf;
	int			i;
	int			ret;

	if (!get_next_line(0, &buf))
		return (-1);
	printf("output1 (%p): %s\n", map->output, map->output);
	map->output = ft_dstrjoin(map->output, buf);
	printf("output2 (%p): %s\n", map->output,  map->output);
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

t_map			*read_map(void)
{
	t_map		*ret;
	t_room		*rlist;
	char		*fstlink;

	write(1, "0.0\n", 4);
	if ((ret = init_map()) == NULL)
		write(1, "NULL\n", 5);
	write(1, "0.1\n", 4);
	if (!ret || (ret->n = ant_nb(ret)) == -1)
		return (rd_error(&ret));
	write(1, "0.2\n", 4);
	if (!(rlist = read_rooms(ret, &fstlink)))
		return (rd_error(&ret));
	write(1, "0.3\n", 4);
	ret->r = rlist_len(rlist);
	write(1, "0.4\n", 4);
	if (!(ret->rooms = make_rtab(rlist, ret->r)))
		return (rd_error(&ret));
	write(1, "0.5\n", 4);
	if (!read_links(ret, fstlink))
	{
		write(1, "0.5+\n", 5);
		ft_memdel((void**)(&fstlink));
		return (rd_error(&ret));
	}
	write(1, "0.5-\n", 5);
	ft_memdel((void**)(&fstlink));
	write(1, "0.6\n", 4);
	return (ret);
}
