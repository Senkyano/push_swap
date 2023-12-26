/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:26:05 by rihoy             #+#    #+#             */
/*   Updated: 2023/12/26 18:30:19 by rihoy            ###   ########.fr       */
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

// void	sort_algo(t_stack **a, t_stack **b)
// {
// 	t_stack	*min;
// 	t_stack	*curr;
// 	int	cost_min;
// 	int	cost;

// 	send_mid(a, b);
// 	while (b)
// 	{
// 		curr =  *b;
// 		cost_min = INT_MAX;
// 		while (curr)
// 		{
// 			cost = cost_way(a, b, curr);
// 			if (cost < cost_min)
// 			{
// 				min = curr;
// 				cost_min = cost;
// 			}
// 			curr = curr->next;
// 		}
// 		do_best_cost(a, b, min);
// 	}
// }

// void	send_mid(t_stack **a, t_stack **b)
// {
// 	t_ref	ref;
// 	int		i;

// 	while (nbr_box(a) > 3)
// 	{
// 		i = 0;
// 		ref = sort_ref(tab_reference(a));
// 		if (!ref.tab)
// 			error_algo(a, b);
// 		while (min_half(a, ref.tab[ref.size / 2]) && nbr_box(a) > 3)
// 		{
// 			if ((*a)->nbr < ref.tab[ref.size / 2])
// 				i = chunk_creator(a, b, ref, i);
// 			else
// 				rota_a(a);
// 		}
// 		while (i-- > 0)
// 			rev_rota_b(b);
// 		free(ref.tab);
// 	}
// 	sort_three(a);
// }

// int	chunk_creator(t_stack **a, t_stack **b, t_ref ref, int i)
// {
// 	push_to_b(a, b);
// 	if ((*b)->nbr > ref.tab[ref.size / 4] && (*b)->next)
// 	{
// 		rota_b(b);
// 		i++;
// 	}
// 	return (i);
// }

////////////////////////////////////////////
////////////////////////////////////////////
////////////////////////////////////////////

// void	smart_push(t_stack **a, t_stack **b)
// {
// 	if ((*b)->nbr > (*a)->nbr)
// 	{
// 		rota_a(a);
// 		push_to_a(b, a);
// 		rev_rota_a(a);
// 	}
// 	else
// 		push_to_a(b, a);
// }

void	half_part(t_stack **a, t_stack **b, t_data data)
{
	t_ref	ref;
	t_ref	mkref;

	data.i = 0;
	data.size = 0;
	data.inception++;
	ref = sort_ref(tab_reference(a));
	while (min_half(a, ref.tab[ref.size / 2]) && nbr_box(a) > 3)
	{
		if ((*a)->nbr < ref.tab[ref.size / 2])
			data = separator_b(a, b, ref, data);
		else
			rota_a(a);
	}
	while (data.i-- > 0)
		rev_rota_b(b);
	if (nbr_box(a) > 3) // C'est que si il y a plus de 3 case dans a pour ne pas rentre
		half_part(a, b, data); // 1 fois de trop dans la recursivite
	if (nbr_box(a) == 3)
		sort_three(a);
	mkref = sort_ref(mk_ref(a, b, data.size));
	// mk_tab(a, b);
	free(mkref.tab);
	free(ref.tab);
}
// // je dois avoir une autre fonction qui dois sappellais aussi en recursivite pour
// // trier de b vers a et puis encore linverse pour des petites fonctions.
// // Comme je garde a chaque fois la taille je peux plus facilement manipule
// // pour prendre juste les 2 nombres a chaque fois et les place dans l'ordre

// // Faire un partionnement en fonction de si elle est plus grande que la medianne
// // Ou plus petite que la medianne de la moitier du tableau de reference

void	mk_tab(t_stack **a, t_stack **b)
{
	int	rota;

	rota = 0;
	while ((*b))
	{
		while ((*a)->nbr < (*b)->nbr)
		{
			rota_a(a);
			rota++;
		}
		push_to_a(b, a);
		while (rota > 0)
		{
			rev_rota_a(a);
			rota--;
		}
	}
}// A garde


// t_data	separotor_a(t_stack **a, t_stack **b, t_ref ref, t_data data)
// {
	
