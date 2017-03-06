/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_room.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 21:10:21 by rvan-der          #+#    #+#             */
/*   Updated: 2017/03/06 21:56:05 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		get_room(char *buf, t_room **rms, int chk)
{
	int			i;
	char		name[25];
	t_room		*new;
	int			lst;

	i = -1;
	while (buf[++i] && buf[i] != ' ')
		name[i] = buf[i];
	name[i] = '\0';
	if ((lst = is_inlist(name, *rms)))
	{
		name[i] = 32 + lst;
		name[i + 1] = '\0';
	}
	if ((new = new_room(name, chk)) != NULL)
	{
		if (chk == 1)
			room_add(rms, new);
		else
			room_pushback(rms, new);
	}
}
