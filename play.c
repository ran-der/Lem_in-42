/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 20:44:34 by rvan-der          #+#    #+#             */
/*   Updated: 2017/03/19 20:46:53 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			move_ant(t_map *map, t_path *path, t_room *r1, t_room *r2)
{
	char		*tmp;

	write(1, "L", 1);
	ft_putstr((const char*)(tmp = \
						ft_itoa(r1->start ? map->n - r1->ant + 1 : r1->ant)));
	write(1, "-", 1);
	free(tmp);
	ft_putstr((const char*)r2->name);
	if (r1->start)
	{
		r2->ant = map->n - r1->ant + 1;
		r1->ant -= 1;
		path->pass -= 1;
	}
	else
	{
		if (r2->end)
			r2->ant += 1;
		else
			r2->ant = r1->ant;
		r1->ant = 0;
	}
}

void			move_ants(t_path *path, t_map *map, int start)
{
	int			i;
	int			*p;

	p = path->pth;
	if (((map->rooms)[p[(i = path->len) - 1]])->ant == map->n)
		return ;
	while (--i > 0)
	{
		if (((map->rooms)[p[i - 1]])->ant > 0 && !(i == 1 && !(path->pass)))
		{
			if (!start)
				write(1, " ", 1);
			start = 0;
			move_ant(map, path, ((map->rooms)[p[i - 1]]), \
									((map->rooms)[p[i]]));
		}
	}
}

void			play(t_map *map, t_path *paths)
{
	t_path		*tmp;
	int			start;

	while (((map->rooms)[map->r - 1])->ant < map->n)
	{
		start = 1;
		tmp = paths;
		while (tmp != NULL)
		{
			move_ants(tmp, map, start);
			tmp = tmp->next;
			start = 0;
		}
		write(1, "\n", 1);
	}
}
