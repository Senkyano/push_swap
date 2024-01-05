/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:26:05 by rihoy             #+#    #+#             */
/*   Updated: 2024/01/05 18:34:50 by rihoy            ###   ########.fr       */
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
		printf("\n");
		printf("---- other ----\n");
		mid_supsup(ref);
		mid_suplow(ref);
		mid_lower(ref);
		printf("---- other ----\n");
		printf("\n");
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
		printf("\n");
		printf("---- other ----\n");
		mid_supsup(ref);
		mid_suplow(ref);
		mid_lower(ref);
		printf("---- other ----\n");
		printf("\n");
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
		printf("\n");
		printf("---- other ----\n");
		mid_supsup(ref);
		mid_suplow(ref);
		mid_lower(ref);
		printf("---- other ----\n");
		printf("\n");
		reintegration(b, a, ref);
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
	else if (ref.non_taff <= 4 && (*from)->pile == 'a')
		trie_a(from, to, ref);
	else if (ref.non_taff <= 4 && (*from)->pile == 'b')
		trie_b(from, to, ref);
	// else
	// 	all_for(from, to, ref);
}

void	trie_a(t_stack **from, t_stack **to, t_ref ref)
{
	int	i;
	int	rot;

	i = 0;
	while (i++ < ref.non_taff)
	{
		if ((*from)-> nbr < ref.tab[ref.ind_mid])
			push_to(from, to);
		else if (i < ref.non_taff - 1)
		{
			rota_pile(from);
			rot++;
		}
	}
	ref.non_taff = ref.non_taff - rot;
	while (rot-- > 0)
		rev_rota_pile(from);
	if ((*from)->nbr > (*from)->next->nbr)
		swap_pile(from);
	reintegration(to, from, ref);
}

void	trie_b(t_stack **from, t_stack **to, t_ref ref)
{
	int	i;
	int	rot;

	rot = 0;
	i = 0;
	while (i++ < ref.non_taff)
	{
		push_to(from, to);
		if ((*to)->nbr < ref.tab[ref.ind_mid])
		{
			rota_pile(to);
			rot++;
		}
	}
	ref.non_taff = ref.non_taff - rot;
	reintegration(to, from, ref);
	ref.non_taff = rot;
	while (rot-- > 0)
		rev_rota_pile(to);
	reintegration(to, from, ref);
}

t_ref	mid_supsup(t_ref ref)
{
	t_ref	refsupsup;

	refsupsup.start_taff = ref.ind_mid + ((ref.end_taff - ref.ind_mid) / 2);
	refsupsup.non_taff = ref.end_taff - refsupsup.start_taff;
	refsupsup.ind_mid = refsupsup.start_taff + refsupsup.non_taff / 2;
	printf("| %d | end_taff suplow\n", ref.tab[ref.end_taff]);
	printf("| %d | mid suplow\n", ref.tab[refsupsup.ind_mid]);
	printf("| %d | start_taff suplow\n", ref.tab[refsupsup.start_taff]);
	printf("| %d | non_taff suplow\n", refsupsup.non_taff);
	return (refsupsup);
}

t_ref	mid_suplow(t_ref ref)
{
	t_ref	refsuplow;
	
	refsuplow.start_taff = ref.ind_mid;
	refsuplow.end_taff = ref.ind_mid + ((ref.end_taff - ref.ind_mid) / 2);
	refsuplow.non_taff = refsuplow.end_taff - refsuplow.start_taff;
	refsuplow.ind_mid = refsuplow.start_taff + refsuplow.non_taff / 2;
	printf("| %d | end_taff suplow\n", ref.tab[refsuplow.end_taff]);
	printf("| %d | mid suplow\n", ref.tab[refsuplow.ind_mid]);
	printf("| %d | start_taff suplow\n", ref.tab[refsuplow.start_taff]);
	printf("| %d | non_taff suplow\n", refsuplow.non_taff);
	return (refsuplow);
}

t_ref	mid_lower(t_ref ref)
{
	t_ref	reflow;
	
	reflow.end_taff = ref.ind_mid;
	reflow.non_taff = ref.ind_mid - ref.start_taff;
	reflow.ind_mid = ref.start_taff + (ref.ind_mid - ref.start_taff) / 2;
	printf("| %d | end_taff low\n", ref.tab[reflow.end_taff]);
	printf("| %d | mid low\n", ref.tab[reflow.ind_mid]);
	printf("| %d | start_taff low\n", ref.tab[ref.start_taff]);
	printf("| %d | non_taff low\n", reflow.non_taff);
	return (reflow);
}

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
