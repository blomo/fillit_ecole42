/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheredat <dheredat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 17:57:30 by dheredat          #+#    #+#             */
/*   Updated: 2019/05/15 21:41:52 by dheredat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_fil_core(t_list *head, int i)
{
	char	*map;
	int		try_count;
	t_list	*current;

	try_count = 0;
	current = head;
	while (try_count < 3)
	{
		if (try_count > 0)
			free(map);
		map = ft_fil_map_gen(i);
		if (ft_fil_fig_place(map, current) == 1)
			break ;
		try_count++;
	}
	free(map);
}

int		ft_fil_pos_check(char *map, int *coor, int i)
{
	if ((i + *(coor + 0) + *(coor + 1) *
	(t_map.side_size + 1) < t_map.sqr_max)
	&& *(map + ((i + *(coor + 0) + *(coor + 1)
	* (t_map.side_size + 1)))) == '.')
		if ((i + *(coor + 2) + *(coor + 3) *
		(t_map.side_size + 1) < t_map.sqr_max)
		&& *(map + ((i + *(coor + 2) + *(coor + 3)
		* (t_map.side_size + 1)))) == '.')
			if ((i + *(coor + 4) + *(coor + 5) *
			(t_map.side_size + 1) < t_map.sqr_max)
			&& *(map + ((i + *(coor + 4) + *(coor + 5)
			* (t_map.side_size + 1)))) == '.')
				if ((i + *(coor + 6) + *(coor + 7) *
				(t_map.side_size + 1) < t_map.sqr_max)
				&& *(map + ((i + *(coor + 6) + *(coor + 7)
				* (t_map.side_size + 1)))) == '.')
					return (1);
	return (-1);
}

void	ft_fil_fig_paint(char **map, int *coor, int i, int letter)
{
	*(*map + (i + *(coor + 0) + *(coor + 1) *
	(t_map.side_size + 1))) = 65 + letter + 0;
	*(*map + (i + *(coor + 2) + *(coor + 3) *
	(t_map.side_size + 1))) = 65 + letter + 0;
	*(*map + (i + *(coor + 4) + *(coor + 5) *
	(t_map.side_size + 1))) = 65 + letter + 0;
	*(*map + (i + *(coor + 6) + *(coor + 7) *
	(t_map.side_size + 1))) = 65 + letter + 0;
}

void	ft_fil_fig_erase(char **map, int *coor, int i)
{
	*(*map + ((i + *(coor + 0) + *(coor + 1)
	* (t_map.side_size + 1)))) = '.';
	*(*map + ((i + *(coor + 2) + *(coor + 3)
	* (t_map.side_size + 1)))) = '.';
	*(*map + ((i + *(coor + 4) + *(coor + 5)
	* (t_map.side_size + 1)))) = '.';
	*(*map + ((i + *(coor + 6) + *(coor + 7)
	* (t_map.side_size + 1)))) = '.';
}

int		ft_fil_fig_place(char *map, t_list *current)
{
	int i;

	if (current == NULL)
	{
		ft_putstr(map);
		return (1);
	}
	i = 0;
	while (i < t_map.sqr_max)
	{
		if (*(map + i) == '.')
		{
			if (ft_fil_pos_check(map, current->content, i) == 1)
			{
				ft_fil_fig_paint(&map, current->content,
				i, current->content_size);
				if (ft_fil_fig_place(map, current->next) == 1)
					return (1);
				ft_fil_fig_erase(&map, current->content, i);
			}
		}
		i++;
	}
	return (-1);
}
