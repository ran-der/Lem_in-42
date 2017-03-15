/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_paths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 17:55:10 by rvan-der          #+#    #+#             */
/*   Updated: 2017/03/15 18:57:12 by rvan-der         ###   ########.fr       */
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

	write(1, "a\n", 2);
	i = -1;
	while (++i < p)
	{
		j = i;
		ctab[i][j] = 0;
		write(1, "b\n", 2);
		while (++j < p)
		{
			//printf("ptab[%d]->pthlen = %d\nptab[%d]->pthlen = %d\n", i, \
			//		pathlen((ptab[i])->pth), j, pathlen((ptab[j])->pth));
			ctab[i][j] = 0;
			if (!paths_cross((ptab[i])->pth, (ptab[j])->pth))
				ctab[i][j] = (ptab[j])->len - 2;
			ctab[j][i] = ctab[i][j];
		}
		write(1, "\n", 1);
	}
	write(1, "c\n", 2);
	i = -1;
	while (++i < p)
		set_line(ctab[i], ptab, p);
	write(1, "d\n", 2);
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

//	write(1, "0\n", 2);
	ptab = make_ptab(paths, p);
//	write(1, "1\n", 2);
	ctab = init_ctab(p);
	fill_ctab(ctab, ptab, p);
//	write(1, "2\n", 2);
	best_set = select_best_set((int**)ctab, (t_path**)ptab, p);
//	write(1, "3\n", 2);
	elim_paths(best_set, (t_path**)ptab, map);
//	write(1, "4\n", 2);
	ret = NULL;
	i = -1;
	while (best_set[++i] != -1)
		if (best_set[i] != -2)
			path_add(new_path((ptab[best_set[i]])->pth), &ret);
//	write(1, "5\n", 2);
	clear_slct_pth(ctab, ptab, best_set);
	return (ret);
}
