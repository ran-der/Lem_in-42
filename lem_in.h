/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 20:29:07 by rvan-der          #+#    #+#             */
/*   Updated: 2017/03/13 17:06:52 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"
# include <stdio.h>

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
	int				*pth;
	int				len;
	int				pass;
	struct s_path	*next;
}					t_path;

typedef struct		s_map
{
	int				n;
	int				r;
	t_room			**rooms;
	int				**links;
	char			*output;
}					t_map;

t_map				*read_map(void);
int					get_room(char *buf, t_room **rms, int cmd);
t_room				*select_room(t_room *rooms, char *nm);
void				room_pushback(t_room **rooms, t_room *elem);
void				room_add(t_room **rooms, t_room *elem);
t_room				*new_room(char *nm, int cmd);
int					rlist_len(t_room *list);
int					check_buff(char **buf, t_map *map, int ofs);
int					check_for_room(char *buf);
int					check_for_link(char *buf);
t_map				*rd_error(t_map **map);
void				make_link(char *buf, t_map *map);
t_room				*read_rooms(t_map *map, char **fstlink);
t_room				**make_rtab(t_room *rlist, int size);
int					read_links(t_map *map, char *fstlink);
void				delete_map(t_map **map);
void				delete_roomlst(t_room **list);
void				delete_itab(int **tab, int size);
t_path				*find_paths(t_map *map);
void				path_add(t_path *elem, t_path **list);
int					plist_len(t_path *list);
t_path				*new_path(int *path);
int					*pathdup(int *path, int len);
int					pathlen(int *path);
int					paths_sum(int *line, t_path **ptab, int lid, int p);
int					path_nb(int *line, int p);
int					paths_cross(int *p1, int *p2);
t_path				*select_paths(t_map map, t_path *paths, int p);
void				sort_set(int *set, t_path **ptab);
int					is_sorted_set(int *set, t_path **ptab);
int					*select_best_set(int **ctab, t_path **ptab, int p);

#endif
