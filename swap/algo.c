/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:26:05 by rihoy             #+#    #+#             */
/*   Updated: 2024/01/04 14:27:42 by rihoy            ###   ########.fr       */
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
	// int	mid;

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
		printf("---- other ----\n");
		printf("| %d | mid sup\n",ref.tab[ref.ind_mid + ((ref.end_taff + 1) - ref.ind_mid) / 2]);
		printf("---------------\n");
		printf("---- %d ----\n", data.inception);
		printf("| %d | end tab\n",ref.tab[ref.end_taff - 1]);
		printf("| %d | mid tab\n",ref.tab[ref.ind_mid]);
		printf("| %d | start tab\n", ref.tab[ref.start_taff]);
		printf("| %d | size tab\n", ref.non_taff);
		printf("---- %d ----\n", data.inception);
	}
	else if (ref.non_taff == ref.size / 2 - 1 || ref.non_taff == ref.size / 2)
	{
		// mk_tab(a, b);
		// reintegration(b, a, ref);
		printf("---- other ----\n");
		printf("| %d | mid sup\n",ref.tab[ref.ind_mid + ((ref.end_taff + 1) - ref.ind_mid) / 2]);
		printf("---------------\n");
		printf("---- %d ----\n", data.inception);
		printf("| %d | end tab\n",ref.tab[ref.end_taff - 1]);
		printf("| %d | mid tab\n",ref.tab[ref.ind_mid]);
		printf("| %d | start tab\n", ref.tab[ref.start_taff]);
		printf("| %d | size tab\n", ref.non_taff);
		printf("---- %d ----\n", data.inception);
	}
	else
	{
		// mk_tab(a, b);
		printf("---- other ----\n");
		printf("| %d | mid sup\n",ref.tab[ref.ind_mid + ((ref.end_taff + 1) - ref.ind_mid) / 2]);
		printf("---------------\n");
		// reintegration(b, a, ref);
		printf("---- %d ----\n", data.inception);
		printf("| %d | end tab\n",ref.tab[ref.end_taff - 1]);
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
	if (ref.non_taff <= 2)
		while (i++ < ref.non_taff)
			only_a(from, to);
	else if (ref.non_taff <= 4)
	else
}

void	jhin(t_stack **from, t_stack **to, t_ref ref)
{
	int	i;

	i = 0;
	if ((*from)->pile == 'a')
	{
		while 
	}
}

// t_ref	mid_supsup(t_ref ref)
// {
// 	t_ref	refsup;
	
// }

// t_ref	mid_suplow(t_ref ref)
// {
// 	t_ref	refsl;
	
// }

// t_ref	mid_lower(t_ref ref)
// {
// 	t_ref	reflow;
	
// }

// void	all_for(t_stack **from, t_stack **to, t_ref ref)
// {
	
// }

void	cuting_part(t_stack **from, t_stack **to, t_ref ref)
{
	int	i;
	int	mid_sup;

	i = 0;
	mid_sup = ref.ind_mid + ((ref.end_taff + 1) - ref.ind_mid) / 2;
	while (i++ < ref.non_taff)
	{
		if ((*from)->nbr >= ref.tab[ref.ind_mid])
		{
			push_to(from, to);
			if ((*to)->nbr < ref.tab[mid_sup])
			{
				if ((*from)->nbr < ref.tab[ref.ind_mid])
					rota_all(from, to);
				else
					rota_pile(to);
			}
		}
		else
			rota_pile(from);
	}
}

void	only_a(t_stack **from, t_stack **to)
{
	if ((*from)->pile == 'a')
	{
		if ((*from)->nbr > (*from)->next->nbr && (*to)->nbr < (*to)->next->nbr)
			swap_all(from, to);
		else if ((*from)->nbr > (*from)->next->nbr)
			swap_pile(from);
	}
	else if ((*from)->pile == 'b')
	{
		if ((*from)->next)
		{
			if ((*from)->nbr < (*from)->next->nbr
					&& (*to)->nbr > (*to)->next->nbr)
				swap_all(from, to);
			else if ((*from)->nbr < (*from)->next->nbr)
				swap_pile(from);
		}
		push_to(from, to);
		if ((*to)->nbr > (*to)->next->nbr)
			swap_pile(to);
	}
}
