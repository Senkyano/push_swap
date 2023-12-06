/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:51:13 by rihoy             #+#    #+#             */
/*   Updated: 2023/12/05 14:47:57 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

void	rotate_pile(t_pile **pile)
{
	t_pile	*case_curr;
	t_pile	*last_case;

	case_curr = *pile;
	last_case = *pile;
	*pile = case_curr->next;
	if (last_case->next == NULL || *pile == NULL)
		return ;
	while (last_case->next != NULL)
		last_case = last_case->next;
	last_case->next = case_curr;
	case_curr->next = NULL;
}

void	rotate_all(t_pile **pile_a, t_pile **pile_b)
{
	rotate_pile(pile_a);
	rotate_pile(pile_b);
}