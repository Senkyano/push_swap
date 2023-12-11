/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rota.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:34:50 by marvin            #+#    #+#             */
/*   Updated: 2023/12/09 16:34:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_sp.h"

void	rev_rota(t_stack *tower)
{
	t_stack *first_room;
	t_stack	*last_room;

	if (tower->next == NULL)
		return ;
	first_room = tower;
	last_room = tower;
	while (last_room->next != NULL)
		last_room = last_room->next;
	last_room->next = first_room;
	first_room->pre = last_room;
	last_room->prev->next = NULL;
	last_room->prev = NULL;
	tower = last_room;
}

void	rev_rota_a(t_stack *tower)
{
	if (rev_rota(tower))
		write(1, "rra\n", 4);
}

void	rev_rota_b(t_stack *tower)
{
	if (rev_rota(tower))
		write(1, "rrb\n", 4);
}

void	rev_rota_all(t_stack *tower_a, t_stack *tower_b)
{
	if (rev_rota(tower_a) && rev_rota(tower_b))
		write(1, "rrr\n", 4);
}