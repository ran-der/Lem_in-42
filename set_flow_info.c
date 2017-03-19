/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_flow_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 22:43:25 by rvan-der          #+#    #+#             */
/*   Updated: 2017/03/19 22:43:37 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				plist_sum(t_path *plist)
{
	int			ret;
	t_path		*tmp;

	tmp = plist;
	ret = 0;
	while (tmp != NULL)
	{
		ret += (tmp->len - 2);
		tmp = tmp->next;
	}
	return (ret);
}

void			set_flow_info(t_map *map, t_path *plist)
{
	int			turns;
	int			sum;
	int			len;
	t_path		*tmp;

	((map->rooms)[0])->ant = map->n;
	sum = plist_sum(plist);
	len = plist_len(plist);
	turns = (sum + map->n) / len + ((sum + map->n) % len ? 1 : 0);
	tmp = plist;
	while (tmp != NULL)
	{
		tmp->pass = turns - (tmp->len - 2);
		tmp = tmp->next;
	}
}
