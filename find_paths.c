/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 16:15:18 by rvan-der          #+#    #+#             */
/*   Updated: 2017/03/19 20:42:55 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			find_all(int id, int *current, t_path **ret, t_map map)
{
	int			i;

	((map.rooms)[id])->mark = 1;
	current[pathlen(current)] = id;
	if (((map.rooms)[id])->end)
		path_add(new_path(current), ret);
	else
	{
		i = -1;
		while ((map.links)[id][++i] != -1)
			if (!(((map.rooms)[(map.links)[id][i]])->mark))
				find_all((map.links)[id][i], current, ret, map);
	}
	((map.rooms)[id])->mark = 0;
	current[pathlen(current) - 1] = -1;
}

t_path			*find_paths(t_map *map)
{
	t_path		*ret;
	int			current[map->r + 1];
	int			i;

	i = -1;
	while (++i < map->r + 1)
		current[i] = -1;
	ret = NULL;
	find_all(0, (int*)current, &ret, *map);
	return (ret);
}
