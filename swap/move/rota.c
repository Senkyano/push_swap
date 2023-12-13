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

#include "../swaplib.h"

void	rota(t_stack **box)
{
	t_stack	*first_box;
	t_stack	*last_box;

	if ((*box) == NULL)
		return ;
	first_box = (*box);
	last_box = (*box);
	(*box) = (*box)->next;
	(*box)->prev = NULL;
	while (last_box->next != NULL)
		last_box = last_box->next;
	first_box->prev = last_box;
	first_box->next = NULL;
	last_box->next = first_box;
}

void	rota_a(t_stack **box)
{
	rota(box);
	write(1, "ra\n", 3);
}

void	rota_b(t_stack **box)
{
	rota(box);
	write(1, "rb\n", 3);
}

void	rota_all(t_stack **a, t_stack **b)
{
	rota(a);
	rota(b);
		write(1, "rr\n", 3);
}