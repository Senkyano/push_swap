/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:12:01 by rihoy             #+#    #+#             */
/*   Updated: 2023/12/18 14:18:01 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swaplib.h"

t_stack	*last_box(t_stack **stack)
{
	t_stack	*curr;
	
	curr = *stack;
	while (curr->next != NULL)
		curr = curr->next;
	return (curr);
}

int	cost_ra(t_stack **a, t_stack *srch)
{
	t_stack	*curr;
	int		i;

	i = 0;
	curr = *a;
	while (curr != NULL)
	{
		if (srch->nbr < curr->nbr)
			return (i);
		curr = curr->next;
		i++;
	}
	return (i);
}

int	cost_rra(t_stack **a, t_stack *srch)
{
	t_stack *curr;
	int		i;

	curr = last_box(a);
	i = 0;
	while (curr->prev != NULL)
	{
		if (srch->nbr > curr->nbr)
			return (i);
		curr = curr->prev;
		i++;
	}
	return (i);
}

int	cost_rb(t_stack **b, t_stack *srch)
{
	t_stack	*curr;
	int		i;

	i = 0;
	curr = *b;
	while (curr->next != NULL)
	{
		if (srch->nbr < curr->nbr)
			return (i);
		curr = curr->next;
		i++;
	}
}

int	cost_rrb(t_stack **b, t_stack *srch)
{
	t_stack	*curr;
	int		i;

	curr = last_box(b);
	i = 0;
	while (curr->next != NULL)
	{
		if (srch->nbr > curr->nbr)
			return (i);
		curr = curr->next;
		i++;
	}
	return (i);
}
