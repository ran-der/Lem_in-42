/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_conv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 14:59:26 by rvan-der          #+#    #+#             */
/*   Updated: 2016/11/10 19:06:50 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*add_space(t_conv c, char *res, int len)
{
	char		*new;
	int			i;

	if ((new = (char*)malloc(sizeof(char) * c.field + 1)) == NULL)
		return (NULL);
	i = -1;
	if (c.min)
	{
		while (++i < len)
			new[i] = res[i];
		while (i < c.field)
			new[i++] = ' ';
	}
	else
	{
		while (++i < c.field - len)
			new[i] = ' ';
		i -= 1;
		while (++i <= c.field)
			new[i] = res[i - c.field + len];
	}
	new[i] = '\0';
	free(res);
	return (new);
}

char			*ft_padding(t_conv c, char *res, int len)
{
	int			pfx;

	if (c.zero && !c.min && !(c.prec >= 0 && ft_check_tp(c.mod, c.type) > 1 &&\
		c.type != pct))
	{
		pfx = get_pfxlen(res, c);
		return (ft_chgprec(res, len, c.field - pfx, pfx));
	}
	return (add_space(c, res, len));
}

char			*cvt_pct(void)
{
	char		*ret;

	if ((ret = (char*)malloc(sizeof(char) * 2)) == NULL)
		return (NULL);
	ret[0] = '%';
	ret[1] = '\0';
	return (ret);
}

char			*ft_write_conv(t_conv c, t_arg *arg)
{
	char		*res;
	int			len;
	int			nul_ch;

	nul_ch = 0;
	if ((res = (c.type == pct ? cvt_pct() : \
		((arg->ctab)[c.mod][c.type])(c, arg->args))) == NULL)
		return (NULL);
	if ((c.type == ch || c.type == C) && !(*res))
		nul_ch = ++(arg->nul);
	len = ft_wstrlen((unsigned char*)res);
	if ((c.type == s && c.mod != l && c.mod != ll) && c.prec > -1 &&\
			len > c.prec)
		if ((res = ft_dstrsub(res, 0, c.prec)) == NULL)
			return (NULL);
	len = ft_wstrlen((unsigned char*)res);
	if (c.field > len + (nul_ch > 0 ? 1 : 0))
		res = ft_padding(c, res, len);
	return (res);
}
