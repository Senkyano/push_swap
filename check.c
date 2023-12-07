/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:03:50 by rihoy             #+#    #+#             */
/*   Updated: 2023/12/07 16:29:40 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

int	check_value(t_pile **pile_a)
{
	t_pile	*curr;

	curr = *pile_a;
	while (curr->next != NULL && curr != NULL)
	{
		if (curr->num > curr->next->num)
			return (0);
		curr = curr->next;
	}
	return (1);
}

int	same_value(t_pile **pile_a)
{
	t_pile	*curr;
	t_pile	*search;

	curr = *pile_a;
	while (curr != NULL)
	{
		search = curr->next;
		while (search != NULL)
		{
			if (search->num == curr->num)
				return (0);
			search = search->next;
		}
		curr = curr->next;
	}
	return (1);
}

int	str_isdigit(const char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-')
		i++;
	while (str[i] != '\0')
	{
		if ((str[i] < '0' || str[i] > '9'))
			return (0);
		i++;
	}
	return (1);
}

int	number_case(t_pile **pile_a)
{
	t_pile	*curr;
	int		i;

	curr = *pile_a;
	i = 0;
	while (curr != NULL)
	{
		curr = curr->next;
		i++;
	}
	return (i);
}
