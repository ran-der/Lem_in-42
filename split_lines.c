/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 14:41:22 by rvan-der          #+#    #+#             */
/*   Updated: 2017/04/08 15:10:17 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				count_lines(char *str)
{
	int			ret;
	int			i;

	if (!str)
		return (0);
	ret = 1;
	i = -1;
	while (str[++i] != '\0')
		if (str[i] == '\n' && !(i > 0 && str[i - 1] == '\n'))
			ret++;
	return (ret);
}

char			**split_lines(char *str)
{
	char		*tmp;
	char		**ret;
	int			i;
	int			current;
	int			j;

	if ((tmp = str) == NULL)
		return (NULL);
	while (*tmp == '\n')
		tmp++;
	if ((ret = (char**)malloc(sizeof(char*) * (count_lines(tmp) + 1))) == NULL)
		return (NULL);
	current = 0;
	j = 0;
	i = -1;
	while (tmp[++i] != '\0')
		if (tmp[i] == '\n' && !(tmp[i] = '\0'))
		{
			ret[j++] = tmp + current;
			current = i + 1;
		}
	ret[j++] = tmp + current;
	ret[j] = NULL;
	return (ret);
}
