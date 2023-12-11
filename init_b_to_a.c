/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:19:21 by marvin            #+#    #+#             */
/*   Updated: 2023/12/11 20:19:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_V3.h"

static void	set_target_b(t_stack *a, t_stack *b) 
{
	t_stack	*current_a;
	t_stack	*target_room;
	long			best_match_index;

	while (b)
	{
		best_match_index = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->value > b->value  && current_a->value < best_match_index)
			{
				best_match_index = current_a->value;
				target_room = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_index == LONG_MAX)
			b->target_room = find_min(a);
		else
			b->target_room = target_room;
		b = b->next;
	}
}

void	init_room_b(t_stack *a, t_stack *b)
{
	curr_index(a);
	curr_index(b);
	set_target_b(a, b);
}