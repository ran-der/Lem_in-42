/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2_ft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 22:42:03 by rvan-der          #+#    #+#             */
/*   Updated: 2017/03/28 21:53:42 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_set			*set_error(t_set **sets)
{
	delete_slist(sets);
	return (NULL);
}

t_opt			*arg_error(t_opt **opt)
{
	if (*opt != NULL)
	{
		free(*opt);
		*opt = NULL;
	}
	return (NULL);
}
