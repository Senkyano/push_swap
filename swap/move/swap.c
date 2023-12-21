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

#include "../swaplib.h"

void	swap(t_stack **box)
{
	t_stack	*first;
	t_stack	*sec;
	t_stack	*third;

	if ((*box) == NULL)
		return ;
	first = *box;
	sec = first->next;
	third = sec->next;
	if (third != NULL)
		third->prev = first;
	first->next = third;
	first->prev = sec;
	sec->next = first;
	sec->prev = NULL;
	(*box) = sec;
}

void	swap_a(t_stack **box)
{
	swap(box);
	write(1, "sa\n", 3);
}

void	swap_b(t_stack **box)
{
	swap(box);
	write(1, "sb\n", 3);
}

void	swap_all(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	write(1, "sb\n", 3);
}
