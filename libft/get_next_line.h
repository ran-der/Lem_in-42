/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <rvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 16:07:56 by rvan-der          #+#    #+#             */
/*   Updated: 2017/03/14 21:55:55 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include "libft.h"
# define BUFF_SIZE 8

typedef struct				s_file
{
	int						fd;
	char					*line;
	struct s_file			*next;
}							t_file;

int							get_next_line(int const fd, char **line);

#endif
