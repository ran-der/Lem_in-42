/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_ft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 17:51:40 by rvan-der          #+#    #+#             */
/*   Updated: 2017/03/10 22:23:13 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		delete_itab(int **tab, int size)
{
	int			i;

	if (tab != NULL)
	{
		i = -1;
		while (++i < size)
			free(tab[i]);
		free(tab);
	}
}

void		delete_roomlst(t_room **list)
{
	t_room		*tmp;
	t_room		*prv;

	if ((tmp = *list) != NULL)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		while (tmp != NULL)
		{
			prv = tmp->prev
			ft_memdel((void**)(&tmp));
			tmp = prv;
		}
		*list = NULL;
	}
}

void		delete_map(t_map **map)
{
	if (*map != NULL)
	{
		if ((*map)->rooms != NULL)
			delete_roomslst(((*map)->rooms)[0]);
		ft_memdel((void**)(&((*map)->rooms)));
		delete_itab(map->links, map->r);
		ft_memdel((void**)(&((*map)->paths)));
		ft_memdel((void**)(&((*map)->output)));
		*map = NULL;
	}
}
