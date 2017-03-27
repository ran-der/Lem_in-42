/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 20:51:13 by rvan-der          #+#    #+#             */
/*   Updated: 2017/03/27 21:46:27 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

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

t_set			*init_set(int p)
{
	t_set		*new;
	int			i;

	if ((new = (t_set*)malloc(sizeof(t_set))) == NULL)
		return (NULL);
	if ((new->set = (int*)malloc(sizeof(int) * (p + 1))) == NULL)
	{
		free(new);
		return (NULL);
	}
	if ((new->turns = (int*)malloc(sizeof(int) * (p + 1))) == NULL)
	{
		free(new->set);
		free(new);
		return (NULL);
	}
	new->next = NULL;
	new->prev = NULL;
	i = -1;
	while (++i <= p)
	{
		(new->set)[i] = -1;
		(new->turns)[i] = -1;
	}
	return (new);
}
