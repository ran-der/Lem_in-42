/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 20:33:07 by rvan-der          #+#    #+#             */
/*   Updated: 2017/03/13 17:06:29 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			check_for_link(char *buf)
{
	int		i;

	i = 0;
	while (buf[i] != '-' && buf[i] != ' ' && ft_isprint(buf[i]))
		i++;
	if (!i || buf[i] != '-')
		return (0);
	i++;
	if (!(buf[i]))
		return (0);
	while (buf[i] != '-' && buf[i] != ' ' && ft_isprint(buf[i]))
		i++;
	return (!(buf[i]) ? 1 : 0);
}

int			check_for_room(char *buf)
{
	int		i;

	i = 0;
	while (buf[i] != ' ' && buf[i] != '-' && ft_isprint(buf[i]))
		i++;
	if (!i || i > 20 || buf[i] != ' ' || !ft_isdigit(buf[++i]))
		return (0);
	while (ft_isdigit(buf[i]))
		i++;
	if (buf[i] != ' ' || !ft_isdigit(buf[++i]))
		return (0);
	while (ft_isdigit(buf[i]))
		i++;
	return (!(buf[i]) ? 1 : 0);
}

int				check_for_cmd(char **buf, t_map *map)
{
	int			ret;

	if ((*buf)[1] != '#')
		return (-2);
	ret = -1;
	if (!ft_strcmp((*buf) + 1, "start"))
		ret = 1;
	else if (!ft_strcmp((*buf) + 1, "end"))
		ret = 2;
	if (ret > 0)
	{
		ft_memdel((void**)buf);
		get_next_line(0, buf);
		if (!check_for_room(*buf))
			return (-1);
		map->output = ft_dstrjoin(map->output, "\n");
		map->output = ft_dstrjoin(map->output, *buf);
	}
	return (ret);
}

int				check_buff(char **buf, t_map *map, int ofs)
{
	if (!*buf || (*buf)[0] == 'L')
		return (-1);
	printf("output3 (%p): %s\n", map->output);
	map->output = ft_dstrjoin(map->output, "\n");
	printf("output4: (%p): %s\n", map->output);
	map->output = ft_dstrjoin(map->output, *buf);
	if ((*buf)[0] == '#')
		return (ofs && (*buf)[1] == '#' ? -1 : check_for_cmd(buf, map));
	if (!ofs && check_for_room(*buf))
		return (0);
	if (check_for_link(*buf))
		return (3);
	return (-1);
}
