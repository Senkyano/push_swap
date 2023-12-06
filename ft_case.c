/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 09:49:34 by rihoy             #+#    #+#             */
/*   Updated: 2023/12/04 15:44:49 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

void	clear_pile(t_pile **pile)
{
	t_pile	*curr_case;
	t_pile	*pre_case;

	curr_case = *pile;
	while (curr_case != NULL)
	{
		pre_case = curr_case;
		curr_case = curr_case->next;
		del_case(pre_case);
	}
	*pile = NULL;
}

void	del_case(t_pile *case_curr)
{
	if (!case_curr)
		return ;
	free(case_curr);
}

t_pile	*new_case(int	content)
{
	t_pile		*num;

	num = malloc(sizeof(t_pile));
	if (!num)
		return (NULL);
	num->num = content;
	num->next = NULL;
	return (num);
}

void	add_case(t_pile **pile, t_pile *last_case)
{
	t_pile *first_case;

	if (*pile == NULL)
	{
		*pile = last_case;
		return ;
	}
	first_case = *pile;
	while (first_case->next != NULL)
		first_case = first_case->next;
	first_case->next = last_case;
}
