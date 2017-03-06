/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvt_unbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 17:48:46 by rvan-der          #+#    #+#             */
/*   Updated: 2016/11/10 20:16:59 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char					*get_prefix(t_conv c, uintmax_t nbr)
{
	if (((c.type == O || c.type == o) && c.altern) || (!nbr && c.prec != 0))
		return ("0");
	if ((c.altern && nbr && (c.type == x || c.type == X)) || c.type == p)
		return (c.type == X ? "0X" : "0x");
	return (NULL);
}

char					*ft_itoabase_pf(t_conv c, uintmax_t n, int range,\
										char *base)
{
	int					i;
	char				*nbr;
	char				*prefix;
	int					base_len;

	if ((nbr = (char*)malloc(sizeof(char) * (range + 1))) == NULL)
		return (NULL);
	if ((prefix = get_prefix(c, n)) != NULL)
	{
		i = -1;
		while (prefix[++i] != '\0')
			nbr[i] = prefix[i];
	}
	base_len = ft_strlen(base);
	i = range - 1;
	while (n != 0)
	{
		nbr[i--] = base[n % base_len];
		n = n / base_len;
	}
	nbr[range] = '\0';
	return (nbr);
}

int						find_range(t_conv c, uintmax_t n, int base_len)
{
	int					range;

	range = 0;
	if (c.type == p || (c.altern && (c.type == x || c.type == X) && n))
		range = 2;
	else if ((!n && c.prec != 0) ||\
				(c.altern && (c.type == o || c.type == O)))
		range = 1;
	while (n != 0)
	{
		range++;
		n = n / base_len;
	}
	return (range);
}

uintmax_t				get_nbr(t_mod m, t_type t, va_list args)
{
	t_val				nbr;

	if ((t == u || t == o || t == x || t == X) && !m)
		return ((uintmax_t)(nbr.uin = va_arg(args, unsigned)));
	if (t != p && m == h)
	{
		return ((uintmax_t)(unsigned short)(nbr.hun =\
					va_arg(args, unsigned int)));
	}
	if (((t == u || t == o || t == x || t == X) && m == l) ||\
			((t == U || t == O) && !m) || (t != p && m == z))
		return ((uintmax_t)(nbr.lun = va_arg(args, unsigned long)));
	if (m == ll || t == p)
		return ((uintmax_t)(nbr.llu = va_arg(args, unsigned long long)));
	if (t != p && m == hh)
	{
		return ((uintmax_t)(unsigned char)(nbr.uch =\
					va_arg(args, unsigned int)));
	}
	if (t != p && m == j)
		return ((nbr.unm = va_arg(args, uintmax_t)));
	return (0);
}

char					*cvt_unbr(t_conv c, va_list args)
{
	uintmax_t			nbr;
	char				*res;
	int					range;
	char				*base;
	int					pfx;

	base = get_base(c.type);
	nbr = get_nbr(c.mod, c.type, args);
	if (c.type == p && !nbr)
	{
		if (c.prec > 0)
			return (ft_chgprec(ft_strdup("0x0"), 3, c.prec, 2));
		else
			return (c.prec == 0 ? ft_strdup("0x") : ft_strdup("0x0"));
	}
	range = find_range(c, nbr, ft_strlen(base));
	if ((res = ft_itoabase_pf(c, nbr, range, base)) == NULL)
		return (NULL);
	if (range - (pfx = get_pfxlen(res, c)) < c.prec)
		if ((res = ft_chgprec(res, range, c.prec, pfx)) == NULL)
			return (NULL);
	return (res);
}
