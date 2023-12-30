/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sec_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:35:15 by rihoy             #+#    #+#             */
/*   Updated: 2023/12/29 18:42:22 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swaplib.h"

int	min_half(t_stack **a, int half)
{
	t_stack	*curr;

	curr = *a;
	while (curr)
	{
		if (curr->nbr < half)
			return (1);
		curr = curr->next;
	}
	return (0);
}

int	chunk_diss(t_stack **a, t_stack **b, t_ref ref, int rev)
{
	push_to(a, b);
	if ((*b)->nbr > ref.tab[ref.ind_mid])
	{
		if ((*b)->next)
			rota_pile(b);
		rev++;
	}
	return (rev);
}
