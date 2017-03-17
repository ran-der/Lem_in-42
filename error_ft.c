/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_ft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 13:26:58 by rvan-der          #+#    #+#             */
/*   Updated: 2017/03/10 22:23:10 by rvan-der         ###   ########.fr       */
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
	ft_printf("ERROR\n");
	return (0);
}
