/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <rvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 14:34:41 by rvan-der          #+#    #+#             */
/*   Updated: 2017/02/20 20:56:34 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <inttypes.h>
# include <sys/types.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef enum			e_type
{
	s = 0,
	S,
	p,
	d,
	D,
	i,
	o,
	O,
	u,
	U,
	x,
	X,
	ch,
	C,
	pct
}						t_type;

typedef enum			e_mod
{
	hh = 1,
	h,
	l,
	ll,
	j,
	z
}						t_mod;

typedef union			u_val
{
	int					din;
	unsigned			uin;
	short				hin;
	unsigned short		hun;
	long				lin;
	unsigned long		lun;
	long long			lli;
	unsigned long long	llu;
	char				chr;
	unsigned char		uch;
	char				*str;
	wchar_t				wch;
	wchar_t				*wst;
	intmax_t			inm;
	uintmax_t			unm;
	size_t				szt;
}						t_val;

typedef struct			s_conv
{
	t_type				type;
	t_mod				mod;
	int					field;
	int					prec;
	int					altern;
	int					zero;
	int					min;
	int					plus;
	int					space;
}						t_conv;

typedef char			*(*t_cvtfct)(t_conv, va_list);

typedef struct			s_arg
{
	va_list				args;
	t_cvtfct			**ctab;
	int					nul;
}						t_arg;

/*
** ft_printf.c
*/
int						ft_printf(const char *format, ...);

/*
** ft_tools.c
*/
char					*ft_dstrnjoin(char *s1, char *s2, size_t n);
char					*ft_dstrjoin(char *s1, char *s2);
int						ft_check_tp(int y, int x);
int						ft_wstrlen(unsigned char *wstr);
char					*ft_dstrsub(char *str, size_t start, size_t end);

/*
** ft_get_conv.c
*/
int						ft_get_conv(char *format, t_conv **conversion, int i,\
									int indicator);
/*
** ft_write_conv.c
*/
char					*ft_write_conv(t_conv conv, t_arg *arg);
/*
** flag_tests.c
*/
int						ft_isvalid_type(char c);
int						ft_isvalid_mod(char c);
int						ft_isvalid_flag(char c);

/*
** cvt_unbr.c
*/
char					*cvt_unbr(t_conv c, va_list args);

/*
** cvt_snbr.c
*/
char					*cvt_snbr(t_conv c, va_list args);

/*
** cvt_txt.c
*/
char					*cvt_txt(t_conv c, va_list args);

/*
** cvt_wtxt.c
*/
char					*cvt_wtxt(t_conv c, va_list args);

/*
** nbr_tools.c
*/
char					*get_base(t_type t);
char					*ft_chgprec(char *res, int range, int prec, int pfx);
char					*min_nbr(void);
int						get_pfxlen(char *str, t_conv c);

#endif
