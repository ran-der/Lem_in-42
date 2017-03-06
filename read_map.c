/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 18:54:32 by rvan-der          #+#    #+#             */
/*   Updated: 2017/03/06 21:56:20 by rvan-der         ###   ########.fr       */
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
	int			chk;

	if ((ret = (t_map*)malloc(sizeof(t_map))) == NULL)
		return (NULL);
	ret->output = NULL;
	ret->rooms = NULL;
	if ((ret->n = ant_nb(ret)) == -1)
		return (rd_error(ret));
	ofs = 0;
	while (get_next_line(&buf))
	{
		if ((chk = check_buff(&buf, &ofs)) == -1)
			return (rd_error(ret));
		if (chk < 3)
			get_room(buf, &(ret->rooms), chk);
		else if (chk == 3)
			make_link(buf, ret->rooms);
	}
	return (ret);
}
