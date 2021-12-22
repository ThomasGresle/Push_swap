#include "../includes/push_swap.h"

void	rotate_b(t_list *list_a, t_list *list_b, t_swap *swap, t_move_list *move_list)
{
	while (swap->a_nbr != list_a->first || swap->b_nbr != list_b->first)
	{
		if (swap->a_rotation == swap->b_rotation &&
			swap->a_nbr != list_a->first &&
			swap->b_nbr != list_b->first)
		{
			if (swap->a_rotation == 0)
				move_r_all(list_a, list_b, "rr", move_list);
			else
				move_rr_all(list_a, list_b, "rrr", move_list);
		}
		else if (swap->a_nbr != list_a->first)
		{
			if (swap->a_rotation == 0)
				move_r(list_a, "ra", move_list);
			else
				move_rr(list_a, "rra", move_list);
		}
		else if (swap->b_nbr != list_b->first)
		{
			if (swap->b_rotation == 0)
				move_r(list_b, "rb", move_list);
			else
				move_rr(list_b, "rrb", move_list);
		}
	}
}

void	sort_list_b(t_list *list_a, t_list *list_b, t_move_list *move_list)
{
	t_swap *swap;

	swap = create_swap();
	if (!(swap))
	{
		ft_putstr("Error\nMalloc failed\n");
		free_list(list_a);
		free_list(list_b);
		free_move_list(move_list);
		exit (0);
	}
	while (list_b->size)
	{
		swap->no_move = 0;
		choose_rotation(list_a, list_b, swap);
		rotate_b(list_a, list_b, swap, move_list);
		move_p(list_a, list_b, "pa", move_list);
	}
	free(swap);
}