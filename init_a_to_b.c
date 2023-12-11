/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:53:31 by marvin            #+#    #+#             */
/*   Updated: 2023/12/11 19:53:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_V3.h"

void	init_room_a(t_stack	*room_a, t_stack *room_b)
{
	curr_index(room_a);
	curr_index(room_b);
	set_target_a(a, b);
	cost_analysis_a(a, b);
	set_cheapest(a);
}

void	curr_index(t_stack *room)
{
	int	i;
	int	median;

	i = 0;
	if (!room)
		return (NULL);
	median = tower_len(room);
	while (room)
	{
		room->index = i;
		if (i <= median)
			room->median = 1;
		else
			room->median = 0;
		room = room->next;
		i++;
	}
}

static void	set_target_a(t_stack *room_a, t_stack *room_b)
{
	t_stack	*curr_b;
	t_stack	*target_room;
	long	best_match_index;

	while (room_a)
	{
		best_match_index = LONG_MIN;
		curr_b = b;
		while (curr_b)
		{
			if (curr_b->value < room_a->value && curr_b->value > best_match_index)
			{
				best_match_index = curr_b->value;
				target_room = curr_b;
			}
			curr_b = curr_b->next;
		}
		if (best_match_index == LONG_MIN)
			room_a->target_room = find_max(b);
		else
			a->target_room = target_room;
		room_a = a->next;
	}
}

static void	cost_analysis_a(t_stack	*room_a, t_stack *room_b)
{
	int	len_a;
	int	len_b;

	len_a = tower_len(room_a);
	len_b = tower_len(room_b);
	while (room_a)
	{
		room_a->push_cost = room_a->index;
		if (!(room_a->median))
			room_a->push_cost = len_a - (room_a->index);
		if (room_a->target_room->median)
			room_a->push_cost += room_a->target_room->index;
		else
			room_a->push_cost += len_b - (room_a->target_room->index);
		room_a = room_a->next;
	}
}

void	set_cheapest(t_stack *room)
{
	long		cheapest_value;
	t_stack		*cheapest_room;

	if (!room)
		return ;
	cheapest_value = LONG_MAX;
	while (room)
	{
		if (room->push_cost < cheapest_value)
		{
			cheapest_value = room->push_cost;
			cheapest_room = room;
		}
		room = room->next;
	}
	cheapest_room->cheapest = 1;
}