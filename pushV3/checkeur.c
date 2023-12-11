/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkeur.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 10:16:10 by marvin            #+#    #+#             */
/*   Updated: 2023/12/11 10:16:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_V3.h"

int	value_checkeur(t_stack *tower)
{
	t_stack	*curr;

	curr = tower;
	while (curr->next != NULL)
	{
		if (curr->value > curr->next->value)
			return (0);
		curr = curr->next;
	}
	return (1);
}

int	same_value(t_stack *tower)
{
	t_stack *curr;
	t_stack	*check;

	curr = tower;
	check = tower->next;
	while (curr != NULL)
	{
		check = tower->next;
		while (check != NULL)
		{
			if (check->value == curr->value)
				return (0);
			check = check->next;
		}
		curr = curr->next;
	}
	return (1);
}

int	onlynum(char *str)
{
	if (*str == '-')
		str++;
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (0);
		str++;
	}
	return (1);
}
