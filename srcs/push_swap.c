/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgresle <tgresle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 20:14:53 by tgresle           #+#    #+#             */
/*   Updated: 2021/12/22 21:37:56 by tgresle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_sort_list(t_list *list_1, t_list *list_2)
{
	free_list(list_1);
	free_list(list_2);
	exit(0);
}

void	sort_list_of_2(t_list *list_1, t_list *list_2)
{	
	int				size;
	t_list_number	*tmp;

	size = 1;
	tmp = list_1->first->next;
	while (tmp != list_1->first)
	{
		tmp = tmp->next;
		size++;
	}
	if (size == 1)
		free_sort_list(list_1, list_2);
	else if (size == 2)
	{
		if (list_1->first->number > list_1->first->next->number)
		{
			ft_putstr("sa\n");
			free_sort_list(list_1, list_2);
		}
		free_sort_list(list_1, list_2);
	}
}

void	export_moves(t_move_list *list)
{
	t_move	*tmp;

	tmp = list->first_move;
	while (tmp)
	{
		ft_putstr(tmp->move);
		ft_putstr("\n");
		tmp = tmp->next;
	}
}

void	order_and_sort(t_list *list_by_bigger, t_list *list_by_link)
{
	t_move_list	*moves_by_bigger;
	t_move_list	*moves_by_link;

	moves_by_bigger = 0;
	moves_by_link = 0;
	order_list(list_by_bigger);
	order_list(list_by_link);
	set_begin_sort_bigger(list_by_bigger);
	set_begin_sort_link(list_by_link);
	moves_by_bigger = sort_by_bigger(list_by_bigger);
	free_list(list_by_bigger);
	moves_by_link = sort_by_link(list_by_link);
	free_list(list_by_link);
	if (moves_by_bigger->move_nbr > moves_by_link->move_nbr)
		export_moves(moves_by_link);
	else
		export_moves(moves_by_bigger);
	free_move_list(moves_by_bigger);
	free_move_list(moves_by_link);
}

int	main(int ac, char **av)
{
	int		error;
	t_list	*list_by_bigger;
	t_list	*list_by_link;

	error = 0;
	if (ac < 2)
		ft_putstr("Error\nWrong number of arguments\n");
	else
	{
		list_by_bigger = create_list(ac, av);
		error = first_check(list_by_bigger);
		list_by_link = create_list(ac, av);
		if (error == 1 || !(list_by_bigger) || !(list_by_link))
		{
			if (list_by_bigger)
				free_list(list_by_bigger);
			if (list_by_link)
				free_list(list_by_link);
			ft_putstr("Error\nIncorrect stack\n");
			return (0);
		}
		sort_list_of_2(list_by_bigger, list_by_link);
		order_and_sort(list_by_bigger, list_by_link);
	}
	return (0);
}
