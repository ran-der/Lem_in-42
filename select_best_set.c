/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_best_set.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 21:13:42 by rvan-der          #+#    #+#             */
/*   Updated: 2017/03/27 21:47:15 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			take_set(int *set, int *line, int p)
{
	int			i;
	int			j;

	i = -1;
	j = 0;
	while (++i < p)
	{
		if (line[i] > -1)
		{
			set[j] = i;
			j++;
		}
	}
}

void			calc_turns(t_set *new, t_path **ptab, int n)
{
	int			i;
	int			sum;

	sum = 0;
	i = -1;
	while ((new->set)[++i] > -1)
	{
		sum += (ptab[(new->set)[i]])->len - 2;
		(new->turns)[i] = sum;
	}
	while (--i > -1)
	{
		sum = (new->turns)[i] + n;
		(new->turns)[i] = sum / (i + 1) + (sum % (i + 1) ? 1 : 0);
	}
	new->tmin = (new->turns)[++i];
	new->pnb = 1;
	while ((new->turns)[++i] > -1)
	{
		if ((new->turns)[i] < new->tmin)
		{
			new->pnb = i + 1;
			new->tmin = (new->turns)[i];
		}
	}
}

t_set			*new_set(int *line, t_path **ptab, int p, int n)
{
	t_set		*new;

	if ((new = init_set(p)) == NULL)
		return (0);
	take_set(new->set, line, p);
	sort_set(new->set, ptab);
	calc_turns(new, ptab, n);
	return (new);
}

t_set			*make_sets(int **ctab, t_path **ptab, int p, int n)
{
	int			i;
	t_set		*ret;
	t_set		*new;

	ret = NULL;
	i = -1;
	while (++i < p)
	{
		if (!(new = new_set(ctab[i], ptab, p, n)))
			return (set_error(&ret));
		new->next = ret;
		if (ret != NULL)
			ret->prev = new;
		ret = new;
	}
	return (ret);
}

t_set			*select_best_set(int **ctab, t_path **ptab, int p, int n)
{
	t_set		*sets;
	t_set		*ret;
	t_set		*tmp;
	int			min;

	if ((sets = make_sets(ctab, ptab, p, n)) == NULL)
		return (NULL);
	tmp = sets->next;
	ret = sets;
	min = sets->tmin;
	while (tmp != NULL)
	{
		if (tmp->tmin < min)
		{
			ret = tmp;
			min = ret->tmin;
		}
		tmp = tmp->next;
	}
	if (ret->prev != NULL)
		(ret->prev)->next = ret->next;
	if (ret->next != NULL)
		(ret->next)->prev = ret->prev;
	delete_slist(ret == sets ? &(ret->next) : &sets);
	return (ret);
}
