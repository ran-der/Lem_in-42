/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvt_wtxt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 19:03:00 by rvan-der          #+#    #+#             */
/*   Updated: 2016/11/10 17:52:11 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			cvt_byte(unsigned int wchar, int range, int pos)
{
	char			ret;
	unsigned char	flags[4];
	int				shift;

	flags[0] = 0;
	flags[1] = 192;
	flags[2] = 224;
	flags[3] = 240;
	shift = 6 * (range - pos - 1);
	if (pos == 0)
		ret = flags[range - 1] + (wchar >> (6 * (range - 1)));
	else
		ret = 128 + ((wchar >> (shift > 0 ? shift : 0)) & 0x0000003F);
	return (ret);
}

char			*wstr_to_utf8(unsigned int wchar)
{
	char			*ret;
	int				range;
	int				i;

	range = (wchar > 127 ? 2 : 1);
	range = (wchar > 2047 ? 3 : range);
	range = (wchar > 65535 ? 4 : range);
	if ((ret = (char*)malloc(sizeof(char) * range + 1)) == NULL)
		return (NULL);
	i = -1;
	while (++i < range)
		ret[i] = cvt_byte(wchar, range, i);
	ret[range] = '\0';
	return (ret);
}

char			*rewrite(t_conv c, wchar_t *wstr)
{
	char			*utf_ch;
	char			*ret;
	int				i;

	if (wstr == NULL)
		return (NULL);
	i = -1;
	utf_ch = NULL;
	ret = NULL;
	while (wstr[++i])
	{
		if ((utf_ch = wstr_to_utf8(*((unsigned int*)wstr + i))) == NULL)
			return (NULL);
		if ((ret = ft_dstrjoin(ret, utf_ch)) == NULL)
			return (NULL);
	}
	if (c.prec > -1 && ft_wstrlen((unsigned char*)ret) > c.prec)
		ret = (char*)ft_dwstrsub((unsigned char*)ret, 0, (size_t)c.prec);
	return (ret);
}

char			*cvt_wtxt(t_conv c, va_list args)
{
	wchar_t			wch[2];
	wchar_t			*tmp;
	char			*ret;

	if (c.type == s || c.type == S)
	{
		tmp = va_arg(args, wchar_t*);
		return (tmp == NULL ? ft_strdup("(null)") : rewrite(c, tmp));
	}
	wch[0] = va_arg(args, wchar_t);
	wch[1] = '\0';
	if (*wch == '\0')
	{
		if ((ret = (char*)malloc(sizeof(char))) == NULL)
			return (NULL);
		*ret = '\0';
		return (ret);
	}
	return (rewrite(c, wch));
}
