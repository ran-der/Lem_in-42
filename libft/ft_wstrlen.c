/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 20:38:16 by rvan-der          #+#    #+#             */
/*   Updated: 2016/11/06 23:40:24 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_wstrlen(unsigned char *wstr)
{
	int		len;
	int		i;
	int		j;

	len = 0;
	if (wstr != NULL)
	{
		i = 0;
		while (*(wstr + i) != 0)
		{
			j = 1;
			if ((*(wstr + i) & (unsigned char)192) == (unsigned char)192)
				j++;
			if ((*(wstr + i) & (unsigned char)224) == (unsigned char)224)
				j++;
			if ((*(wstr + i) & (unsigned char)240) == (unsigned char)240)
				j++;
			i += j;
			len++;
		}
	}
	return (len);
}
