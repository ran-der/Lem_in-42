/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_lem_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 18:30:47 by rvan-der          #+#    #+#             */
/*   Updated: 2017/03/14 22:11:03 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			get_line_stdin(char **line)
{
	char	buf[2];
	int		i;
	int		rd;
	char	ret[200];

	buf[1] = '\0';
	i = 0;
	while ((rd = read(0, buf, 1)) && buf[0] != '\n')
	{
		ret[i] = buf[0];
		i++;
	}
	ret[i] = '\0';
	*line = ft_strdup((const char*)ret);
	return (rd > 0 ? 1 : 0);
}

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

void		print_rlist(t_room *rlist)
{
	t_room		*tmp;

	printf("\nrlist :\n");
	if ((tmp = rlist) == NULL)
		printf("NULL\n");
	while (tmp != NULL)
	{
		printf("%s\n", tmp->name);
		tmp = tmp->next;
	}
}

void		print_rtab(t_room **rtab, int size)
{
	int			i;

	printf("\nrtab (size %d) :\n", size);
	i = -1;
	while (++i <size)
	{
		if (rtab[i] == NULL)
			printf("NULL\n");
		else
			printf("id%3d : %s\n", (rtab[i])->id, (rtab[i])->name);
	}
}

int			main(void)
{
	t_map		*map;
	t_path		*paths;
	char		*buf;

	if ((map = read_map()) == NULL)
	{
		printf("map NULL\n");
		return (0);
	}
//	write(1, "1\n", 2);
//		return (main_error(NULL, NULL));
	if ((paths = find_paths(map)) == NULL)
	{
		printf("paths NULL\n");
		return (0);
	}
//	write(1, "2\n", 2);
//		return (main_error(map, NULL));
	paths = select_paths(*map, paths, plist_len(paths));
//	write(1, "3\n", 2);
	printf("output:\n%s$", map->output);
//	write(1, "4\n", 2);
	print_paths(paths, map->rooms);
//	write(1, "5\n", 2);
//	set_flow_info(map, paths);
	return (0);
}
