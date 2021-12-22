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

void	move_s(t_list *list, char *move, t_move_list *move_list)
{
	t_list_number *prev;
	t_list_number *next;

	if (list->size >= 2)
	{
		prev = list->first->previous;
		next = list->first->next->next;
		prev->next = list->first->next;
		list->first->next->previous = prev;
		list->first->next = next;
		next->previous = list->first;
		list->first->next->next = list->first;
		list->first->previous = list->first->next;
		list->first = list->first->next;
	}
	if (move && !(move_list))
	{
		ft_putstr(move);
		ft_putstr("\n");
	}
	if (move && move_list)
		add_move(move_list, create_move(move));
}

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
