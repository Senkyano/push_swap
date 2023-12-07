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
	{
		if (curr->num > curr->next->num && curr->num < curr->next->next->num)
			swap_q(pile_a);
		else if (curr->num < curr->next->num && curr->num > curr->next->next->num)
			rev_rota(pile_a);
		else if (curr->num > curr->next->num && curr->num > curr->next->next->num)
			rota(pile_a);
	}
	else if (sizecase > 3)
		return ;
}

// void	algomore(t_pile **pile_a, t_pile **pile_b)
// {
// 	if (check_value(pile_a) && number_case(pile_b) == 0)
// 		return ;
// 	else if ()
// }
