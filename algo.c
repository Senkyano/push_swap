/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:49:32 by rihoy             #+#    #+#             */
/*   Updated: 2023/12/07 12:04:32 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

void	algo(t_pile **pile_a, t_pile **pile_b, int sizecase)
{
	t_pile	*curr;

	curr = *pile_a;
	if (check_value(pile_a))
		return ;
	else if (sizecase == 2)
		swap_q(pile_a);
	else if (sizecase == 3)
		while (!check_value(pile_a))
		three_case(pile_a, pile_b, sizecase);
	else if (sizecase > 3)
		return ;
}

void	three_case(t_pile **pile_a, t_pile **pile_b, int sizecase)
{
	t_pile	*first;
	t_pile	*sec;

	first = *pile_a;
	sec = first->next;
	if (first->num > sec->num && first->num < sec->next->num)
		swap_q(pile_a);
	else if (first->num > sec->next->num && first->num > sec->num)
		rota(pile_a);
	else
		rev_rota(pile_a);
}