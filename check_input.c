/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 20:33:07 by rvan-der          #+#    #+#             */
/*   Updated: 2017/04/07 15:11:28 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				check_for_link(char *buf)
{
	int			i;

	if (buf[0] == '#')
		return (0);
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

int				check_for_room(char *buf)
{
	int			i;

	i = 0;
	while (buf[i] != ' ' && buf[i] != '-' && ft_isprint(buf[i]))
		i++;
	if (!i || i > 20 || buf[i] != ' ' || !(++i) || !ft_isdigit(buf[i]))
		return (0);
	while (ft_isdigit(buf[i]))
		i++;
	if (buf[i] != ' ' || !(++i) || !ft_isdigit(buf[i]))
		return (0);
	while (ft_isdigit(buf[i]))
		i++;
	return (!(buf[i]) ? 1 : 0);
}

int				check_for_cmd(char **buf, t_map *map, int ofs, int fd)
{
	int			ret;

	if (!ft_strcmp(*buf, "##start"))
		ret = 1;
	else if (!ft_strcmp(*buf, "##end"))
		ret = 2;
	else
		return (-2);
	if (ofs)
		return (-1);
	free(*buf);
	get_next_line(fd, buf);
	if (!check_for_room(*buf))
		return (-1);
	map->output = ft_dstrjoin(&(map->output), "\n");
	map->output = ft_dstrjoin(&(map->output), *buf);
	return (ret);
}

int				check_buff(char **buf, t_map *map, int ofs, int fd)
{
	if (!(*buf) || (*buf)[0] == 'L')
		return (-1);
	map->output = ft_dstrjoin(&(map->output), "\n");
	map->output = ft_dstrjoin(&(map->output), *buf);
	if ((*buf)[0] == '#')
		return (check_for_cmd(buf, map, ofs, fd));
	if (!ofs && check_for_room(*buf))
		return (0);
	if (check_for_link(*buf))
		return (3);
	return (-1);
}
