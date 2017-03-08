/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 13:21:14 by rvan-der          #+#    #+#             */
/*   Updated: 2017/03/08 16:22:28 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room			*new_room(char *nm, int cmd)
{
	t_room		*ret;

	if (!(ret = (t_room*)malloc(sizeof(t_room))))
		return (NULL);
	if (!(ret->links = (char**)malloc(sizeof(char*))))
		ft_memdel((void**)(&ret));
	if (!ret || !(*(ret->links) = (char*)malloc(sizeof(char))))
	{
		if (ret != NULL)
		{
			ft_memdel((void**)(&(ret->links)));
			ft_memdel((void**)(&ret));
		}
		return (NULL);
	}
	ft_strcpy((char*)(ret->name), nm);
	*(ret->links) = NULL;
	ret->mark = 0;
	ret->dist = -1;
	ft_bzero((void*)(ret->via), 22);
	ret->start = (cmd == 1 ? 1 : 0);
	ret->end = (cmd == 2 ? 1 : 0);
	ret->next = NULL;
	ret->prev = NULL;
	return (ret);
}

void			room_add(t_room **rooms, t_room *new)
{
	t_room		*tmp;

	if (!new)
		return ;
	if (!(*rooms))
		*rooms = new;
	else if ((*rooms)->start)
	{
		tmp = ((*rooms)->next)->prev;
		tmp->prev = new;
		new->next = tmp;
		new->prev = *rooms;
		(*rooms)->next = new;
	}
	else
	{
		(*rooms)->prev = new;
		new->next = *rooms;
		*rooms = new;
	}
}

void			room_pushback(t_room **rooms, t_room *new)
{
	t_room		*tmp;
	t_room		*tmp2;
	
	if (!new)
		return ;
	if (!(tmp = *rooms))
		tmp = new;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		if (tmp->end)
		{
			if ((tmp2 = tmp->prev) != NULL)
				tmp2->next = new;
			new->next = tmp;
			new->prev = tmp2;
		}
		else
		{
			new->prev = tmp;
			tmp->next = new;
		}
	}
}

t_room			*select_room(t_room *rooms, char *nm)
{
	t_room		*ret;

	if ((ret = rooms) == NULL)
		return (NULL);
	while (ret != NULL && ft_strcmp(ret->name, nm))
		ret = ret->next;
	return (ret);
}
