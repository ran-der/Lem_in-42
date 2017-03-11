/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_paths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 17:55:10 by rvan-der          #+#    #+#             */
/*   Updated: 2017/03/11 22:08:59 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			set_line(int *line, t_path **ptab, int p)
{
	int			i;
	int			j;

	i = -1;
	while (++i < p - 1)
	{
		if (line[i] > 0)
		{
			j = i;
			while (++j < p)
			{
				if (line[j] > 0 && paths_cross((ptab[i])->pth, (ptab[j])->pth))
				{
					if ((ptab[i])->len > (ptab[j])->len)
					{
						line[i] = 0;
						break ;
					}
					line[j] = 0;
				}
			}
		}
	}
}

void			fill_ctab(int **ctab, t_path **ptab, int p)
{
	int			i;
	int			j;

	i = -1;
	while (++i < p)
	{
		j = i;
		ctab[i][j] = 0;
		while (++j < p)
		{
			ctab[i][j] = 0;
			if (paths_cross((ptab[i])->pth, (ptab[j])->pth))
				ctab[i][j] = (ptab[j])->len;
			ctab[j][i] = ctab[i][j];
		}
	}
	i = -1;
	while (++i < p)
		set_line(ctab[i], ptab, p);
}
							

void			set_ptab(t_path **ptab, t_path *paths)
{
	t_path		*tmp;
	int			i;
	
	if ((tmp = paths) != NULL)
	{
		i = 0;
		while (tmp != NULL)
		{
			ptab[i] = tmp;
			i++;
			tmp = tmp->next;
		}
	}
}

int				*select_best_set(int **ctab, t_path **ptab, int p)
{
	int			ret[p];
	int			sum;
	int			nb;
	int			tmp;
	int			i;

	nb = path_nb(ctab[0], 0, p);
	sum = paths_sum(ctab[0], ptab, 0, p);
	i = 0;
	while (++i < p)
	{
		if ((tmp = path_nb(ctab[i], i, p)) >= c)

t_paths			*select_paths(t_map map, t_path *paths, int p)
{
	int			ctab[p][p];
	t_path		*ptab[p];
	int			*best_set;
	t_path		*ret;
	int			i;

	set_ptab((t_path**)ptab, paths);
	fill_ctab((int**)ctab, (t_path**)ptab, p);
	best_set = select_best_set(ctab, map);
