/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgresle <tgresle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 10:58:13 by tgresle           #+#    #+#             */
/*   Updated: 2021/12/22 21:09:44 by tgresle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static	int	check(const char *str, int *i, int *erreur)
{
	while (str[*i] == ' ' || str[*i] == '\t' || str[*i] == '\n'
		|| str[*i] == '\v' || str[*i] == '\f' || str[*i] == '\r')
	{
		(*i)++;
	}
	if (str[*i] == '\0' || (str[*i] != '+'
			&& str[*i] != '-' && (str[*i] < 48 && str[*i] > 57)))
	{
		*erreur = 1;
		return (0);
	}
	else if (str[*i] == '-')
	{
		(*i)++;
		return (-1);
	}
	else if (str[*i] == '+')
	{
		(*i)++;
		return (1);
	}
	else
		return (1);
}

int	ft_atoi(const char *str)
{
	int		i;
	long	resultat;
	int		erreur;
	int		signe;

	i = 0;
	resultat = 0;
	erreur = 0;
	signe = check(str, &i, &erreur);
	if (erreur == 1)
		return (-1);
	while (str[i] >= 48 && str[i] <= 57)
	{
		resultat = (resultat * 10) + (str[i] - 48);
		i++;
	}
	return (resultat * signe);
}
