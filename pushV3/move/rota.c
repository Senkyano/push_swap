/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rota.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:54:50 by marvin            #+#    #+#             */
/*   Updated: 2023/12/09 16:54:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_V3.h"

void	rota(t_stack **tower)
{
	t_stack	*first_room;
	t_stack	*last_room;

	if ((*tower) == NULL)
		return ;
	first_room = (*tower);
	last_room = (*tower);
	(*tower) = (*tower)->next;
	(*tower)->prev = NULL;
	while (last_room->next != NULL)
		last_room = last_room->next;
	first_room->prev = last_room;
	first_room->next = NULL;
	last_room->next = first_room;
}

void	rota_a(t_stack **tower)
{
	rota(tower);
	write(1, "ra\n", 3);
}

void	rota_b(t_stack **tower)
{
	rota(tower);
	write(1, "rb\n", 3);
}

void	rota_all(t_stack **tower_a, t_stack **tower_b)
{
	rota(tower_a);
	rota(tower_b);
		write(1, "rr\n", 3);
}