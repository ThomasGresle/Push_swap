#include "../includes/push_swap.h"

void	free_array(char **mat)
{
	int	i;

	i = 0;
	while (mat && mat[i])
	{
		free(mat[i]);
		i++;
	}
	if (mat && mat[i])
		free(mat[i]);
	if (mat)
		free(mat);
}

void	free_list(t_list *list)
{
	int i;
	t_list_number *tmp;
	t_list_number *to_free;

	i = 0;
	to_free = list->first;
	while(i < list->size)
	{
		tmp = to_free;
		to_free = to_free->next;
		free(tmp);
		i++;
	}
	free(list);
}

void	free_move_list(t_move_list *list)
{
	t_move	*tmp;
	t_move	*to_free;

	tmp = list->first_move;
	while (tmp)
	{
		to_free = tmp;
		tmp = tmp->next;
		free(to_free->move);
		free(to_free);
	}
	free(list);
}
