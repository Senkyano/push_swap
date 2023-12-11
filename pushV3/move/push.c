/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:20:40 by marvin            #+#    #+#             */
/*   Updated: 2023/12/09 16:20:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_sp.h"

void	push_to_a(t_stack *tower_from, t_stack *tower_to)
{
	t_stack *first_room;

	write(1, "pa\n", 3);
	if (!tower_to)
	{
		tower_to = tower;
		tower_from = tower_from->next;
		tower_from->prev = NULL;
		tower_to->next = NULL;
		return ;
	}
	first_room = tower_from;
	tower_from = tower->next;
	tower_from->prev = NULL;
	first_room->next = tower_to;
	tower_to->prev = first_room;
	tower_to = first_room;
}

void	push_to_b(t_stack *tower_from, t_stack *tower_to)
{
	t_stack *first_room;

	write(1, "pb\n", 3);
	if (!tower_to)
	{
		tower_to = tower;
		tower_from = tower_from->next;
		tower_from->prev = NULL;
		tower_to->next = NULL;
		return ;
	}
	first_room = tower_from;
	tower_from = tower->next;
	tower_from->prev = NULL;
	first_room->next = tower_to;
	tower_to->prev = first_room;
	tower_to = first_room;
}
