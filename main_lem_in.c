/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_lem_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 18:30:47 by rvan-der          #+#    #+#             */
/*   Updated: 2017/03/29 22:46:37 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		print_path(int *path, t_room **rooms, int nb, int color)
{
	int		i;
	int		start;

	start = 1;
	ft_putnbr(nb);
	ft_putstr(") ");
	i = 0;
	while (path[i] != -1)
	{
		if (!start)
			ft_putstr(" - ");
		if (color)
			ft_putstr(YEL);
		ft_putstr((rooms[path[i]])->name);
		if (color)
			ft_putstr(NRM);
		start = 0;
		i++;
	}
	write(1, "\n", 1);
}

void		print_paths(t_path *paths, t_map *map, int color)
{
	t_path		*tmp;
	int			i;

	ft_putstr("Used paths:\n\n");
	tmp = paths;
	i = 0;
	while (tmp != NULL)
	{
		print_path(tmp->pth, map->rooms, i, color);
		write(1, "\n", 1);
		tmp = tmp->next;
		i++;
	}
}

int			main(int argc, char **argv)
{
	t_map		*map;
	t_path		*paths;
	t_opt		*options;

	if ((options = check_args(argc, argv)) == NULL || options->fd == -1)
		return (lem_in_usage(&options));
	if ((map = read_map(options->fd)) == NULL)
		return (input_error(&options));
	if (options->fd)
		close(options->fd);
	if ((paths = find_paths(map)) == NULL)
		return (path_error(&map, &options));
	paths = select_paths(*map, paths, plist_len(paths));
	set_flow_info(map, paths);
	if (options->color)
		color_output(map->output);
	else
		ft_printf("%s\n\n", map->output);
	if (options->path)
		print_paths(paths, map, options->color);
	play(map, paths, options->color);
	free(options);
	delete_plist(&paths);
	delete_map(&map);
	return (0);
}
