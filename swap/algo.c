/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:26:05 by rihoy             #+#    #+#             */
/*   Updated: 2023/12/13 17:25:04 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swaplib.h"

void	sort_three(t_stack **a)
{
	t_stack	*sec;
	t_stack	*fst;

	if (!(*a))
		return ;
	fst = *a;
	sec = fst->next;
	if (fst->nbr > sec->nbr && fst->nbr < sec->next->nbr)
		swap_a(a);
	else if (fst->nbr > sec->nbr && fst->nbr > sec->next->nbr)
		rota_a(a);
	else if (sec->nbr > fst->nbr && sec->nbr > sec->next->nbr)
		rev_rota_a(a);
	if (!trie_ok(a))
		sort_three(a);
}

void	more_than_three(t_stack **a, t_stack **b)
{
	three_for_a(a, b);
}

void	three_for_a(t_stack **a, t_stack **b)
{
	t_stack	*mid;

	while (nbr_box(a) > 3)
	{
		mid = mid_pos(a);
		while (nbr_box(a) > 3 && hightest(a, mid) == 0)
		{
			if ((*a)->nbr < mid->nbr)
				push_to_b(a, b);
			else
				rota_a(a);
		}
	}
	sort_three(a);
}
