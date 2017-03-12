/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 20:51:13 by rvan-der          #+#    #+#             */
/*   Updated: 2017/03/12 22:34:57 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			take_set(char *ret, int *line, int p)
{
	int			i;
	int			j;

	i = -1;
	j = 0;
	while (++i < p)
	{
		if (line[i] > 0)
		{
			ret[j] = i;
			j++;
		}
	}
	ret[j] = -1;
}

int				*select_best_set(int **ctab, t_path **ptab, int p)
{
	int			ret[p];
	int			sum;
	int			nb;
	int			tmp;
	int			i;

	nb = path_nb(ctab[0], p);
	sum = paths_sum(ctab[0], ptab, 0, p);
	take_set((char*)ret, ctab[0], p);
	i = 0;
	while (++i < p)
	{
		if ((tmp = path_nb(ctab[i], p)) > nb)
		{
			nb = tmp;
			sum = paths_sum(ctab[i], ptab, i, p);
			take_set((char*)ret, ctab[i], p);
		}
		else if (tmp == nb && (tmp = paths_sum(ctab[i], ptab, i, p)) < sum)
		{
			sum = tmp;
			take_set((char*)ret, ctab[i], p);
		}
	}
	return (pathdup(ret, nb + 1));
}

int				is_sorted_set(int *set, t_path **ptab)
{
	int			i;

	i = 0;
	while (set[i] != -1 && set[i + 1] != -1)
	{
		if ((ptab[set[i]])->len > (ptab[set[i + 1]])->len)
			return (0);
		i++;
	}
	return (1);
}

void			sort_set(int *set, t_path **ptab)
{
	int			tmp;
	int			i;

	while (!is_sorted_set(set, ptab))
	{
		i = 0;
		while (set[i] != -1 && set[i + 1] != -1)
		{
			if ((ptab[set[i]])->len > (ptab[set[i + 1]])->len)
			{
				tmp = set[i];
				set[i] = set[i + 1];
				set[i + 1] = tmp;
			}
			i++;
		}
	}
}
