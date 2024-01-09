/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:26:05 by rihoy             #+#    #+#             */
/*   Updated: 2024/01/09 13:21:07 by rihoy            ###   ########.fr       */
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

void	dissection(t_stack **a, t_stack **b, t_ref ref)
{
	ref = first_half(ref);
	if (ref.non_taff == ref.size / 2 || ref.non_taff == ref.size / 2 - 1)
		before_mid(a, b, ref);
	else
		after_mid(a, b, ref);
	if (nbr_box(a) > 3)
		dissection(a, b, ref);
	if (nbr_box(a) == 3)
	{
		sort_three(a);
		reintegration(b, a, ref);
	}
	else if (ref.non_taff == ref.size / 2 - 1 || ref.non_taff == ref.size / 2)
	{
		// new ref;
		// reintegration(b, a, ref);
		// new ref; 
		// reintegration(b, a, ref);
		mid_supsup(ref);
		mid_suplow(ref);
		mid_lower(ref);
		printf("--------------------------\n");
		printf("| %d | end tab\n",ref.tab[ref.end_taff - 1]);
		printf("| %d | mid tab\n",ref.tab[ref.ind_mid]);
		printf("| %d | start tab\n", ref.tab[ref.start_taff]);
		printf("| %d | size tab\n", ref.non_taff);
		printf("--------------------------\n");
	}
	else
		reintegration(b, a, ref);
}

void	before_mid(t_stack **a, t_stack **b, t_ref ref)
{
	while (min_half(a, ref.tab[ref.end_taff]))
	{
		if ((*a)->nbr < ref.tab[ref.end_taff])
			chunk_diss_bis(a, b, ref);
		else
			rota_pile(a);
	}
}

void	chunk_diss_bis(t_stack **a, t_stack **b, t_ref ref)
{
	push_to(a, b);
	if ((*b)->nbr < ref.tab[ref.ind_mid])
	{
		if ((*b)->next)
			rota_pile(b);
	}
}

void	after_mid(t_stack **a, t_stack **b, t_ref ref)
{
	int	rev;

	rev = 0;
	while (min_half(a, ref.tab[ref.end_taff]) && nbr_box(a) > 3)
	{
		if ((*a)->nbr < ref.tab[ref.end_taff])
			rev = chunk_diss(a, b, ref, rev);
		else
			rota_pile(a);
	}
	while (rev-- > 0)
		rev_rota_pile(b);
}

void	reintegration(t_stack **from, t_stack **to, t_ref ref)
{
	int	i;

	i = 0;
	if (ref.non_taff <= 2)
	{
		while (i++ < ref.non_taff)
			only_a(from, to);
	}
	else if (ref.non_taff > 2)
		all_for(from, to, ref);
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

	refsupsup = ref;
	refsupsup.start_taff = ref.ind_mid + ((ref.end_taff - ref.ind_mid) / 2);
	refsupsup.non_taff = ref.end_taff - refsupsup.start_taff;
	refsupsup.ind_mid = refsupsup.start_taff + (refsupsup.non_taff / 2);
	refsupsup.end_taff = ref.end_taff;
	if(ref.non_taff == 50 || ref.non_taff == 49)
	{
		printf("| %d | end_taff supsup\n", ref.tab[refsupsup.end_taff]);
		printf("| %d | mid supsup\n", ref.tab[refsupsup.ind_mid]);
		printf("| %d | start_taff supsup\n", ref.tab[refsupsup.start_taff]);
		printf("| %d | non_taff supsup\n", refsupsup.non_taff);
	}
	return (refsupsup);
}

t_ref	mid_suplow(t_ref ref)
{
	t_ref	refsuplow;
	
	refsuplow = ref;
	refsuplow.start_taff = ref.ind_mid;
	refsuplow.end_taff = (ref.ind_mid) + ((ref.end_taff - ref.ind_mid) / 2);
	refsuplow.non_taff = refsuplow.end_taff - refsuplow.start_taff;
	refsuplow.ind_mid = refsuplow.start_taff + (refsuplow.non_taff / 2);
	if(ref.non_taff == 50 || ref.non_taff == 49)
	{
		printf("| %d | end_taff suplow\n", ref.tab[refsuplow.end_taff]);
		printf("| %d | mid suplow\n", ref.tab[refsuplow.ind_mid]);
		printf("| %d | start_taff suplow\n", ref.tab[refsuplow.start_taff]);
		printf("| %d | non_taff suplow\n", refsuplow.non_taff);
	}
	return (refsuplow);
}

t_ref	mid_lower(t_ref ref)
{
	t_ref	reflow;
	
	reflow = ref;
	reflow.end_taff = ref.ind_mid;
	reflow.non_taff = ref.ind_mid - ref.start_taff;
	reflow.ind_mid = ref.start_taff + (ref.ind_mid - ref.start_taff) / 2;
	reflow.start_taff = ref.start_taff;
	if(ref.non_taff == 50 || ref.non_taff == 49)
	{
		printf("| %d | end_taff low\n", ref.tab[reflow.end_taff]);
		printf("| %d | mid low\n", ref.tab[reflow.ind_mid]);
		printf("| %d | start_taff low\n", ref.tab[reflow.start_taff]);
		printf("| %d | non_taff low\n", reflow.non_taff);
	}
	return (reflow);
}

void	all_for(t_stack **from, t_stack **to, t_ref ref)
{
	t_ref	fst;
	t_ref	sec;
	t_ref	thr;

	fst = mid_supsup(ref);
	sec = mid_suplow(ref);
	thr = mid_lower(ref);
	cuting_part(from, to, ref);
	reintegration(to, from, fst);
	if ((*from)->pile == 'b')
	{
		ecomove(from, to, sec, thr);
		reintegration(to, from, sec);
		reintegration(from, to, thr);
	}
	else if ((*from)->pile == 'a')
	{
		do_move(to, sec);
		reintegration(to, from, sec);
		do_move(from, thr);
		reintegration(from, to, thr);
	}
}

void	do_move(t_stack	**from, t_ref ref)
{
	while (ref.non_taff-- > 0)
		rev_rota_pile(from);
}

void	ecomove(t_stack **from, t_stack **to, t_ref	sec, t_ref thr)
{
	while (sec.non_taff-- > 0 && thr.non_taff-- > 0)
		rev_rota_all(from, to);
	while (sec.non_taff-- > 0)
		rev_rota_pile(to);
	while (thr.non_taff-- > 0)
		rev_rota_pile(from);
}

void	cuting_part(t_stack **from, t_stack **to, t_ref ref)
{
	int	i;
	int	midsup;

	i = 0;
	midsup = ref.ind_mid + ((ref.end_taff - ref.ind_mid) / 2);
	while (i++ < ref.non_taff)
	{
		if ((*from)->nbr >= ref.tab[ref.ind_mid])
		{
			push_to(from, to);
			if ((*to)->nbr < ref.tab[midsup] && (*from)->nbr < ref.tab[ref.ind_mid]
				&& i < ref.non_taff - 1)
			{
				rota_all(from, to);
				i++;
			}
			else if ((*to)->nbr < ref.tab[midsup])
				rota_pile(to);
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
