/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grep_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheredat <dheredat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 17:29:34 by dheredat          #+#    #+#             */
/*   Updated: 2019/05/15 20:19:20 by dheredat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_fil_sidecount(int nb)
{
	int i;

	i = 1;
	nb *= 4;
	while (i * i < nb)
		i++;
	return (i);
}

char	*ft_fil_map_gen(int nb)
{
	char	*map;
	int		i;

	if (!t_map.side_size)
		t_map.side_size = ft_fil_sidecount(nb);
	else
		t_map.side_size++;
	t_map.sqr_max = t_map.side_size * (t_map.side_size + 1);
	map = ft_strnew((size_t)(t_map.sqr_max));
	i = 0;
	while (i < t_map.side_size * (t_map.side_size + 1))
	{
		if (((i / t_map.side_size == 1 && i % t_map.side_size == 0)
			|| (i / (t_map.side_size + 1) > 0
			&& i % (t_map.side_size + 1) == t_map.side_size)))
			*(map + i) = '\n';
		else
			*(map + i) = '.';
		i++;
	}
	return (map);
}

int		*ft_fil_coor_grep(char **buff)
{
	int i;
	int *coor;

	i = 0;
	coor = (int*)malloc(sizeof(int) * 8);
	while (*(*buff + i))
	{
		if (*(*buff + i) == '#')
		{
			*coor++ = i % 5;
			*coor++ = i / 5;
		}
		i++;
	}
	coor -= 8;
	i = 0;
	*(coor + 2) = (*(coor + 2) - *(coor + 0));
	*(coor + 4) = (*(coor + 4) - *(coor + 0));
	*(coor + 6) = *(coor + 6) - *(coor + 0);
	*(coor + 0) = 0;
	*(coor + 3) = *(coor + 3) - *(coor + 1);
	*(coor + 5) = *(coor + 5) - *(coor + 1);
	*(coor + 7) = *(coor + 7) - *(coor + 1);
	*(coor + 1) = 0;
	return (coor);
}

void	ft_fil_list_maker(t_list **head, int nb, char *buff)
{
	t_list	*cur;

	if ((*head)->content == NULL)
	{
		(*head)->content_size = (size_t)nb;
		(*head)->content = ft_fil_coor_grep(&buff);
		(*head)->next = NULL;
		return ;
	}
	cur = *head;
	while (cur)
	{
		if (cur->next == NULL)
		{
			cur->next = ft_lstnew(NULL, 0);
			cur = cur->next;
			cur->content_size = nb;
			cur->content = ft_fil_coor_grep(&buff);
			cur->next = NULL;
			return ;
		}
		cur = cur->next;
	}
}
