/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:26:32 by rihoy             #+#    #+#             */
/*   Updated: 2023/12/07 16:35:32 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

int	main(int argc, const char *argv[])
{
	t_pile	**pile_a;
	t_pile	**pile_b;
	
	if (argc < 2)
		return (0);
	pile_b = malloc(sizeof(t_pile *));
	pile_a = malloc(sizeof(t_pile *));
	if (!pile_a || !pile_b)
		return (1);
	*pile_a = NULL;
	*pile_b = NULL;
	pile_a = spawn_pile(argv, pile_a, pile_b);
	if (*pile_a == NULL || !same_value(pile_a))
		errormsg(pile_a, pile_b);
	algo(pile_a, pile_b, number_case(pile_a));
	print_pile(pile_a);
	clear_all(pile_a, pile_b);
	return (0);
}

int	errormsg(t_pile **pile_a, t_pile **pile_b)
{
	clear_all(pile_a, pile_b);
	printite("error\n", 0);
	exit(1);
}

void	clear_all(t_pile **pile_a, t_pile **pile_b)
{
	clear_pile(pile_a);
	clear_pile(pile_b);
	free(pile_a);
	free(pile_b);
}
