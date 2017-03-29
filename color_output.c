/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 17:48:47 by rvan-der          #+#    #+#             */
/*   Updated: 2017/03/29 22:56:48 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			color_cmd(char *str)
{
	ft_putstr(CYA);
	ft_putstr(str);
	ft_putstr(NRM);
}

void			color_link(char *str)
{
	int			i;

	i = 0;
	while (str[i] != '\0' && str[i] != '-')
		i++;
	ft_putstr(MAG);
	write(1, str, i);
	ft_putstr(NRM);
	write(1, "-", 1);
	ft_putstr(MAG);
	write(1, str + i + 1, ft_strlen(str) - i - 1);
	ft_putstr(NRM);
}

void			color_room(char *str)
{
	int			i;

	i = 0;
	while (str[i] != '\0' && str[i] != ' ')
		i++;
	ft_putstr(YEL);
	write(1, str, i);
	ft_putstr(NRM);
	write(1, str + i, ft_strlen(str) - i);
}

void			color_output(char *str)
{
	char		**ltab;
	int			i;

	ltab = ft_strsplit(str, '\n');
	if (!ltab)
		return ;
	ft_putstr(RED);
	ft_putendl(ltab[0]);
	ft_putstr(NRM);
	i = 0;
	while (ltab[++i] != NULL)
	{
		if (ltab[i][0] == '#')
			color_cmd((char*)(ltab[i]));
		else if (ft_strchr((const char*)(ltab[i]), '-') != NULL)
			color_link((char*)(ltab[i]));
		else
			color_room((char*)(ltab[i]));
		write(1, "\n", 1);
		free(ltab[i]);
	}
	write(1, "\n", 1);
	free(ltab);
}
