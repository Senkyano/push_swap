/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:26:05 by rihoy             #+#    #+#             */
/*   Updated: 2024/01/06 19:26:49 by rihoy            ###   ########.fr       */
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
	else if (ref.non_taff <= 4)
		trie_four(from, to, ref);
	// else
	// 	all_for(from, to, ref);
}

void	trie_four(t_stack **from, t_stack **to, t_ref ref)
{
	int	i;
	int	rota;

	i = 0;
	rota = 0;
	while (i++ < ref.non_taff)
	{
		only_a(from, to);
		if ((*to)->nbr < ref.tab[ref.ind_mid])
		{
			rota_pile(to);
			rota++;
		}
	}
	while (rota-- > 0)
	{
		rev_rota_pile(to);
		only_a(to, from);
	}
}

t_ref	mid_supsup(t_ref ref)
{
	t_ref	refsupsup;

	refsupsup.start_taff = ref.ind_mid + ((ref.end_taff - ref.ind_mid) / 2);
	refsupsup.non_taff = ref.end_taff - refsupsup.start_taff;
	refsupsup.ind_mid = refsupsup.start_taff + refsupsup.non_taff / 2;
	printf("| %d | end_taff supsup\n", ref.tab[ref.end_taff]);
	printf("| %d | mid supsup\n", ref.tab[refsupsup.ind_mid]);
	printf("| %d | start_taff supsup\n", ref.tab[refsupsup.start_taff]);
	printf("| %d | non_taff supsup\n", refsupsup.non_taff);
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
// 	// t_ref	fst;
// 	// t_ref	sec;
// 	// t_ref	thr;
// 	// t_data	dt;

// 	// mid_supsup(ref);
// 	// mid_suplow(ref);
// 	// mid_lower(ref);
// 	// dt = cuting_part(from, to, ref);
// 	// printf("%d rotafrom, %d rota_to \n", dt.rota_from, dt.rota_to);
// 	// reintegration(to, from, fst);
// 	// ecomove(from, to, dt);
// // 	reintegration(to, from, sec);
// // 	reintegration(from, to, thr);
// }

void	ecomove(t_stack **from, t_stack **to, t_data dt)
{
	while (dt.rota_from-- > 0 && dt.rota_from-- > 0)
		rev_rota_all(from, to);
	while (dt.rota_to-- > 0)
		rev_rota_pile(to);
	while (dt.rota_from-- > 0)
		rev_rota_pile(from);
}

// t_data	cuting_part(t_stack **from, t_stack **to, t_ref ref)
// {

// }

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
