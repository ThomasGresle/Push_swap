#include "../includes/push_swap.h"

t_list_number *take_from(t_list *list)
{
	t_list_number *number;

	number = 0;
	if (list->size)
	{
		if (list->size == 1)
		{
			number = list->first;
			number->previous = 0;
			number->next = 0;
			list->first = 0;
		}
		else
		{
			number = list->first;
			list->first = list->first->next;
			number->previous->next = number->next;
			number->next->previous = number->previous;
			number->previous = 0;
			number->next = 0;
		}
		list->size -= 1;
	}
	return (number);
}

void	put_to(t_list *list, t_list_number *number)
{
	t_list_number *last;

	if (!(list->first))
	{
		list->first = number;
		list->first->previous = number;
		list->first->next = number;
	}
	else
	{
		last = list->first->previous;
		number->previous = last;
		last->next = number;
		number->next = list->first;
		list->first->previous = number;
		list->first = number;
	}
	list->size += 1;
}