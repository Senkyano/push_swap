/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:46:30 by rihoy             #+#    #+#             */
/*   Updated: 2023/12/14 18:42:05 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swaplib.h"

t_ref	*tab_reference(t_stack **a)
{
	t_ref	ref;
	t_stack	*curr;
	t_data	ind;

	ref.size = nbr_box(a);
	ref.tab = malloc(sizeof(int) * ref.size);
	if (!ref)
		return (-1);
	ind.i = 0;
	curr = *a;
	while (curr && ind.i < ref.size)
	{
		ref.tab[ind.i++] = curr->nbr;
		curr = curr->next;
	}
	return (ref);
}

t_ref	sort_ref(t_ref ref)
{
	t_data	*ind;
	
	ind.i = 0;
	while (i < ref.size - 1)
	{
		if (ref.tab[ind.i] > ref.tab[ind.i + 1])
		{
			ind.j = ref.tab[j];
			ref.tab[ind.i] = ref.tab[ind.i + 1];
			ref.tab[ind.i + 1] = ind.j;
			ref = sort(ref);
		}
		ind.i++;
	}
	return (ref);
}

t_stack	*mid_pos_ref(t_stack **a, t_ref ref)
{
	int	i;
	t_stack	*curr;

	curr = *a;
	while (curr)
	{
		if (curr->nbr == ref.tab[size / 2])
			return (curr);
		curr = curr->next;
	}
	return (curr);
}

bool	hightest(t_stack **a, t_stack *mid)
{
	t_stack	*curr;

	curr = *a;
	while (curr)
	{
		if (curr->nbr < mid->nbr)
			return (0);
		curr = curr->next;
	}
	return (1);
}
