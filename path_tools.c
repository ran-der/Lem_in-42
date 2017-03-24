/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 18:03:49 by rvan-der          #+#    #+#             */
/*   Updated: 2017/03/24 22:12:43 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				pathlen(int *path)
{
	int			ret;

	ret = 0;
	while (path[ret] > -1)
		ret++;
	return (ret);
}

int				paths_cross(int *p1, int *p2)
{
	int			i;
	int			j;

	i = 0;
	while (p1[++i + 1] != -1)
	{
		j = -1;
		while (p2[++j + 1] != -1)
			if (p1[i] == p2[j])
				return (1);
	}
	return (0);
}

int				path_nb(int *line, int p)
{
	int			i;
	int			ret;

	ret = 0;
	i = -1;
	while (++i < p)
		if (line[i] > -1)
			ret++;
	return (ret);
}

int				paths_sum(int *line, int p)
{
	int			i;
	int			ret;

	i = -1;
	ret = 0;
	while (++i < p)
		if (line[i] > -1)
			ret += line[i];
	return (ret);
}