// }

t_data	separator_b(t_stack **a, t_stack **b, t_ref ref, t_data data)
{
	data.size++;
	push_to_b(a, b);
	if ((*b)->nbr > ref.tab[ref.size / 4])
	{
		if ((*b)->next)
			rota_b(b);
		data.i++;
	}
	return (data);
}

t_ref	mk_ref(t_stack **a, t_stack **b, int size)
{
	t_stack	*curr;
	t_ref	mkref;
	int		i;

	mkref.tab = malloc(sizeof(int) * size);
	if (!mkref.tab)
		error_algo(a, b);
	i = 0;
	mkref.size = size;
	curr = *b;
	while (i < mkref.size)
	{
		mkref.tab[i] = curr->nbr;
		if (curr->next)
			curr = curr->next;
		i++;
	}
	return (mkref);
}

// void	print_ref(t_ref ref)
// {
// 	int	i;

// 	i = 0;
// 	while (i < ref.size)
// 	{
// 		printf("%d i = %d\n", ref.tab[i], i);
// 		i++;
// 	}
// 	printf("\n");
// }

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

void	sission(t_stack **a, t_stack **b, t_ref ref, int inception, int decoupe)
{
	int	power;
	int	rev_rota;

	rev_rota = 0;
	printf("%d entre inception\n",inception);
	power = sec_power(inception, 2);
	decoupe = decoupe + (ref.size / power) - 1;
	while (decoupe < ref.size && min_half(a, ref.tab[decoupe]) && nbr_box(a) > 3)
	{
		if ((*a)->nbr < ref.tab[decoupe])
			rev_rota += chunk(a, b, ref, decoupe, (ref.size / power) / 2);
		else
			rota_a(a);
	}
	while (rev_rota-- > 0)
		rev_rota_b(b);
	inception++;
	printf("%d decoupe\n", decoupe);
	if (nbr_box(a) > 3)
		sission(a, b, ref, inception, decoupe);
	if (nbr_box(a) == 3)
		sort_three(a);
	printf("%d decoupe\n", decoupe);
	printf("%d sortie inception\n",inception);
}

int	chunk(t_stack **a, t_stack **b, t_ref ref, int decoupe, int half)
{
	int	i;

	i = 0;
	push_to_b(a, b);
	if ((*b)->nbr >= ref.tab[decoupe - half])
	{
		if ((*b)->next)
			rota_b(b);
		i++;
	}
	return (i);
}

int	sec_power(int n, int nbr)
{
	int	pow;

	pow = nbr;
	while (n-- > 1)
		nbr = nbr * pow;
	return (nbr);
}

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

void	dissection(t_stack **a, t_stack **b, t_ref ref, t_data data)
{
	int	rev;

	data.inception++;
	printf("%d entre\n", data.inception);
	rev = 0;
	data.i = ref.size - (ind_half(ref, data.i) / 2);
	while (min_half(a, ref.tab[data.i]) && nbr_box(a) > 3)
	{
		if ((*a)->nbr < ref.tab[data.i])
			rev = chunk_diss(a, b, ref, data.i, rev);
		else
			rota_a(a);
	}
	while (rev-- > 0)
		rev_rota_b(b);
	if (nbr_box(a) > 3)
		dissection(a, b, ref, data);
	if (nbr_box(a) == 3)
		sort_three(a);
	data.j = ind_half(ref, data.i) / 2;
	printf("%d size tab\n", (ind_half(ref, data.i)));
	printf("%d nbr mid\n", ref.tab[data.i - data.j]);
	printf("%d nbr start\n", ref.tab[data.i - ind_half(ref, data.i)]);
	printf("%d index half for a\n", data.i);
	printf("%d sortie \n", data.inception);
}

int	chunk_diss(t_stack **a, t_stack **b, t_ref ref, int i, int rev)
{
	i = (ind_half(ref, i) / 2);
	push_to_b(a, b);
	if ((*b)->nbr > ref.tab[i])
	{
		if ((*b)->next)
			rota_b(b);
		rev++;
	}
	return (rev);
}

int	ind_half(t_ref ref, int ind)
{
	int	i;

	i = 0;
	while (ind++ < ref.size)
		i++;
	return (i);
}
