/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_lem_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 18:30:47 by rvan-der          #+#    #+#             */
/*   Updated: 2017/03/13 17:06:41 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		print_paths(t_path *paths, t_room **rooms)
{
	t_path		*tmp;
	int			i;
	int			j;

	if ((tmp = paths) != NULL)
	{
		i = 0;
		while (tmp != NULL)
		{
			j = -1;
			printf("p%d (len = %d): ", i, tmp->len);
			i++;
			while ((tmp->pth)[++j] != -1)
			{
				printf("%s", (rooms[(tmp->pth)[j]])->name);
				if ((tmp->pth)[j + 1] != -1)
					printf(" - ");
			}
			printf("\n");
			tmp = tmp->next;
		}
	}
}

int			main(void)
{
	t_map		*map;
	t_path		*paths;

	write(1, "0\n", 2);
	if ((map = read_map()) == NULL)
	{
		printf("map NULL\n");
		return (0);
	}
	write(1, "1\n", 2);
//		return (main_error(NULL, NULL));
	if ((paths = find_paths(map)) == NULL)
	{
		printf("paths NULL\n");
		return (0);
	}
	write(1, "2\n", 2);
//		return (main_error(map, NULL));
	paths = select_paths(*map, paths, plist_len(paths));
	write(1, "3\n", 2);
	printf("output:\n%s$", map->output);
	print_paths(paths, map->rooms);
//	set_flow_info(map, paths);
	return (0);
}
