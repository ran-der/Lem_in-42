/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvt_txt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 17:47:50 by rvan-der          #+#    #+#             */
/*   Updated: 2016/11/07 17:26:31 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*cvt_txt(t_conv c, va_list args)
{
	char	ch;
	char	*ret;

	if (c.type == s)
	{
		ret = va_arg(args, char*);
		return (ret == NULL ? ft_strdup("(null)") : ft_strdup(ret));
	}
	if ((ret = (char*)malloc(sizeof(char) * 2)) == NULL)
		return (NULL);
	ch = (char)va_arg(args, int);
	ret[0] = ch;
	ret[1] = '\0';
	return (ret);
}
