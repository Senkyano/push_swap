/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 20:22:03 by marvin            #+#    #+#             */
/*   Updated: 2023/12/08 20:22:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

int	lowest_pos(t_pile **pile_a, int case_b)
{
	int	cost;
	t_pile	**curr;

	curr = *pile_a;
	cost = 0;
	while (curr->num < case_b)
	{
		curr = curr->next;
		cost++;
	}
	return (number_case(pile_a) - cost);
}


