#include "../includes/push_swap.h"

t_list	*create_list_b(void)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (!(list))
		return (0);
	list->first = 0;
	list->keep_a = 0;
	list->size = 0;
	list->begin_sort = 0;
	return (list);
}

t_move	*create_move(char *move)
{
	t_move	*tmp;

	tmp = (t_move *)malloc(sizeof(t_move));
	if (!(tmp))
		return (0);
	tmp->move = ft_strdup(move);
	if (!(tmp->move))
		return (0);
	tmp->next = 0;
	return (tmp);
}

t_move_list	*create_move_list(void)
{
	t_move_list *list;

	list = (t_list *)malloc(sizeof(t_list));
	if (!(list))
		return (0);
	list->first_move = 0;
	list->move_nbr = 0;
	return (list);
}

t_swap	*create_swap(void)
{
	t_swap	*swap;

	swap = (t_swap *)malloc(sizeof(t_swap));
	if (!(swap))
		return (0);
	swap->a_nbr = 0;
	swap->b_nbr = 0;
	swap->a_rotation = 0;
	swap->b_rotation = 0;
	swap->size = 0;
	swap->no_move = 0;
	return (swap);
}