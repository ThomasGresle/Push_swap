#include "../includes/push_swap.h"

int	use_sa_bigger(t_list *list_a)
{
	int	keep_a;

	keep_a = 0;
	if (list_a->size >= 2)
	{
		move_s(list_a, NULL, NULL);
		keep_a = number_keep_a_bigger(list_a->begin_sort);
		move_s(list_a, NULL, NULL);
		number_keep_a_bigger(list_a->begin_sort);
		if (keep_a > list_a->keep_a)
			return (1);
	}
	return (0);
}

void	sort_list_a_by_bigger(t_list *list_a, t_list *list_b,
			t_move_list *move_list)
{
	while (is_move_to_b(list_a))
	{
		if (use_sa_bigger(list_a))
		{
			move_s(list_a, "sa", move_list);
			list_a->keep_a = number_keep_a_bigger(list_a->begin_sort);
		}
		else if (list_a->first->no_move == 0)
			move_p(list_b, list_a, "pb", move_list);
		else
			move_r(list_a, "ra", move_list);
	}
}

t_move_list	*sort_by_bigger(t_list *list_a)
{
	int			error;
	t_list		*list_b;
	t_move_list *move_list;
	
	error = 0;
	list_b = create_list_b();
	move_list = create_move_list();
	if (!(list_b) || !(move_list))
	{
		ft_putstr("Error\nMalloc problem\n");
		free_list(list_a);
		if (list_b)
			free_list(list_b);
		if (move_list)
			free_move_list(move_list);
		exit (0);
	}
	sort_list_a_by_bigger(list_a, list_b, move_list);
	sort_list_b(list_a, list_b, move_list);
	finish_list_a(list_a, move_list);
	free_list(list_b);
	return (move_list);
}
