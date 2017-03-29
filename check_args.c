/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 21:33:29 by rvan-der          #+#    #+#             */
/*   Updated: 2017/03/29 16:03:58 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_opt		*init_opt(void)
{
	t_opt		*ret;

	if ((ret = (t_opt*)malloc(sizeof(t_opt))) == NULL)
		return (NULL);
	ret->fd = 0;
	ret->path = 0;
	ret->color = 0;
	return (ret);
}

int			check_opt_f(char *arg, t_opt *opt)
{
	if (opt->fd != 0)
		return (0);
	return (open(arg, O_RDONLY));
}

int			check_opt_c(t_opt *opt)
{
	if (opt->color)
		return (0);
	return (1);
}

int			check_opt_p(t_opt *opt)
{
	if (opt->path)
		return (0);
	return (1);
}

t_opt		*check_args(int argc, char **argv)
{
	int			i;
	t_opt		*ret;

	if ((ret = init_opt()) == NULL)
		return (NULL);
	i = 0;
	while (++i < argc)
	{
		if (ft_strcmp(argv[i], "-p") && ft_strcmp(argv[i], "-c") && \
				ft_strcmp(argv[i], "-f"))
			return (arg_error(&ret));
		if (ft_strequ(argv[i], "-p") && !(ret->path = check_opt_p(ret)))
			return (arg_error(&ret));
		if (ft_strequ(argv[i], "-c") && !(ret->color = check_opt_c(ret)))
			return (arg_error(&ret));
		if (ft_strequ(argv[i], "-f") && (i == argc - 1 || \
							!(ret->fd = check_opt_f(argv[++i], ret))))
			return (arg_error(&ret));
	}
	return (ret);
}
