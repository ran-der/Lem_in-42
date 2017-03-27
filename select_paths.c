/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_paths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 17:55:10 by rvan-der          #+#    #+#             */
/*   Updated: 2017/03/27 21:47:21 by rvan-der         ###   ########.fr       */
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
		if (line[i] > -1)
		{
			j = i;
			while (++j < p)
			{
				if (line[j] > -1 && paths_cross((ptab[i])->pth, (ptab[j])->pth))
				{
					if ((ptab[i])->len > (ptab[j])->len)
					{
						line[i] = -1;
						break ;
					}
					line[j] = -1;
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
		ctab[i][j] = (ptab[i])->len - 2;
		while (++j < p)
		{
			ctab[i][j] = -1;
			if (!paths_cross((ptab[i])->pth, (ptab[j])->pth))
				ctab[i][j] = (ptab[j])->len - 2;
			ctab[j][i] = ctab[i][j];
		}
	}
	i = -1;
	while (++i < p)
		set_line(ctab[i], ptab, p);
}

t_path			*select_paths(t_map map, t_path *paths, int p)
{
	int			**ctab;
	t_path		**ptab;
	t_set		*best_set;
	t_path		*ret;
	int			i;

	ptab = make_ptab(paths, p);
	ctab = init_ctab(p);
	fill_ctab(ctab, ptab, p);
	if ((best_set = select_best_set(ctab, ptab, p, map.n)) == NULL)
	{
		clear_slct_pth(ctab, ptab, best_set, p);
		write(1, "PATH ERROR\n", 11);
		return (NULL);
	}
	ret = NULL;
	i = -1;
	while (++i < best_set->pnb)
		path_add(new_path((ptab[(best_set->set)[i]])->pth), &ret);
	clear_slct_pth(ctab, ptab, best_set, p);
	return (ret);
}
