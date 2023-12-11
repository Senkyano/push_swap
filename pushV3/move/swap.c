/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:00:01 by marvin            #+#    #+#             */
/*   Updated: 2023/12/09 17:00:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_sp.h"

void	swap(t_stack *tower)
{
	t_stack	*first_room;
	t_stack	*tmp;

	if (tower == NULL)
		return ;
	first_room = tower;
	tmp = tower->next;
	first_room->next = tmp->next;
	first_room->prev = tmp;
	tmp->next = first_room;
	tmp->pre = NULL;
	tower = tmp;
}

void	swap_a(t_stack *tower)
{
	swap(tower);
	write(1, "sa\n", 3);
}

void	swap_b(t_stack *tower)
{
	swap(tower);
	write(1, "sb\n", 3);
}

void	swap_all(t_stack *tower_a, t_stack *tower_b)
{
	swap(tower_a);
	swap(tower_b);
	write(1, "sb\n", 3);
}
