/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgresle <tgresle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 20:15:32 by tgresle           #+#    #+#             */
/*   Updated: 2021/12/22 21:38:24 by tgresle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	move_p(t_list *dest, t_list *src, char *move, t_move_list *list)
{
	put_to(dest, take_from(src));
	if (move && !(list))
	{
		ft_putstr(move);
		ft_putstr("\n");
	}
	if (move && list)
		add_move(list, create_move(move));
}

void	move_r_all(t_list *list_a, t_list *list_b,
			char *move, t_move_list *move_list)
{
	move_r(list_a, NULL, NULL);
	move_r(list_b, NULL, NULL);
	if (move && !(move_list))
	{
		ft_putstr(move);
		ft_putstr("\n");
	}
	if (move && move_list)
		add_move(move_list, create_move(move));
}

void	move_rr_all(t_list *list_a, t_list *list_b,
			char *move, t_move_list *move_list)
{
	move_rr(list_a, NULL, NULL);
	move_rr(list_b, NULL, NULL);
	if (move && !(move_list))
	{
		ft_putstr(move);
		ft_putstr("\n");
	}
	if (move && move_list)
		add_move(move_list, create_move(move));
}

void	finish_list_a(t_list *list_a, t_move_list *move_list)
{
	int				count_ra;
	int				count_rra;
	t_list_number	*tmp;

	count_ra = 0;
	count_rra = 0;
	if (list_a && list_a->first)
	{
		tmp = list_a->first;
		while (tmp->order != 0)
		{
			tmp = tmp->next;
			count_ra++;
		}
		tmp = list_a->first;
		while (tmp->order != 0)
		{
			tmp = tmp->previous;
			count_rra++;
		}
		while (list_a->first->order != 0 && (count_ra < count_rra))
			move_r(list_a, "ra", move_list);
		while (list_a->first->order != 0 && (count_ra >= count_rra))
			move_rr(list_a, "rra", move_list);
	}
}
