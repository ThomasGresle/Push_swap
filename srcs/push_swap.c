#include "../includes/push_swap.h"

void	export_moves(t_move_list *list)
{
	t_move	*tmp;

	tmp = list->first_move;
	while (tmp)
	{
		ft_putstr(tmp->move);
		ft_putstr("\n");
		tmp = tmp->next;
	}
}

void	order_and_sort(t_list *list_by_bigger, t_list *list_by_link)
{
	t_move_list	*moves_by_bigger;
	t_move_list	*moves_by_link;

	moves_by_bigger = 0;
	moves_by_link = 0;
	order_list(list_by_bigger);
	order_list(list_by_link);
	set_begin_sort_bigger(list_by_bigger);
	set_begin_sort_link(list_by_link);
	moves_by_bigger = sort_by_bigger(list_by_bigger);
	free_list(list_by_bigger);
	moves_by_link = sort_by_link(list_by_link);
	free_list(list_by_link);
	if (moves_by_bigger->move_nbr > moves_by_link->move_nbr)
		export_moves(moves_by_link);
	else
		export_moves(moves_by_bigger);
	free_move_list(moves_by_bigger);
	free_move_list(moves_by_link);
}

int main(int ac, char **av)
{
	int			error;
    t_list		*list_by_bigger;
	t_list		*list_by_link;

	error = 0;
	if (ac < 2)
		ft_putstr("Error\nWrong number of arguments\n");
	else
	{
		list_by_bigger = create_list(ac, av);
		error = first_check(list_by_bigger);
		list_by_link = create_list(ac, av);
		if (error == 1 || !(list_by_bigger) || !(list_by_link))
		{
			if (list_by_bigger)
				free_list(list_by_bigger);
			if (list_by_link)
				free_list(list_by_link);
			ft_putstr("Error\nIncorrect stack\n");
			return (0);
		}
		order_and_sort(list_by_bigger, list_by_link);
	}
	return (0);
}