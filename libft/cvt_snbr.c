/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvt_snbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 17:42:22 by rvan-der          #+#    #+#             */
/*   Updated: 2016/11/10 19:18:43 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char			*get_prefix(t_conv c, intmax_t nbr)
{
	if (c.plus && !nbr && c.prec != 0)
		return ("+0");
	if (c.space && !nbr && c.prec != 0)
		return (" 0");
	if (!nbr && c.prec != 0)
		return ("0");
	if (c.plus && nbr >= 0)
		return ("+");
	if (nbr < 0)
		return ("-");
	if (c.space)
		return (" ");
	return (NULL);
}

static int			find_range(intmax_t n, t_conv c)
{
	int					range;

	range = (!n && c.prec != 0 ? 1 : 0);
	range = ((n < 0 || c.plus || c.space) ? range + 1 : range);
	n = (n < 0 ? -n : n);
	while (n != 0)
	{
		range++;
		n = n / 10;
	}
	return (range);
}

static char			*ft_itoa_pf(t_conv c, intmax_t n, int range)
{
	int					i;
	char				*nbr;
	char				*prefix;

	if ((nbr = (char*)malloc(sizeof(char) * (range + 1))) == NULL)
		return (NULL);
	if ((prefix = get_prefix(c, n)) != NULL)
	{
		i = -1;
		while (prefix[++i] != '\0')
			nbr[i] = prefix[i];
	}
	i = range - 1;
	n = (n < 0 ? -n : n);
	while (n != 0)
	{
		nbr[i--] = '0' + ABS(ABS(n % 10));
		n = n / 10;
	}
	nbr[range] = '\0';
	return (nbr);
}

static intmax_t		get_nbr(t_mod m, t_type t, va_list args)
{
	t_val				nbr;

	if ((t == d || t == i) && !m)
		return ((intmax_t)(nbr.din = va_arg(args, int)));
	if ((t == d || t == D || t == i) && m == h)
		return ((intmax_t)(short)(nbr.din = va_arg(args, int)));
	if (((t == i || t == d || t == D) && m == l) || (t == D && !m))
		return ((intmax_t)(nbr.lin = va_arg(args, long)));
	if ((t == d || t == D || t == i) && m == ll)
		return ((intmax_t)(nbr.lli = va_arg(args, long long)));
	if ((t == d || t == D || t == i) && m == hh)
		return ((intmax_t)(char)(nbr.chr = va_arg(args, int)));
	if ((t == d || t == D || t == i) && m == j)
		return ((nbr.inm = va_arg(args, intmax_t)));
	return (0);
}

char				*cvt_snbr(t_conv c, va_list args)
{
	intmax_t			nbr;
	char				*res;
	int					range;
	int					pfx;

	nbr = get_nbr(c.mod, c.type, args);
	range = find_range(nbr, c);
	if ((res = ft_itoa_pf(c, nbr, range)) == NULL)
		return (NULL);
	if (range - (pfx = get_pfxlen(res, c)) < c.prec)
		if ((res = ft_chgprec(res, range, c.prec, pfx)) == NULL)
			return (NULL);
	return (res);
}
