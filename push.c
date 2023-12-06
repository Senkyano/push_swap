/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:40:47 by rihoy             #+#    #+#             */
/*   Updated: 2023/12/05 14:28:01 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

void	push_case(t_pile **pile_curr, t_pile **pile_to)
{
	t_pile	*case_curr;
	t_pile	*new_curr;
	
	case_curr = *pile_curr;
	new_curr = case_curr->next;
	*pile_curr = new_curr;
	if (*pile_to == NULL)
	{
		case_curr->next = NULL;
		*pile_to = case_curr;
		return ;
	}
	case_curr->next = *pile_to;
	*pile_to = case_curr;
}
