/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:07:27 by rihoy             #+#    #+#             */
/*   Updated: 2023/12/21 16:08:11 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swaplib.h"

void	do_rr(t_stack **a, t_stack **b, int ra, int rb)
{
	while (ra && rb)
	{
		rota_all(a, b);
		ra--;
		rb--;
	}
	while (ra)
	{
		rota_a(a);
		ra--;
	}
	while (rb)
	{
		rota_b(b);
		rb--;
	}
	push_to_a(b, a);
}

void	do_ra_rrb(t_stack **a, t_stack **b, int ra, int rrb)
{
	while (ra)
	{
		rota_a(a);
		ra--;
	}
	while (rrb)
	{
		rev_rota_b(b);
		rrb--;
	}
	push_to_a(b, a);
}

void	do_rra_rb(t_stack **a, t_stack **b, int rra, int rb)
{
	while (rra)
	{
		rev_rota_a(a);
		rra--;
	}
	while (rb)
	{
		rota_b(b);
		rb--;
	}
	push_to_a(b, a);
}

void	do_rrr(t_stack **a, t_stack **b, int rra, int rrb)
{
	while (rra && rrb)
	{
		rev_rota_all(a, b);
		rra--;
		rrb--;
	}
	while (rra)
	{
		rev_rota_a(a);
		rra--;
	}
	while (rrb)
	{
		rev_rota_b(b);
		rrb--;
	}
	push_to_a(b, a);
}

void	do_best_cost(t_stack **a, t_stack **b, t_stack *srch)
{
	t_data	dt;
	int		best;

	dt.cost_ra = cost_ra(a, srch);
	dt.cost_rra = cost_rra(a, srch);
	dt.cost_rb = cost_rb(b, srch);
	dt.cost_rrb = cost_rrb(b, srch);
	best = best_way(dt.cost_ra, dt.cost_rb, dt.cost_rra, dt.cost_rrb);
	printf("ra %d ,rb %d ,rra %d ,rrb %d \n",dt.cost_ra, dt.cost_rb, dt.cost_rra, dt.cost_rrb);
	if (best == 1)
		do_rr(a, b, dt.cost_ra, dt.cost_rb);
	else if (best == 2)
		do_ra_rrb(a, b, dt.cost_ra, dt.cost_rrb);
	else if (best == 3)
		do_rra_rb(a, b, dt.cost_rra, dt.cost_rb);
	else
		do_rrr(a, b, dt.cost_rra, dt.cost_rrb);
}