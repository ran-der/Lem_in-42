/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_rooms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 19:49:08 by rvan-der          #+#    #+#             */
/*   Updated: 2017/03/11 15:10:14 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room			**make_rtab(t_room *rlist, int size)
{
	int			id;
	t_room		*tmp;
	t_room		**ret;

	if ((tmp = rlist) != NULL)
	{
		if ((ret = (t_room**)malloc(sizeof(t_room*) * size)) == NULL)
			return (NULL);
		id = -1;
		while (++id < size)
		{
			tmp->id = id;
			ret[i] = tmp;
			tmp = tmp->next;
		}
		return (ret);
	}
	return (NULL);
}

t_room			*read_rooms(t_map *map, char **fstlink)
{
	int			cmd;
	int			tmp;
	char		*buf;
	t_room		*ret;

	tmp = 0;
	cmd = 0;
	ret = NULL;
	while (cmd != 3 && get_next_line(0, &buf))
	{
		if ((cmd = check_buff(&buf, map, 0)) == -1 || \
				(cmd == 1 && (tmp == 1 || tmp == 3)) || \
				(cmd == 2 && (tmp == 2 || tmp == 3)))
			return (NULL);
		if (cmd != -2 && cmd != 3 && (tmp += cmd) > -1)
			get_room(buf, &ret, cmd);
		if (cmd != 3)
			ft_memdel((void**)(&buf));
	}
	if (cmd != 3)
		return (NULL);
	*fstlink = buf;
	return (ret);
}
