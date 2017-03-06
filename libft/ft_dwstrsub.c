/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dwstrsub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 17:37:34 by rvan-der          #+#    #+#             */
/*   Updated: 2016/11/06 18:01:04 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		find_start_byte(unsigned char *wstr, size_t start)
{
	size_t		ch;
	size_t		bytes;
	size_t		i;

	ch = 0;
	bytes = 0;
	while (ch < start)
	{
		i = 1;
		if ((*(wstr + bytes) & (unsigned char)192) == (unsigned char)192)
			i++;
		if ((*(wstr + bytes) & (unsigned char)224) == (unsigned char)224)
			i++;
		if ((*(wstr + bytes) & (unsigned char)240) == (unsigned char)240)
			i++;
		bytes += i;
		ch++;
	}
	return (bytes);
}

static int		get_byte_qtt(unsigned char *wstr, size_t start, size_t len)
{
	size_t		bytes;
	size_t		k;
	size_t		chars;
	size_t		i;

	chars = 0;
	bytes = 0;
	k = find_start_byte(wstr, start);
	while (chars < len)
	{
		i = 1;
		if ((*(wstr + k + bytes) & (unsigned char)192) == (unsigned char)192)
			i++;
		if ((*(wstr + k + bytes) & (unsigned char)224) == (unsigned char)224)
			i++;
		if ((*(wstr + k + bytes) & (unsigned char)240) == (unsigned char)240)
			i++;
		bytes += i;
		chars++;
	}
	return (bytes);
}

void			*ft_dwstrsub(unsigned char *wstr, size_t start, size_t len)
{
	void		*sub;
	size_t		n;

	sub = NULL;
	if (len > 0)
	{
		n = get_byte_qtt(wstr, start, len);
		if ((sub = (char*)malloc(sizeof(char) * n + 1)) == NULL)
			return (NULL);
		sub = ft_memcpy(sub, (void*)(wstr + start), n);
		*((char*)sub + n) = '\0';
	}
	else
	{
		if ((sub = (char*)malloc(sizeof(char))) == NULL)
			return (NULL);
		*((char*)sub) = '\0';
	}
	ft_memdel((void**)&wstr);
	return (sub);
}
