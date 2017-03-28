/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_lem_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 18:30:47 by rvan-der          #+#    #+#             */
/*   Updated: 2017/03/27 23:09:17 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		print_path(int *path, t_room **rooms, int nb)
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
		ft_putstr((rooms[path[i]])->name);
		start = 0;
		i++;
	}
	write(1, "\n", 1);
}

void		print_paths(t_path *paths, t_map *map)
{
	t_path		*tmp;
	int			i;

	ft_putstr("Used paths:\n\n");
	tmp = paths;
	i = 0;
	while (tmp != NULL)
	{
		print_path(tmp->pth, map->rooms, i);
		write(1, "\n", 1);
		tmp = tmp->next;
		i++;
	}
}

t_opt		*init_opt(void)
{
	t_opt		*ret;
	
	if ((ret = (t_opt*)malloc(sizeof(t_opt))) == NULL)
		return (NULL);
	ret->fd = 0;
	ret->path = 0;
	ret->color = 0;
	return (ret);
}

t_opt		*check_args(int argc, char **argv)
{
	int			i;
	t_opt		*ret;
	
	i = -1;
	if ((ret = init_opt()) == NULL)
		return (NULL);
	while (++i < argc)
	{
		if (ft_streq
	if (argc > 2 || (argc == 2 && ft_strcmp(argv[1], "-p")))

int			main(int argc, char **argv)
{
	t_map		*map;
	t_path		*paths;
	t_opt		*options;

	if ((options = check_args(argc, argv)) == NULL)
		return (lem_in_usage());
	if ((map = read_map()) == NULL)
		return (input_error(&options));
	if ((paths = find_paths(map)) == NULL)
		return (path_error(&map, &options));
	paths = select_paths(*map, paths, plist_len(paths));
	set_flow_info(map, paths);
	ft_printf("%s\n\n", map->output);
	if (argc == 2)
		print_paths(paths, map);
	play(map, paths);
	delete_plist(&paths);
	delete_map(&map);
	return (0);
}
