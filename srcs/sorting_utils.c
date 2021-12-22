#include "../includes/push_swap.h"

int	is_move_to_b(t_list *list_a)
{
	int	i;
	t_list_number *tmp;

	i = 0;
	tmp = list_a->first;
	while (i < list_a->size)
	{
		if (tmp->no_move == 0)
			return (1);
		tmp = tmp->next;
		i++;
	}
	return (0);
}

void	move_s_util(t_list_number *first, t_list_number *second, t_list *list)
{
	t_list_number *prev;
	t_list_number *next;

	prev = first->previous;
	next = second->next;
	prev->next = second;
	second->previous = prev;
	first->next = next;
	next->previous = first;
	second->next = first;
	first->previous = second;
	list->first = second;
}

void	move_s(t_list *list, char *move, t_move_list *move_list)
{
	if (list && list->first && list->size >= 2)
		move_s_util(list->first, list->first->next, list);
	if (move && !(move_list))
	{
		ft_putstr(move);
		ft_putstr("\n");
	}
	if (move && move_list)
		add_move(move_list, create_move(move));
}

void	move_r(t_list *list, char *move, t_move_list *move_list)
{
	if (list->first)
		list->first = list->first->next;
	if (move && !(move_list))
	{
		ft_putstr(move);
		ft_putstr("\n");
	}
	if (move && move_list)
		add_move(move_list, create_move(move));
}

void	move_rr(t_list *list, char *move, t_move_list *move_list)
{
	if (list && list->first)
		list->first = list->first->previous;
	if (move && !(move_list))
	{
		ft_putstr(move);
		ft_putstr("\n");
	}
	if (move && move_list)
		add_move(move_list, create_move(move));
}
