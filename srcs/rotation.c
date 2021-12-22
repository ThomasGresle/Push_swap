#include "../includes/push_swap.h"

void	pick_rotation(int size, t_swap new_swap, t_swap *swap)
{
	if (swap->no_move == 0 || size < swap->size)
	{
		swap->a_nbr = new_swap.a_nbr;
		swap->a_rotation = new_swap.a_rotation;
		swap->b_nbr = new_swap.b_nbr;
		swap->b_rotation = new_swap.b_rotation;
		swap->size = size;
		swap->no_move = 1;
	}
}

void	compare_rotations(t_list *list, int order, int *count_r, int *count_rr)
{
	t_list_number	*tmp;

	if (list && list->first)
	{
		tmp = list->first;
		while (tmp->order != order)
		{
			tmp = tmp->next;
			(*count_r)++;
		}
		tmp = list->first;
		while (tmp->order != order)
		{
			tmp = tmp->next;
			(*count_rr)++;
		}
	}
}

t_list_number	*find_spot_a(t_list *list_a, int order)
{
	t_list_number	*tmp;

	tmp = list_a->begin_sort;
	if (order < tmp->order)
	{
		while (order < tmp->previous->order && tmp->order > tmp->previous->order)
			tmp = tmp->previous;
	}
	else
	{
		while (order > tmp->order && tmp->order < tmp->next->order)
			tmp = tmp->next;
		if (order > tmp->order && tmp->order > tmp->next->order)
			tmp = tmp->next;
	}
	return (tmp);
}

void	best_rotation(t_list *list_a, t_list *list_b, t_list_number *tmp, t_swap *swap)
{
	t_swap	new_swap;
	int count_ra;
	int	count_rra;
	int	count_rb;
	int	count_rrb;

	count_ra = 0;
	count_rra = 0;
	count_rb = 0;
	count_rrb = 0;
	new_swap.a_nbr = find_spot_a(list_a, tmp->order);
	new_swap.b_nbr = tmp;
	compare_rotations(list_a, new_swap.a_nbr->order, &count_ra, &count_rra);
	compare_rotations(list_b, tmp->order, &count_rb, &count_rrb);
	new_swap.a_rotation = 0;
	new_swap.b_rotation = 0;
	pick_rotation(pick_max(count_ra, count_rb), new_swap, swap);
	new_swap.a_rotation = 1;
	pick_rotation(count_rra + count_rb, new_swap, swap);
	new_swap.b_rotation = 1;
	pick_rotation(pick_max(count_rra, count_rrb), new_swap, swap);
	new_swap.a_rotation = 0;
	pick_rotation(count_ra + count_rrb, new_swap, swap);
}

void	choose_rotation(t_list *list_a, t_list *list_b, t_swap *swap)
{
	int	i;
	t_list_number *tmp;

	i = 0;
	tmp = 0;
	if (list_b)
	{
		tmp = list_b->first;
		while (i < list_b->size)
		{
			best_rotation(list_a, list_b, tmp, swap);
			tmp = tmp->next;
			i++;
		}
	}
}
