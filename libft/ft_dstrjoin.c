/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dstrjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 18:41:37 by rvan-der          #+#    #+#             */
/*   Updated: 2017/03/14 17:03:14 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_dstrjoin(char **s1, char *s2)
{
	char	*old;
	int		l1;
	int		l2;

	l1 = (*s1 == NULL ? 0 : ft_strlen(*s1));
	l2 = (s2 == NULL ? 0 : ft_strlen(s2));
	if (!(l1 + l2))
		return (NULL);
	old = *s1;
	*s1 = (char*)malloc(sizeof(char) * (l1 + l2 + 1));
	(*s1)[0] = '\0';
	if (l1)
		*s1 = ft_strcpy(*s1, (const char*)old);
	if (l2)
		*s1 = ft_strcat(*s1, (const char*)s2);
	ft_strdel(&old);
	return (*s1);
}
