/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 17:54:38 by rvan-der          #+#    #+#             */
/*   Updated: 2016/11/05 17:54:47 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_realloc(void *ptr, size_t src_size, size_t dst_size)
{
	void	*new;

	if ((new = malloc(dst_size)) == NULL)
		return (NULL);
	new = ft_memcpy(new, ptr, src_size);
	ft_memdel(&ptr);
	return (new);
}
