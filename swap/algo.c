/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:26:05 by rihoy             #+#    #+#             */
/*   Updated: 2023/12/20 14:02:39 by rihoy            ###   ########.fr       */
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

void	sort_mid(t_stack **a, t_stack **b)
{
	t_stack	*mid;
	t_ref	ref;
	int		i;

	while (nbr_box(a) > 3)
	{
		i = 0;
		ref = sort_ref(tab_reference(a));
		if (!ref.tab)
			error_algo(a, b);
		mid = mid_pos_ref(a, ref);
		while (nbr_box(a) > 3 && hightest(a, mid) == 0)
		{
			if ((*a)->nbr < mid->nbr)
				i = chunk_creator(a, b, ref, i);
			else
				rota_a(a);
		}
		while (i-- > 0)
			rev_rota_b(b);
		free(ref.tab);
	}
	sort_three(a);
}

int	chunk_creator(t_stack **a, t_stack **b, t_ref ref, int i)
{
	t_stack	*curr;

	push_to_b(a, b);
	curr = *b;
	if (curr->nbr > ref.tab[ref.size / 4] && nbr_box(b) != 1)
	{
		rota_b(b);
		i++;
	}
	return (i);
}

void	sort_more(t_stack **a, t_stack **b)
{
	sort_mid(a, b);
}
