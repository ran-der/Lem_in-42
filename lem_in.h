/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 20:29:07 by rvan-der          #+#    #+#             */
/*   Updated: 2017/03/15 18:13:30 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include "libft/libft.h"
# include <stdio.h>
# include <sys/types.h>
# include <sys/uio.h>

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

void		print_rlist(t_room *rlist);
void		print_rtab(t_room **rtab, int size);
int			get_line_stdin(char **line);
t_map				*read_map(void);
int					get_room(char *buf, t_room **rms, int cmd);
int					room_id(t_room **rooms, int r, char *nm);
void				room_pushback(t_room **rooms, t_room *elem);
void				room_add(t_room **rooms, t_room *elem);
t_room				*new_room(char *nm, int cmd);
int					rlist_len(t_room *list);
int					check_buff(char **buf, t_map *map, int ofs);
int					check_for_room(char *buf);
int					check_for_link(char *buf);
void				make_link(char *buf, t_map *map);
t_room				*read_rooms(t_map *map, char **fstlink);
t_room				**make_rtab(t_room *rlist, int size);
int					read_links(t_map *map, char *fstlink);
void				delete_map(t_map **map);
void				delete_roomlst(t_room **list);
void				delete_itab(int **tab, int size);
void				delete_plist(t_path **plist);
int					main_error(t_map **map);
t_map				*rd_error(t_map **map);
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
t_path				**make_ptab(t_path *paths, int p);
int					**init_ctab(int size);
void				clear_slct_pth(int **ctab, t_path **ptab, int *best_set);
void				set_flow_info(t_map *map, t_path *plist);
void				play(t_map *map, t_path *paths);

#endif
