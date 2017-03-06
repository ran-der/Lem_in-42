/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 20:29:07 by rvan-der          #+#    #+#             */
/*   Updated: 2017/03/06 21:56:13 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct		s_room
{
	int				mark;
	int				start;
	int				end;
	char			*name;
	char			**links;
	int				dist;
	char			*via;
	struct s_room	*next;
	struct s_room	*prev;
}					t_room;

typedef struct		s_path
{
	char			**path;
	int				len;
}

typedef struct		s_map
{
	int				n;
	t_room			*rooms;
	t_list			*paths;
	char			*output;
}					t_map;


#endif
