/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 20:32:04 by rvan-der          #+#    #+#             */
/*   Updated: 2017/03/18 20:34:07 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				already_linked(t_map *map, int r1, int r2)
{
	int			i;

	i = 0;
	while (i < map->r && (map->links)[r1][i] != -1 && \
			(map->links)[r1][i] != r2)
		i++;
	return ((map->links)[r1][i] == r2 ? 1 : 0);
}

int				tabsize(char **tab)
{
	int			ret;

	ret = 1;
	while (tab[ret] != NULL)
		ret++;
	return (ret);
}
