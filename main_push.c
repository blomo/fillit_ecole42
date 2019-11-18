/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheredat <dheredat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 15:38:39 by dheredat          #+#    #+#             */
/*   Updated: 2019/11/01 16:03:37 by dheredat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_fil_val_error(void)
{
	ft_putendl("error");
	return (1);
}

int		ft_fil_val_usage(void)
{
	ft_putendl("usage: fillit tetraminos_list");
	return (1);
}

void	ft_fil_list_dstr(t_list *head)
{
	t_list *current;
	t_list *next;

	if (head->content)
	{
		free(head->content);
		head->content = NULL;
	}
	current = head->next;
	while (current)
	{
		next = current->next;
		if (current->content)
		{
			free(current->content);
			current->content = NULL;
		}
		free(current);
		current = NULL;
		current = next;
	}
}

int		main(int argc, char **argv)
{
	t_list	head;
	int		fd;
	int		i;

	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) > 0)
		{
			if ((i = ft_fil_val_core(fd, &head)) > 0 && t_val.eof == i - 2)
				ft_fil_core(&head, i);
			else
			{
				close(fd);
				ft_fil_list_dstr(&head);
				return (ft_fil_val_error());
			}
			close(fd);
			ft_fil_list_dstr(&head);
		}
		else
			return (ft_fil_val_error());
	}
	else
		return (ft_fil_val_usage());
	return (0);
}
