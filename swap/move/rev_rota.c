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
		first_box = first_box->next;
	last_box = first_box->prev;
	last_box->next = NULL;
	first_box->next = (*box);
	first_box->prev = NULL;
	(*box)->prev = first_box;
	(*box) = first_box;
}

void	rev_rota_a(t_stack **box)
{
	rev_rota(box);
	write(1, "rra\n", 4);
}

void	rev_rota_b(t_stack **box)
{
	rev_rota(box);
	write(1, "rrb\n", 4);
}

void	rev_rota_all(t_stack **a, t_stack **b)
{
	rev_rota(a);
	rev_rota(b);
	write(1, "rrr\n", 4);
}
