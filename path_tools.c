/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 18:03:49 by rvan-der          #+#    #+#             */
/*   Updated: 2017/03/15 18:53:27 by rvan-der         ###   ########.fr       */
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

	write(1, "\nowyeah\n", 8);
	i = -1;
	while (p1[++i] != -1)
	{
		write(1, "sisi\n", 5);
		j = -1;
		while (p2[++j] != -1)
		{
			write(1, "pl", 2);
			if (p1[i] == p2[j])
				return (1);
			write(1, "ouf", 3);
		}
		write(1, "end\n", 4);
	}
	write(1, "bam\n", 4);
	return (0);
}

int				path_nb(int *line, int p)
{
	int			i;
	int			ret;

	ret = 1;
	i = -1;
	while (++i < p)
		if (line[i] > 0)
			ret++;
	return (ret);
}

int				paths_sum(int *line, t_path **ptab, int lid, int p)
{
	int			i;
	int			ret;

	ret = (ptab[lid])->len - 2;
	i = -1;
	while (++i < p)
		if (line[i] > 0)
			ret += line[i];
	return (ret);
}
