/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_paths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 17:55:10 by rvan-der          #+#    #+#             */
/*   Updated: 2017/03/24 23:45:37 by rvan-der         ###   ########.fr       */
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

void			elim_paths(int *set, t_path **ptab, t_map map)
{
	int			pnb;
	int			wsum;
	int			turns;
	int			tmp;

	sort_set(set, ptab);
	wsum = 0;
	pnb = -1;
	while (set[++pnb] != -1)
		wsum += ((ptab[set[pnb]])->len - 2);
	turns = (wsum + map.n) / pnb + ((wsum + map.n) % pnb ? 1 : 0);
	while (--pnb > 0)
	{
		wsum -= ((ptab[set[pnb]])->len - 2);
		tmp = (wsum + map.n) / pnb + ((wsum + map.n) % pnb ? 1 : 0);
		if (tmp < turns)
		{
			set[pnb] = -1;
			turns = tmp;
		}
		else
			break ;
	}
}

t_path			*select_paths(t_map map, t_path *paths, int p)
{
	int			**ctab;
	t_path		**ptab;
	int			*best_set;
	t_path		*ret;
	int			i;

	ptab = make_ptab(paths, p);
	ctab = init_ctab(p);
	fill_ctab(ctab, ptab, p);
	best_set = select_best_set(ctab, p);
	elim_paths(best_set, (t_path**)ptab, map);
	ret = NULL;
	i = -1;
	while (best_set[++i] != -1)
		if (best_set[i] != -2)
			path_add(new_path((ptab[best_set[i]])->pth), &ret);
	clear_slct_pth(ctab, ptab, best_set, p);
	return (ret);
}
