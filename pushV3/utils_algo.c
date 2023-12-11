/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:20:09 by marvin            #+#    #+#             */
/*   Updated: 2023/12/11 20:20:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_V3.h"

static void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*b != cheapest_node->target_room && *a != cheapest_node)
		rota_all(a, b);
	curr_index(*a);
	curr_index(*b);
}

static void	rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*b != cheapest_node->target_room && *a != cheapest_node)
		rev_rota_all(a, b);
	curr_index(*a);
	curr_index(*b);
}

static void	move_a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = get_cheapest(*a); 
	if (cheapest_node->median && cheapest_node->target_room->median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->median) && !(cheapest_node->target_room->median))
	prep_for_push(a, cheapest_node, 'a');
	prep_for_push(b, cheapest_node->target_room, 'b');
	push_to_b(b, a);
}

static void	move_b_to_a(t_stack **a, t_stack **b)
{
	prep_for_push(a, (*b)->target_room, 'a');
	push_to_a(a, b); 
}

static void	min_on_top(t_stack **a)
{
	while ((*a)->value != find_min(*a)->value)
	{
		if (find_min(*a)->median)
			rota_a(a);
		else
			rev_rota_a(a);
	}
}
