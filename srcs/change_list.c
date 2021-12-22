#include "../includes/push_swap.h"

t_list_number	*create_number(int number)
{
	t_list_number	*new;

	new = (t_list_number *)malloc(sizeof(t_list_number));
	if (!(new))
		return (0);
	new->number = number;
	new->no_move = 0;
	new->order = -1;
	new->previous = NULL;
	new->next = NULL;
	return (new);
}

void			add_number(t_list *list, t_list_number *number)
{
	t_list_number	*tmp;

	if (list && number)
	{
		if (!list->first)
		{
			list->first = number;
			list->first->previous = number;
			list->first->next = number;
		}
		else
		{
			tmp = list->first->previous;
			number->previous = tmp;
			tmp->next = number;
			number->next = list->first;
			list->first->previous = number;
		}
		list->size++;
	}
}