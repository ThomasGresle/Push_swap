/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgresle <tgresle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 20:13:41 by tgresle           #+#    #+#             */
/*   Updated: 2021/12/22 21:31:01 by tgresle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	first_check(t_list *list)
{
	int				i;
	int				error;
	t_list_number	*nbr_i;
	t_list_number	*nbr_j;

	i = 0;
	error = 0;
	nbr_i = list->first;
	while (i < list->size)
	{
		nbr_j = nbr_i->next;
		while (nbr_j != nbr_i)
		{
			if (nbr_i->number == nbr_j->number)
				error = 1;
			nbr_j = nbr_j->next;
		}
		i++;
		nbr_i = nbr_i->next;
	}
	return (error);
}
