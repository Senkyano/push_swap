/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:46:30 by rihoy             #+#    #+#             */
/*   Updated: 2023/12/13 20:04:46 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swaplib.h"

void	tab_ref(t_stack **a)
{
	t_stack	*min;
	t_stack	*curr;
	t_stack	*tmp;
	
	curr = *a;
	min = *a;
	tmp = NULL;
	while (trie)
	{
		curr = *a;
		while (curr)
		{
			if (curr->nbr < min->nbr)
				min = curr;
			curr = curr->next;
		}
		if (!tmp)
			tmp = min;
		tmp->ref = min;
		tmp = tmp->ref;
	}
	
}

t_stack	*mid_pos(t_stack **a)
{
	int median;
	t_stack	*mid;

	mid = *a;
	median = nbr_box(a) / 2;
	while (median)
	{
		mid = mid->next;
		median--;
	}
	return (mid);
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
