/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssab.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:34:31 by rihoy             #+#    #+#             */
/*   Updated: 2023/12/05 16:10:16 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

void	swap_q(t_pile **pile)
{
	t_pile	*case_d;
	t_pile	*tmp;

	case_d = *pile;
	if (case_d->next == NULL || *pile == NULL)
		return ;
	tmp = case_d->next;
	case_d->next = tmp->next;
	tmp->next = case_d;
}

void	swap_s(t_pile **pile_a, t_pile **pile_b)
{
	swap_q(pile_a);
	swap_q(pile_b);
}
