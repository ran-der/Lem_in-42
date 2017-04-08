/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 20:44:34 by rvan-der          #+#    #+#             */
/*   Updated: 2017/04/07 14:57:13 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			print_move(t_map *map, t_room *r1, t_room *r2, int color)
{
	write(1, "L", 1);
	if (color)
		ft_putstr(RED);
	ft_putnbr(r1->start ? map->n - r1->ant + 1 : r1->ant);
	ft_putstr(NRM);
	write(1, "-", 1);
	if (color)
		ft_putstr(YEL);
	ft_putstr((const char*)r2->name);
	if (color)
		ft_putstr(NRM);
}

void			move_ant(t_map *map, t_path *path, int i, int color)
{
	t_room		*r1;
	t_room		*r2;

	r1 = (map->rooms)[(path->pth)[i - 1]];
	r2 = (map->rooms)[(path->pth)[i]];
	print_move(map, r1, r2, color);
	if (r1->start)
	{
		r2->ant = (r2->end ? r2->ant + 1 : map->n - r1->ant + 1);
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

void			move_ants(t_path *path, t_map *map, int start, int color)
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
			move_ant(map, path, i, color);
		}
	}
}

void			play(t_map *map, t_path *paths, int color)
{
	t_path		*tmp;
	int			start;

	while (((map->rooms)[map->r - 1])->ant < map->n)
	{
		start = 1;
		tmp = paths;
		while (tmp != NULL)
		{
			move_ants(tmp, map, start, color);
			tmp = tmp->next;
			start = 0;
		}
		write(1, "\n", 1);
	}
}
