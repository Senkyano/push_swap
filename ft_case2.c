/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:29:25 by rihoy             #+#    #+#             */
/*   Updated: 2023/12/07 13:07:46 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

t_pile	**spawn_pile(const char **argv, t_pile **pile)
{
	d_donnee	in;
	
	in.j = 0;
	in.pos = 1;
	while (argv[++in.j] != NULL)
	{
		in.sent = ft_split(argv[in.j]);
		in.i = -1;
		while (in.sent[++in.i] != NULL)
		{
			if (str_isdigit(argv[in.i]))
				add_case(pile, new_case(number(in.sent[in.i]), in.pos));
			else
			{
				clear_pile(pile);
				freesplit(in.sent);
				return (NULL);
			}
			in.pos++;
		}
		freesplit(in.sent);
	}
	return (pile);
}

void	print_pile(t_pile **pile)
{
	t_pile	*curr;
	
	if (pile == NULL)
		return ;
	curr = *pile;
	while (curr != NULL)
	{
		printf("|%d| ", curr->num);
		curr = curr->next;
	}
}
