/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rota.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:01:05 by rihoy             #+#    #+#             */
/*   Updated: 2023/12/05 14:47:27 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

void	rev_rota(t_pile **pile)
{
	t_pile	*first_case;
	t_pile	*last_case;

	last_case = *pile;
	if (last_case->next == NULL || *pile == NULL)
		return ;
	last_case = *pile;
	while (last_case->next->next != NULL)
		last_case = last_case->next;
	first_case = last_case->next;
	last_case->next = NULL;
	first_case->next = *pile;
	*pile = first_case;
}

void	rev_rotall(t_pile **pile_a, t_pile **pile_b)
{
	rev_rota(pile_a);
	rev_rota(pile_b);
}
