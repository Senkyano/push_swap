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

#include "swaplib.h"

void	rota(t_stack **box)
{
	t_stack	*first_box;
	t_stack	*last_box;

	if ((*box) == NULL || (*box)->next == NULL)
		return ;
	first_box = (*box);
	last_box = (*box);
	(*box) = (*box)->next;
	while (last_box->next != NULL)
		last_box = last_box->next;
	first_box->next = NULL;
	last_box->next = first_box;
}

void	rota_pile(t_stack **box)
{
	if ((*box)->next || (*box))
	{
		rota(box);
		action("r", (*box)->pile);
	}
}

// void	rota_b(t_stack **box)
// {
// 	rota(box);
// 	write(1, "rb\n", 3);
// }

void	rota_all(t_stack **a, t_stack **b)
{
	rota(a);
	rota(b);
	write(1, "rr\n", 3);
}