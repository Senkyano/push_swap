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

#include "swaplib.h"

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
	first->next = third;
	sec->next = first;
	(*box) = sec;
}

void	swap_pile(t_stack **box)
{
	if ((*box)->next && (*box))
	{
		swap(box);
		action("s", (*box)->pile);
	}
}

// void	swap_b(t_stack **box)
// {
// 	swap(box);
// 	write(1, "sb\n", 3);
// }

void	swap_all(t_stack **a, t_stack **b)
{
	if (((*a)->next || (*a)) && ((*b)->next || (*b)))
	{
		swap(a);
		swap(b);
		write(1, "ss\n", 3);
	}
}
