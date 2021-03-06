/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 17:48:09 by rvan-der          #+#    #+#             */
/*   Updated: 2017/03/27 23:09:57 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_path			**make_ptab(t_path *paths, int p)
{
	t_path		**ret;
	t_path		*tmp;
	int			i;

	if ((ret = (t_path**)malloc(sizeof(t_path*) * p)) == NULL)
		return (NULL);
	if ((tmp = paths) != NULL)
	{
		i = 0;
		while (tmp != NULL)
		{
			ret[i] = tmp;
			i++;
			tmp = tmp->next;
		}
	}
	return (ret);
}

int				**init_ctab(int size)
{
	int			**ret;
	int			i;

	if ((ret = (int**)malloc(sizeof(int*) * size)) == NULL)
		return (NULL);
	i = -1;
	while (++i < size)
		*(ret + i) = (int*)malloc(sizeof(int) * size);
	return (ret);
}

void			clear_slct_pth(int **ctab, t_path **ptab, t_set *best_set, \
																	int p)
{
	int			i;

	i = -1;
	while (++i < p)
	{
		free((ptab[i])->pth);
		free(ptab[i]);
	}
	free(ptab);
	i = -1;
	while (++i < p)
		free(ctab[i]);
	free(ctab);
	free(best_set->set);
	free(best_set->turns);
	free(best_set);
}
