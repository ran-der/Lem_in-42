/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 19:29:37 by rvan-der          #+#    #+#             */
/*   Updated: 2016/11/06 17:44:12 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcat(void *dst, void *src, size_t start, size_t len)
{
	size_t		i;

	if (dst == NULL || src == NULL)
		return (dst);
	i = 0;
	while (i < len)
		*((char*)(dst + start + i)) = *((char*)(src + i));
	return (dst);
}
