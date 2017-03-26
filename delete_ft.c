/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_ft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 17:51:40 by rvan-der          #+#    #+#             */
/*   Updated: 2017/03/26 22:59:12 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		delete_plist(t_path **plist)
{
	t_path		*tmp;

	if (plist == NULL || (tmp = *plist) == NULL)
		return ;
	while (tmp != NULL)
	{
		*plist = tmp->next;
		ft_memdel((void**)(&(tmp->pth)));
		ft_memdel((void**)(&tmp));
		tmp = *plist;
	}
}

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
			prv = tmp->prev;
			ft_memdel((void**)(&tmp));
			tmp = prv;
		}
		*list = NULL;
	}
}

void		delete_slist(t_set **slist)
{
	t_set		*tmp;

	if (slist == NULL || (tmp = *slist) == NULL)
		return ;
	while (tmp != NULL)
	{
		*slist = tmp->next;
		ft_memdel((void**)(&(tmp->set)));
		ft_memdel((void**)(&(tmp->turns)));
		ft_memdel((void**)(&tmp));
		tmp = *slist;
	}
}

void		delete_map(t_map **map)
{
	if (*map != NULL)
	{
		if ((*map)->rooms != NULL)
			delete_roomlst((*map)->rooms);
		ft_memdel((void**)(&((*map)->rooms)));
		delete_itab((*map)->links, (*map)->r);
		ft_memdel((void**)(&((*map)->output)));
		free(*map);
		*map = NULL;
	}
}
