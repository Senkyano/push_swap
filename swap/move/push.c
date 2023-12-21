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

#include "../swaplib.h"

void	push_to_a(t_stack **from, t_stack **to)
{
	t_stack *first_room;

	write(1, "pa\n", 3);
	if (!(*to))
	{
		(*to) = *from;
		(*from) = (*from)->next;
		(*from)->prev = NULL;
		(*to)->next = NULL;
		return ;
	}
	first_room = (*from);
	(*from) = (*from)->next;
	if ((*from) != NULL)
		(*from)->prev = NULL;
	first_room->next = (*to);
	(*to)->prev = first_room;
	(*to) = first_room;
}

void	push_to_b(t_stack **from, t_stack **to)
{
	t_stack *first_room;

	write(1, "pb\n", 3);
	if (!(*to))
	{
		(*to) = *from;
		(*from) = (*from)->next;
		(*from)->prev = NULL;
		(*to)->next = NULL;
		return ;
	}
	first_room = (*from);
	(*from) = (*from)->next;
	if ((*from) != NULL)
		(*from)->prev = NULL;
	first_room->next = (*to);
	(*to)->prev = first_room;
	(*to) = first_room;
}
