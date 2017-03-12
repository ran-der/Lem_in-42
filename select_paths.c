/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_paths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 17:55:10 by rvan-der          #+#    #+#             */
/*   Updated: 2017/03/12 22:35:01 by rvan-der         ###   ########.fr       */
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
	int			ctab[p][p];
	t_path		*ptab[p];
	int			*best_set;
	t_path		*ret;
	int			i;

	set_ptab((t_path**)ptab, paths);
	fill_ctab((int**)ctab, (t_path**)ptab, p);
	best_set = select_best_set((int**)ctab, (t_path**)ptab, p);
	elim_paths(best_set, (t_path**)ptab, map);
	ret = NULL;
	i = -1;
	while (best_set[++i] != -1)
		if (best_set[i] != -2)
			path_add(new_path((ptab[best_set[i]])->pth), &ret);
	i = -1;
	while (++i < p)
	{
		free((ptab[i])->pth);
		free(ptab[i]);
	}
	free(best_set);
	return (ret);
}
