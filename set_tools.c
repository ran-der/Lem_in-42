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
void			print_set(int *set);

int				*take_set(int **old, int *line, int lid, int p)
{
	int			i;
	int			j;
	int			*new;

	new = (int*)malloc(sizeof(int) * p);
	i = -1;
	new[0] = lid;
	j = 1;
	while (++i < p)
	{
		if (line[i] > 0)
		{
			new[j] = i;
			j++;
		}
	}
	new[j] = -1;
	if (old != NULL)
		free(*old);
	return (new);
}

int				*select_best_set(int **ctab, t_path **ptab, int p)
{
	int			*ret;
	int			sum;
	int			nb;
	int			tmp;
	int			i;

	nb = path_nb(ctab[0], p);
	sum = paths_sum(ctab[0], ptab, 0, p);
	ret = take_set(NULL, ctab[0], 0, p);
	print_set(ret);
	i = 0;
	while (++i < p)
	{
		if ((tmp = path_nb(ctab[i], p)) > nb)
		{
			nb = tmp;
			sum = paths_sum(ctab[i], ptab, i, p);
			ret = take_set(&ret, ctab[i], i, p);
		}
		else if (tmp == nb && (tmp = paths_sum(ctab[i], ptab, i, p)) < sum)
		{
			sum = tmp;
			ret = take_set(&ret, ctab[i], i, p);
		}
	}
	return (ret);
}

int				is_sorted_set(int *set, t_path **ptab)
{
	int			i;

	write(1, "is_sorted\n", 10);
	i = 0;
	while (set[i] != -1 && set[i + 1] != -1)
	{
		write(1, "S->", 3);
		if (write(1, "he", 2) && (ptab[set[i]])->len > (ptab[set[i + 1]])->len)
		{
			write(1, "+ ", 2);
			return (0);
		}
		i++;
		write(1, "- ", 2);
	}
	write(1, "end\n", 4);
	return (1);
}

void			sort_set(int *set, t_path **ptab)
{
	int			tmp;
	int			i;

	write(1, "sort_set\n", 9);
	while (!is_sorted_set(set, ptab))
	{
		write(1, "A\n", 2);
		i = 0;
		while (set[i] != -1 && set[i + 1] != -1)
		{
			write(1, "B->", 3);
			if ((ptab[set[i]])->len > (ptab[set[i + 1]])->len)
			{
				write(1, "+ ", 2);
				tmp = set[i];
				set[i] = set[i + 1];
				set[i + 1] = tmp;
			}
			write(1, "- ", 2);
			i++;
		}
		write(1, "\n", 1);
	}
	write(1, "end\n", 4);
}
