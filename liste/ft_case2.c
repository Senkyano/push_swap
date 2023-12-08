/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:29:25 by rihoy             #+#    #+#             */
/*   Updated: 2023/12/07 16:34:52 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

t_pile	**spawn_pile(const char **argv, t_pile **pile_a, t_pile **pile_b)
{
	d_donnee	in;
	
	in.j = 0;
	while (argv[++in.j] != NULL)
	{
		in.sent = ft_split(argv[in.j]);
		in.i = -1;
		while (in.sent[++in.i] != NULL)
		{
			if (str_isdigit(in.sent[in.i]) == 1)
				add_case(pile_a, new_case(number(in.sent[in.i])));
			else
				errormsg(pile_a, pile_b);
		}
		freesplit(in.sent);
	}
	return (pile);
}

void	print_pile(t_pile **pile)
{
	t_pile	*curr;

	curr = *pile;
	while (curr != NULL)
	{
		printf("|%d| ", curr->num);
		curr = curr->next;
	}
}
