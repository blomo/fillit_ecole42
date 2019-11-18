/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheredat <dheredat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 16:43:02 by dheredat          #+#    #+#             */
/*   Updated: 2019/05/15 20:19:16 by dheredat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_fil_val_ext(int i, char *buff)
{
	if (i + 1 < 20 && (*(buff + i + 1) == '#'))
		t_val.contact++;
	if (i - 1 >= 0 && (*(buff + i - 1) == '#'))
		t_val.contact++;
	if (i - 5 >= 0 && (*(buff + i - 5) == '#'))
		t_val.contact++;
	if (i + 5 < 20 && (*(buff + i + 5) == '#'))
		t_val.contact++;
}

int		ft_fil_val_base(int i, char *buff)
{
	i = 0;
	while (i < 20 && *(buff + i))
	{
		if (*(buff + i) == '.')
			t_val.dot_count++;
		else if (*(buff + i) == '#')
		{
			t_val.nbs_count++;
			ft_fil_val_ext(i, buff);
		}
		else if (*(buff + i) == '\n')
		{
			t_val.nwl_count++;
			if (i - t_val.lnb != 4)
				return (-1);
			t_val.lnb = i + 1;
		}
		else
			return (-1);
		i++;
	}
	if (!(*(buff + i) == '\n' || *(buff + i) == '\0'))
		return (-1);
	(*(buff + i) == '\0') ? t_val.eof-- : t_val.eof++;
	return (1);
}

void	ft_fil_val_zero(void)
{
	t_val.nbs_count = 0;
	t_val.dot_count = 0;
	t_val.nwl_count = 0;
	t_val.lnb = 0;
	t_val.contact = 0;
}

int		ft_fil_val_core(int fd, t_list *head)
{
	char	buff[BUFF_SIZE + 1];
	char	*p_buff;
	int		i;

	i = 0;
	if ((read(fd, buff, 0)) < 0)
		return (-1);
	t_val.data = 0;
	while ((t_val.data = read(fd, buff, BUFF_SIZE)) > 0)
	{
		if (t_val.data < 20 || i > 25)
			return (-1);
		buff[t_val.data] = '\0';
		p_buff = buff;
		ft_fil_val_zero();
		if (ft_fil_val_base(i, p_buff) == -1)
			return (-1);
		if (!(t_val.dot_count == 12 && t_val.nbs_count == 4
		&& t_val.nwl_count == 4
		&& (t_val.contact == 6 || t_val.contact == 8)))
			return (-1);
		ft_fil_list_maker(&head, i, p_buff);
		i++;
	}
	return (i);
}
