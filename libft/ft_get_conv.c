/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 16:45:16 by rvan-der          #+#    #+#             */
/*   Updated: 2016/11/10 19:06:36 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_get_flags(char *format, t_conv **conv, int i)
{
	while (ft_isvalid_flag(format[i]))
	{
		if (format[i] == '#')
			(*conv)->altern = 1;
		else if (format[i] == '0')
			(*conv)->zero = 1;
		else if (format[i] == '+')
			(*conv)->plus = 1;
		else if (format[i] == '-')
			(*conv)->min = 1;
		else if (format[i] == ' ')
			(*conv)->space = 1;
		i++;
	}
	return (i);
}

static int		ft_get_mod(char *format, t_conv **conv, int i)
{
	if (format[i] == 'l' || format[i] == 'h')
	{
		if (format[i] == format[i + 1])
			(*conv)->mod = (format[i] == 'h' ? hh : ll);
		else
			(*conv)->mod = (format[i] == 'h' ? h : l);
		return (format[i] == format[i + 1] ? i + 2 : i + 1);
	}
	else
		(*conv)->mod = (format[i] == 'z' ? z : j);
	return (i + 1);
}

static int		ft_get_type2(t_conv **conv, char t)
{
	if (t == 'x')
		(*conv)->type = x;
	else if (t == 'X')
		(*conv)->type = X;
	else if (t == 'c')
		(*conv)->type = ch;
	else if (t == 'C')
		(*conv)->type = C;
	else if (t == '%')
		(*conv)->type = pct;
	else
		return (0);
	return (1);
}

static int		ft_get_type(t_conv **conv, char t)
{
	if (t == 's')
		(*conv)->type = s;
	else if (t == 'S')
		(*conv)->type = S;
	else if (t == 'p')
		(*conv)->type = p;
	else if (t == 'd')
		(*conv)->type = d;
	else if (t == 'D')
		(*conv)->type = D;
	else if (t == 'i')
		(*conv)->type = i;
	else if (t == 'o')
		(*conv)->type = o;
	else if (t == 'O')
		(*conv)->type = O;
	else if (t == 'u')
		(*conv)->type = u;
	else if (t == 'U')
		(*conv)->type = U;
	else
		return (ft_get_type2(conv, t));
	return (1);
}

/*
** indicator positions:
** 0: start
** 1: flags were found
** 2: field width was found
** 3: precision was found
** 4: modifier was found
*/

int				ft_get_conv(char *format, t_conv **c, int i,\
						int indicator)
{
	if (indicator < 1 && ft_isvalid_flag(format[i]) &&\
			(i = ft_get_flags(format, c, i)))
		return (ft_get_conv(format, c, i, 1));
	if (indicator < 2 && ft_isdigit(format[i]))
	{
		(*c)->field = ft_atoi(format + i);
		while (ft_isdigit(format[i]))
			i++;
		return (ft_get_conv(format, c, i, 2));
	}
	if (indicator < 3 && format[i] == '.')
	{
		(*c)->prec = ft_atoi(format + (++i));
		while (ft_isdigit(format[i]))
			i++;
		return (ft_get_conv(format, c, i, 3));
	}
	if (indicator < 4 && ft_isvalid_mod(format[i]) &&\
			(i = ft_get_mod(format, c, i)))
		return (ft_get_conv(format, c, i, 4));
	if (ft_isvalid_type(format[i]) && ft_get_type(c, format[i]))
		return (i + 1);
	return (0);
}
