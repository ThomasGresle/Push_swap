#include "../includes/push_swap.h"

void	from_arr(t_list *list, int ac, char **av)
{
	int i;
	int list_size;
	int	number;
	int error;
	t_list_number *new;
	
	i = 1;
	list_size = ac;
	number = 0;
	error = 0;
	new = 0;
	while (i < list_size)
	{
		number = ft_atoi_check(av[i], &error);
		if (error)
		{
			ft_putstr("Error\nUn des arguments n'est pas un nombre\n");
			exit(0);
		}
		else
		{
			number = ft_atoi(av[i]);
			new = create_number(number);
			add_number(list, new);
		}
		i++;
	}
}

void	from_str(t_list *list, char *str)
{
	int i;
	long	number;
	int error;
	char **list_nbr;
	t_list_number *new;

	i = 0;
	number = 0;
	error = 0;
	list_nbr = ft_split(str, ' ');
	new = 0;
	while (list_nbr[i])
	{
		number = ft_atoi_check(list_nbr[i], &error);
		if (error)
		{
			ft_putstr("Error\nUn des arguments n'est pas un nombre\n");
			exit(0);
		}
		else
		{
			number = ft_atoi(list_nbr[i]);
			new = create_number(number);
			add_number(list, new);
		}
		i++;
	}
	free_array(list_nbr);
}

t_list	*create_list(int ac, char **av)
{
	t_list *list;

	list = (t_list *)malloc(sizeof(t_list));
	if (!(list))
		return (0);
	list->first = 0;
	list->keep_a = 0;
	list->size = 0;
	list->begin_sort = 0;
	if (ac > 2)
		from_arr(list, ac, av);
	else
		from_str(list, av[1]);
	if (list->size  == 0)
	{
		free_list(list);
		list = 0;
		return (0);
	}
	else
		return (list);
}

t_list_number	*return_unset_min(t_list *list)
{
	int	i;
	int	min_exists;
	t_list_number	*min;
	t_list_number	*tmp;

	i = 0;
	min_exists = 0;
	min = 0;
	tmp = list->first;
	while (i < list->size)
	{
		if (tmp->order == -1 && (min_exists == 0 || tmp->number < min->number))
		{
			min = tmp;
			min_exists = 1;
		}
		tmp = tmp->next;
		i++;
	}
	return (min);
}

void	order_list(t_list *list)
{
	int				order;
	t_list_number	*tmp;

	order = 0;
	tmp = return_unset_min(list);
	while (tmp)
	{
		tmp->order = order;
		order++;
		tmp = return_unset_min(list);
	}
}
