/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 13:21:14 by rvan-der          #+#    #+#             */
/*   Updated: 2017/03/11 15:20:47 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room			*new_room(char *nm, int cmd)
{
	t_room		*ret;

	if (!(ret = (t_room*)malloc(sizeof(t_room))))
		return (NULL);
	ret->mark = 0;
	ret->start = (cmd == 1 ? 1 : 0);
	ret->end = (cmd == 2 ? 1 : 0);
	ret->ant = 0;
	ft_strcpy((char*)(ret->name), nm);
	ret->next = NULL;
	ret->prev = NULL;
	return (ret);
}

void			room_add(t_room **rooms, t_room *elem)
{
	t_room		*tmp;

	if (!elem)
		return ;
	if (!(*rooms))
		*rooms = elem;
	else if ((*rooms)->start)
	{
		tmp = ((*rooms)->next)->prev;
		tmp->prev = elem;
		elem->next = tmp;
		elem->prev = *rooms;
		(*rooms)->next = elem;
	}
	else
	{
		(*rooms)->prev = elem;
		elem->next = *rooms;
		*rooms = elem;
	}
}

void			room_pushback(t_room **rooms, t_room *elem)
{
	t_room		*tmp;
	t_room		*tmp2;
	
	if (!elem)
		return ;
	if (!(tmp = *rooms))
		tmp = elem;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		if (tmp->end)
		{
			if ((tmp2 = tmp->prev) != NULL)
				tmp2->next = elem;
			elem->next = tmp;
			elem->prev = tmp2;
		}
		else
		{
			elem->prev = tmp;
			tmp->next = elem;
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

int				rlist_len(t_room *list)
{
	int			i;
	t_room		*tmp;

	tmp = list;
	i = 0;
	while (tmp != NULL)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
