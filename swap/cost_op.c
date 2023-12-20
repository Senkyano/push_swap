/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:14:29 by rihoy             #+#    #+#             */
/*   Updated: 2023/12/20 16:48:11 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swaplib.h"

t_stack	*last_box(t_stack **b)
{
	t_stack	*curr;

	curr = *b;
	while (curr->next != NULL)
		curr = curr->next;
	return (curr);
}

int	cost_ra(t_stack **a, t_stack *here)
{
	t_stack *curr;
	t_data	min;
	int		i;

	min = min_value(a);
	if (min.box->nbr > here->nbr)
		return (min.i);
	else
	{
		i = 0;
		curr = *a;
		while (here->nbr > curr->nbr ||)
	}
}

int	cost_rra(t_stack **a, t_stack *here)
{
	
}

int	cost_rb(t_stack **b, t_stack *srch)
{
	t_stack *curr;
	int		i;

	curr = *b;
	i = 0;
	while (curr->nbr != srch->nbr)
	{
		curr = curr->next;
		i++;
	}
	return (i);
}

int	cost_rrb(t_stack **b, t_stack *srch)
[
	t_stack *curr;
	int		i;

	i = 1;
	curr = last_box(b);
	while (curr->nbr != srch->nbr)
	{
		curr = curr->prev;
		i++;
	}
	return (i);
]
