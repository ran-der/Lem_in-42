/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_ft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 13:26:58 by rvan-der          #+#    #+#             */
/*   Updated: 2017/03/19 23:01:06 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_map			*rd_error(t_map **map)
{
	delete_map(map);
	return (NULL);
}

int				main_error(t_map **map)
{
	if (map != NULL)
		delete_map(map);
	write(1, "ERROR\n", 6);
	return (0);
}
