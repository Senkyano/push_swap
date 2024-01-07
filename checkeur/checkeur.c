/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkeur.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 00:14:50 by rihoy             #+#    #+#             */
/*   Updated: 2024/01/08 00:40:20 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checkeur.h"

int	main(void)
{
	
	// if (check == 0)
		// "error";
	// else
		// "ok";
}

int	check(t_stack **pile)
{
	t_stack	*curr;

	curr = *pile;
	while (curr->next)
	{
		if (curr->nbr < curr->next->nbr)
			return (0);
		curr = curr->next;
	}
	return (1);
}
