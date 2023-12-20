/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:14:29 by rihoy             #+#    #+#             */
/*   Updated: 2023/12/20 19:47:41 by rihoy            ###   ########.fr       */
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

int	cost_ra(t_stack **a, t_stack *btw)
{
	t_stack *front;
	t_stack	*back;
	t_data	min;
	int		i;

	min = min_value(a);
	if (min.box->nbr > btw->nbr)
		return (min.i);
	else
	{
		i = 0;
		back = last_box(a);
		front = *a;
		printf("front %d, btw %d, back %d\n", front->nbr, btw->nbr, back->nbr);
		while (front_back(front->nbr, btw->nbr, back->nbr) == 0)
		{
			back = back->next;
			front = front->next;
			if (back == NULL)
				back = *a;
			if (front == NULL)
				front = *a;
			i++;
		}
		return (i);
	}
}

int	cost_rra(t_stack **a, t_stack *btw)
{
	t_stack	*front;
	t_stack	*back;
	t_data	min;
	int		i;

	min = min_value(a);
	if (min.box->nbr > btw->nbr)
	{
		printf("min %d ", min.i);
		return (min.i);
	}
	else
	{
		i = 0;
		back = *a;
		front = last_box(a);
		printf("front %d, btw %d, back %d\n", front->nbr, btw->nbr, back->nbr);
		while (back_front(back->nbr, btw->nbr, front->nbr))
		{
			back = back->prev;
			front = front->prev;
			if (back == NULL)
				back = last_box(a);
			if (front == NULL)
				front = last_box(a);
			i++;
		}
		return (i);
	}
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
{
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
}
