/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 14:36:09 by rvan-der          #+#    #+#             */
/*   Updated: 2017/03/12 22:34:48 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				pathlen(int *path)
{
	int			ret;

	ret = 0;
	while (path[ret] >= 0)
		ret++;
	return (ret);
}

int				*pathdup(int *path, int len)
{
	int			i;
	int			*ret;

	if ((ret = (int*)malloc(sizeof(int) * len)) == NULL)
		return (NULL);
	i = -1;
	while (++i < len)
		ret[i] = path[i];
	return (ret);
}

t_path			*new_path(int *path)
{
	t_path		*new;

	if ((new = (t_path*)malloc(sizeof(t_path))) == NULL)
		return (NULL);
	new->len = pathlen(path);
	if ((new->pth = pathdup(path, new->len + 1)) == NULL)
	{
		free(new);
		return (NULL);
	}
	new->next = NULL;
	return (new);
}

void			path_add(t_path *elem, t_path **list)
{
	if (elem != NULL)
	{
		if (list != NULL)
			elem->next = *list;
		*list = elem;
	}
}

int				plist_len(t_path *list)
{
	int			i;
	t_path		*tmp;

	i = 0;
	if ((tmp = list) == NULL)
		return (i);
	while (tmp != NULL)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
