/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:54:07 by marvin            #+#    #+#             */
/*   Updated: 2023/12/11 15:54:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_V3.h"

void	three_room(t_stack **tower) // pour gerer si il y a 3 room
{
	t_stack	*first;
	t_stack	*sec;

	first = *tower;
	sec = first->next;
	if (first->value > sec->value && first->value < sec->next->value)
		swap_a(tower);
	else if (first->value > sec->next->value && first->value > sec->value)
		rota_a(tower);
	else
		rev_rota_a(tower);
}

void	sort_tower(t_stack **tower_a, t_stack **tower_b)
{
	int	len_a;

	len_a = tower_len(tower_a);
	if (len_a-- > 3 && !value_checkeur(*tower_a))
		push_to_b(tower_a, tower_b);
	if (len_a-- > 3 && !value_checkeur(*tower_a))
		push_to_b(tower_a, tower_b);
	while (len_a-- > 3 && !value_checkeur(*tower_a))
	{
		init_room_a(*tower_a, *tower_b);
		move_a_to_b(tower_a, tower_b);
	}
	three_room(tower_a);
	while (*tower_b)
	{
		init_room_b(*tower_a, *tower_b);
		move_b_to_a(tower_a, tower_b);
	}
	curr_index(*tower_a);
	min_on_top(tower_a);
}
