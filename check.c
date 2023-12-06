/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:03:50 by rihoy             #+#    #+#             */
/*   Updated: 2023/12/06 15:00:33 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_pusg_swap.h"

int	check_valeur(t_pile **pile_a)
{
	t_pile	*curr;

	curr = *pile_a;
	while (curr->next != NULL && curr != NULL)
	{
		if (curr->num < curr->next->num)
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
			if (seach->num == curr->num)
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
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	number_case(t_pile **pile_a)
{
	
}