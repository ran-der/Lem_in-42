/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 13:21:14 by rvan-der          #+#    #+#             */
/*   Updated: 2017/03/19 22:41:16 by rvan-der         ###   ########.fr       */
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

	if (!elem)
		return ;
	if (!(tmp = *rooms))
		*rooms = elem;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		if (tmp->end)
		{
			(tmp->prev)->next = elem;
			elem->prev = tmp->prev;
			tmp->prev = elem;
			elem->next = tmp;
		}
		else
		{
			elem->prev = tmp;
			tmp->next = elem;
		}
	}
}

int				room_id(t_room **rooms, int r, char *nm)
{
	int			ret;

	ret = -1;
	while (++ret < r && rooms[ret] != NULL)
		if (!ft_strcmp((rooms[ret])->name, nm))
			return (ret);
	return (-1);
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
