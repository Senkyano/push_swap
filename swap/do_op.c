/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:07:27 by rihoy             #+#    #+#             */
/*   Updated: 2023/12/20 16:25:19 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swaplib.h"

void	do_rr(t_stack **a, t_stack **b)
{
	while ()
		rota_all(a, b);
	while ()
		rota_a(a);
	while ()
		rota_b(b);
	push_to_a(b, a);
}

void	do_ra_rrb(t_stack **a, t_stack **b)
{
	while ()
		rota_a(a);
	while ()
		rev_rota_b(b);
	push_to_a(b, a);
}

void	do_rra_rb(t_stack **a, t_stack **b)
{
	while ()
		rev_rota_a(a);
	while ()
		rota_b(b);
	push_to_a(b, a);
}

void	do_rrr(t_stack **a, t_stack **b)
{
	while ()
		rev_rota_all(a, b);
	while ()
		rev_rota_a(a);
	while ()
		rev_rota_b(b);
	push_to_a(b, a);
}

void	do_best_cost(t_stack **a, t_stack **b)
{
	
}