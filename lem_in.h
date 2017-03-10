/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 20:29:07 by rvan-der          #+#    #+#             */
/*   Updated: 2017/03/10 22:23:22 by rvan-der         ###   ########.fr       */
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
	int				ant;
	int				id;
	char			name[22];
	struct s_room	*next;
	struct s_room	*prev;
}					t_room;

typedef struct		s_path
{
	int				*path;
	int				id;
	int				len;
}					t_path;

typedef struct		s_map
{
	int				n;
	int				r;
	t_room			**rooms;
	int				**links;
	t_path			*paths;
	char			*output;
}					t_map;

t_map				*read_map(void);
int					get_room(char *buf, t_room **rms, int cmd);
t_room				*select_room(t_room *rooms, char *nm);
void				room_pushback(t_room **rooms, t_room *elem);
void				room_add(t_room **rooms, t_room *elem);
t_room				*new_room(char *nm, int cmd);
int					check_buff(char **buf, int *ofs, t_map *map);
int					check_for_room(char *buf);
int					check_for_link(char *buf);
t_map				*rd_error(t_map **map, char	*buf);
void				make_link(char *buf, t_room *rooms);
int					tabsize(char **tab);

#endif
