/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dstrjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 18:41:37 by rvan-der          #+#    #+#             */
/*   Updated: 2017/03/09 19:22:29 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_dstrjoin(char *s1, char *s2)
{
	char	*new;

	if (s1 == NULL)
		return (s2);
	if (s2 == NULL)
		return (s1);
	if ((new = (char*)malloc(sizeof(char) * \
					(ft_strlen(s1) + ft_strlen(s2) + 1))) == NULL)
		return (NULL);
	new = ft_strcpy(new, (const char*)s1);
	new = ft_strcat(new, (const char*)s2);
	ft_strdel(&s1);
	return (new);
}
