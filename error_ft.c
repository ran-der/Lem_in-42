/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_ft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 13:26:58 by rvan-der          #+#    #+#             */
/*   Updated: 2017/03/28 22:38:45 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room			*room_error(t_room **rlist, char **buf)
{
	ft_memdel((void**)buf);
	delete_roomlst(rlist);
	return (NULL);
}

t_map			*rd_error(t_map **map)
{
	delete_map(map);
	return (NULL);
}

int				input_error(t_opt **opt)
{
	if (*opt)
	{
		if ((*opt)->fd)
			close((*opt)->fd);
		free(*opt);
	}
	if (map != NULL)
		delete_map(map);
	write(1, "INPUT ERROR\n", 12);
	return (0);
}

int				path_error(t_map **map, t_opt **opt)
{
	if (*opt)
		free(*opt);
	if (map != NULL)
		delete_map(map);
	write(1, "NO PATH\n", 8);
	return (0);
}

int				lem_in_usage(void)
{
	ft_putendl("ERROR");
	ft_putendl("Usage: display input on stdin | ./lem-in [-p]");
	return (0);
}
