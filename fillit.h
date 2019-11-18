/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheredat <dheredat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 14:35:19 by dheredat          #+#    #+#             */
/*   Updated: 2019/11/01 16:07:34 by dheredat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUFF_SIZE 21

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include "./libft/libft.h"

struct	s_val{
	int data;
	int blb;
	int lnb;
	int contact;
	int nbs_count;
	int dot_count;
	int nwl_count;
	int	eof;
}		t_val;

struct	s_map{
	int	side_size;
	int	sqr_max;
}		t_map;

int		ft_fil_val_error(void);
int		ft_fil_val_usage(void);
void	ft_fil_list_dstr(t_list *head);
void	ft_fil_val_ext(int i, char *buff);
int		ft_fil_val_base(int i, char *buff);
void	ft_fil_val_zero(void);
int		ft_fil_val_core(int fd, t_list *head);
int		*ft_fil_coor_grep(char **buff);
void	ft_fil_list_maker(t_list **head, int nb, char *buff);
void	ft_fil_core(t_list *head, int i);
int		ft_fil_sidecount(int nb);
char	*ft_fil_map_gen(int nb);
int		ft_fil_pos_check(char *map, int *coor, int i);
void	ft_fil_fig_paint(char **map, int *coor, int i, int letter);
void	ft_fil_fig_erase(char **map, int *coor, int i);
int		ft_fil_fig_place(char *map, t_list *current);

#endif
