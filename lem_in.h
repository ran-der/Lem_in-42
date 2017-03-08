/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 20:29:07 by rvan-der          #+#    #+#             */
/*   Updated: 2017/03/08 16:11:46 by rvan-der         ###   ########.fr       */
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
	char			name[22];
	char			**links;
	int				dist;
	char			via[22];
	struct s_room	*next;
	struct s_room	*prev;
}					t_room;

typedef struct		s_path
{
	char			**path;
	int				id;
	int				len;
}					t_path;

typedef struct		s_map
{
	int				n;
	t_room			*rooms;
	t_path			*paths;
	char			*output;
}					t_map;


#endif
