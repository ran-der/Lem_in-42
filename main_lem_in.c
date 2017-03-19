/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_lem_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 18:30:47 by rvan-der          #+#    #+#             */
/*   Updated: 2017/03/19 23:09:26 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			main(void)
{
	t_map		*map;
	t_path		*paths;

	if ((map = read_map()) == NULL)
		return (main_error(NULL));
	if ((paths = find_paths(map)) == NULL)
		return (main_error(&map));
	paths = select_paths(*map, paths, plist_len(paths));
	set_flow_info(map, paths);
	ft_printf("%s\n\n", map->output);
	play(map, paths);
	delete_plist(&paths);
	delete_map(&map);
	return (0);
}
