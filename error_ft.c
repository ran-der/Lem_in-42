/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_ft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 13:26:58 by rvan-der          #+#    #+#             */
/*   Updated: 2017/03/29 19:20:19 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room			*room_error(t_room **rlist, char **buf)
{
	ft_memdel((void**)buf);
	delete_roomlst(rlist);
	return (NULL);
}

t_map			*read_error(t_map **map)
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

int				lem_in_usage(t_opt **opt)
{
	if (*opt != NULL)
	{
		if ((*opt)->fd > 0)
			close((*opt)->fd);
		free(*opt);
	}
	ft_putendl("ERROR");
	ft_putendl("Usage:\n       ./lem-in [-p] [-c] [-f file]");
	ft_putendl("       -p: print used paths for ant movement");
	ft_putendl("       -c: add color to output");
	ft_putendl("       If no file specified, take input from stdin.");
	return (0);
}
