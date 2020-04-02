/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisauvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 03:38:15 by nisauvig          #+#    #+#             */
/*   Updated: 2020/03/12 17:46:53 by nisauvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/*
** ---------------------- < includes & defines > ----------------------------
*/

# include "cub3D.h"
# include "../libft/libft.h"
#define BUFFER_SIZE 15
/*
** ----------------------- < static structure > -----------------------------
*/

typedef struct		s_save
{
	char			*end;
	int				fd;
	struct s_save	*next;
}					t_save;

/*
** ---------------------- < main file  prototypes > -------------------------
*/

int					get_next_line(int fd, char **line);
t_save				*new_elem(int fd);
int					make_str(int fd, char **end, char **line);
void				free_elem_fd(t_save *index, int fd);
char				*ft_free(char *end, char *buf);
int					ft_bln(char *buf);

/*
** ------------------------- < tools prototype > ----------------------------
*/

char				*ft_strdupimp(char *src, int r);
char				*ft_strjoin_pimp(char *s1, char *s2);
size_t				ft_strlen_pimp(char *s, int r);

#endif
