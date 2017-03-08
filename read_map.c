/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 18:54:32 by rvan-der          #+#    #+#             */
/*   Updated: 2017/03/08 16:23:19 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				ant_nb(t_map *map)
{
	char		*buf;
	int			i;
	int			ret;

	if (!get_next_line(0, &buf))
		return (-1);
	map->output = ft_dstrjoin(map->output, "\n");
	map->output = ft_dstrjoin(map->output, buf);
	i = 0;
	while (ft_isdigit(buf[i]))
		i++;
	if (buf[i] != '\0')
		return (-1);
	ret = ft_atoi(buf);
	free(buf);
	return (ret);
}

t_map			*read_map(void)
{
	t_map		*ret;
	char		*buf;
	int			ofs;
	int			cmd;

	if ((ret = (t_map*)malloc(sizeof(t_map))) == NULL)
		return (NULL);
	ret->output = NULL;
	ret->rooms = NULL;
	if ((ret->n = ant_nb(ret)) == -1)
		return (rd_error(&ret));
	ofs = 0;
	tmp = 0;
	while (get_next_line(&buf))
	{
		if ((cmd = check_buff(&buf, &ofs)) == -1 || \
				(cmd == 1 && (tmp == 1 || tmp == 3)) || \
				(cmd == 2 && (tmp == 2 || tmp == 3)))
			return (rd_error(&ret));
		if (cmd < 3)
			get_room(buf, &(ret->rooms), cmd);
		else if (cmd == 3)
			make_link(buf, ret->rooms);
	}
	return (ret);
}
