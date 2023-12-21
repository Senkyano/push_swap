/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp_cost.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:24:42 by rihoy             #+#    #+#             */
/*   Updated: 2023/12/21 16:08:41 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swaplib.h"

int	best_way(int ra, int rb, int rra, int rrb)
{
	int	ra_rrb;
	int	rra_rb;
	int	rr;
	int rrr;
	
	ra_rrb = ra + rrb;
	rra_rb = rra + rb;
	rr = ra + rb;
	rrr = rra + rrb;
	if (rr <= ra_rrb && rr <= rra_rb && rr <= rrr)
		return (1);
	else if (ra_rrb <= rra_rb && ra_rrb <= rrr)
		return (2);
	else if (rra_rb <= rrr)
		return (3);
	return (4);
}

int	cost_way(t_stack **a, t_stack **b, t_stack *srch)
{
	t_data	dt;
	int		best;

	dt.cost_ra = cost_ra(a, srch);
	dt.cost_rb = cost_rb(b, srch);
	dt.cost_rra = cost_rra(a, srch);
	dt.cost_rrb = cost_rrb(b, srch);
	best = best_way(dt.cost_ra, dt.cost_rb, dt.cost_rra, dt.cost_rrb);
	if (best == 1)
	{
		if (dt.cost_ra > dt.cost_rb)
			return (dt.cost_ra);
		return (dt.cost_rb);
	}
	else if (best == 2)
		return (dt.cost_ra + dt.cost_rrb);
	else if (best == 3)
		return (dt.cost_rra + dt.cost_rb);
	else
	{
		if (dt.cost_rra > dt.cost_rrb)
			return (dt.cost_rra);
		return (dt.cost_rrb);	
	}
}
