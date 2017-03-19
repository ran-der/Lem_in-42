/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_link.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 16:27:39 by rvan-der          #+#    #+#             */
/*   Updated: 2017/03/19 22:39:59 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			add_link(int **links, int r1, int r2)
{
	int			i;

	i = 0;
	while (links[r1][i] != -1)
		i++;
	links[r1][i] = r2;
	i = 0;
	while (links[r2][i] != -1)
		i++;
	links[r2][i] = r1;
}

int				make_link(char *buf, t_map *map)
{
	int			r1;
	int			r2;
	char		name1[22];
	char		name2[22];
	int			i;

	i = 0;
	while (buf[i] && buf[i] != '-')
	{
		name1[i] = buf[i];
		i++;
	}
	name1[i] = '\0';
	ft_strcpy((char*)name2, buf + i + 1);
	r1 = room_id(map->rooms, map->r, (char*)name1);
	r2 = room_id(map->rooms, map->r, (char*)name2);
	if (r1 == -1 || r2 == -1)
		return (0);
	if (!already_linked(map, r1, r2))
		add_link(map->links, r1, r2);
	return (1);
}

int				init_links(t_map *map)
{
	int			i;
	int			j;

	if ((map->links = (int**)malloc(sizeof(int*) * map->r)) == NULL)
		return (0);
	i = -1;
	while (++i < map->r)
	{
		if (((map->links)[i] = (int*)malloc(sizeof(int) * (map->r + 1))) \
							== NULL)
			return (0);
		j = -1;
		while (++j <= map->r)
			(map->links)[i][j] = -1;
	}
	return (1);
}

int				read_links(t_map *map, char *fstlink)
{
	int			cmd;
	char		*buf;

	if (!init_links(map))
		return (0);
	if (!make_link(fstlink, map))
		return (0);
	while (get_next_line(0, &buf))
	{
		if ((cmd = check_buff(&buf, map, 1)) > -2 && cmd < 3)
		{
			free(buf);
			return (0);
		}
		if (cmd == 3 && !make_link(buf, map))
		{
			free(buf);
			return (0);
		}
		free(buf);
	}
	return (1);
}
