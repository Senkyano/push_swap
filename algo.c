/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:26:05 by rihoy             #+#    #+#             */
/*   Updated: 2023/12/30 17:55:51 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swaplib.h"

void	sort_three(t_stack **a)
{
	t_stack	*sec;
	t_stack	*fst;

	fst = *a;
	sec = fst->next;
	if (fst->nbr > sec->nbr && fst->nbr < sec->next->nbr)
		swap_pile(a);
	else if (sec->nbr < fst->nbr)
		rota_pile(a);
	else if (sec->nbr > fst->nbr && sec->nbr > sec->next->nbr)
		rev_rota_pile(a);
	if (!trie_ok(a))
		sort_three(a);
	else
		return ;
}

void	mk_tab(t_stack **a, t_stack **b)
{
	int	rota;

	rota = 0;
	while ((*b))
	{
		while ((*a)->nbr < (*b)->nbr)
		{
			rota_pile(a);
			rota++;
		}
		push_to(b, a);
		while (rota > 0)
		{
			rev_rota_pile(a);
			rota--;
		}
	}
}// A garde

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

void	dissection(t_stack **a, t_stack **b, t_ref ref, t_data data)
{
	int	rev = 0;
	ref = first_half(ref);
	data.inception++;
	while (min_half(a, ref.tab[ref.end_taff]) && nbr_box(a) > 3)
	{
		if ((*a)->nbr < ref.tab[ref.end_taff])
			rev = chunk_diss(a, b, ref, rev);
		else
			rota_pile(a);
	}
	while (rev-- > 0)
		rev_rota_pile(b);
	if (nbr_box(a) > 3)
		dissection(a, b, ref, data);
	if (nbr_box(a) == 3)
	{
		sort_three(a);
		reintegration(b, a, ref);
		printf("---- %d ----\n", data.inception);
		printf("| %d | end tab\n",ref.tab[ref.end_taff]);
		printf("| %d | mid tab\n",ref.tab[ref.ind_mid]);
		printf("| %d | start tab\n", ref.tab[ref.start_taff]);
		printf("| %d | size tab\n", ref.non_taff);
		printf("---- %d ----\n", data.inception);
	}
	else if (ref.non_taff == ref.size / 2)
	{
		// reintegration(b, a, ref);
		printf("---- %d ----\n", data.inception);
		printf("| %d | end tab\n",ref.tab[ref.end_taff]);
		printf("| %d | mid tab\n",ref.tab[ref.ind_mid]);
		printf("| %d | start tab\n", ref.tab[ref.start_taff]);
		printf("| %d | size tab\n", ref.non_taff);
		printf("---- %d ----\n", data.inception);
		printf("ok\n");
	}
	else
	{
		reintegration(b, a, ref);
		printf("---- %d ----\n", data.inception);
		printf("| %d | end tab\n",ref.tab[ref.end_taff]);
		printf("| %d | mid tab\n",ref.tab[ref.ind_mid]);
		printf("| %d | start tab\n", ref.tab[ref.start_taff]);
		printf("| %d | size tab\n", ref.non_taff);
		printf("---- %d ----\n", data.inception);
	}
}

void	reintegration(t_stack **from, t_stack **to, t_ref ref)
{
	int	i;

	i = 0;
	while (i++ < ref.non_taf)
	{
		if ((*from)->nbr >= ref.tab[ref.ind_mid])
			push_to(from, to);
		else
			rota_pile(from);
	}
	while ()
		rev_rota(from);
	if (ref.non_taff == 1)
		only_a(from, to);
}

void	only_a(t_stack **from, t_stack **to)
{
	if ((*from)->pile == 'b')
	{
		push_to(from, to);
		if ((*to)->nbr > (*to)->next->nbr)
			swap_pile(to);
	}
}

void	chunk_split(t_stack **from, t_stack **to, t_ref ref)
{
	if ((*from)->nbr >= ref.tab[ref.ind_mid])
	{
		push_to(from, to);
		if ((*from)->nbr < ref.tab[ref.ind_mid + (ref.non_taff / 2)])
			rota_pile(to);
	}
	else
		rota_pile(from);
}