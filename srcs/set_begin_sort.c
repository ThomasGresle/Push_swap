#include "../includes/push_swap.h"

int	number_keep_a_bigger(t_list_number *begin_sort)
{
	int	order;
	int	keep_a;
	t_list_number	*tmp;

	order = begin_sort->order;
	keep_a = 0;
	begin_sort->no_move = 1;
	tmp = begin_sort->next;
	while (tmp != begin_sort)
	{
		if (tmp->order > order)
		{
			keep_a += 1;
			order = tmp->order;
			tmp->no_move = 1;
		}
		else
			tmp->no_move = 0;
		tmp = tmp->next;
	}
	return (keep_a);
}

void	set_begin_sort_bigger(t_list *list)
{
	int	i;
	int	keep_a;
	t_list_number *tmp;

	i = 0;
	keep_a = 0;
	tmp = list->first;
	while (i < list->size)
	{
		keep_a = number_keep_a_bigger(tmp);
		if (keep_a > list->keep_a)
		{
			list->begin_sort = tmp;
			list->keep_a = keep_a;
		}
		else if (keep_a == list->keep_a && (list->begin_sort == 0
			|| tmp->number < list->begin_sort->number))
			list->begin_sort = tmp;
		tmp = tmp->next;
		i++;
	}
	number_keep_a_bigger(list->begin_sort);
}

int	number_keep_a_link(t_list_number *begin_sort)
{
	int	order;
	int	keep_a;
	t_list_number	*tmp;

	order = begin_sort->order;
	keep_a = 0;
	begin_sort->no_move = 1;
	tmp = begin_sort->next;
	while (tmp != begin_sort)
	{
		if (tmp->order == order + 1)
		{
			keep_a += 1;
			order = tmp->order;
			tmp->no_move = 1;
		}
		else
			tmp->no_move = 0;
		tmp = tmp->next;
	}
	return (keep_a);
}

void	set_begin_sort_link(t_list *list)
{
	int	i;
	int	keep_a;
	t_list_number *tmp;

	i = 0;
	keep_a = 0;
	tmp = list->first;
	while (i < list->size)
	{
		keep_a = number_keep_a_link(tmp);
		if (keep_a > list->keep_a)
		{
			list->begin_sort = tmp;
			list->keep_a = keep_a;
		}
		else if (keep_a == list->keep_a && (list->begin_sort == 0
			|| tmp->number < list->begin_sort->number))
			list->begin_sort = tmp;
		tmp = tmp->next;
		i++;
	}
	number_keep_a_link(list->begin_sort);
}