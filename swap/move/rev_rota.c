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

#include "../swaplib.h"

void	rev_rota(t_stack **box)
{
	t_stack *first_box;
	t_stack	*last_box;

	if ((*box)->next == NULL || (*box) == NULL)
		return ;
	first_box = *box;
	while (first_box->next != NULL)
	{
		last_box = first_box;
		first_box = first_box->next;
	}
	last_box->next = NULL;
	first_box->next = (*box);
	(*box) = first_box;
}

void	rev_rota_pile(t_stack **box)
{
	if ((*box)->next || (*box))
	{
		rev_rota(box);
		action("rr", (*box)->pile);
	}
}

// void	rev_rota_b(t_stack **box)
// {
// 	rev_rota(box);
// 	write(1, "rrb\n", 4);
// }

void	rev_rota_all(t_stack **a, t_stack **b)
{
	if (((*a)->next || (*a)) && ((*b)->next || (*b)))
	{
		rev_rota(a);
		rev_rota(b);
		write(1, "rrr\n", 4);
	}
}
