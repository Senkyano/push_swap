/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:28:22 by rihoy             #+#    #+#             */
/*   Updated: 2023/12/18 17:15:55 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swaplib.h"

// faire un tab de ref deja trie

int	main(int argc, const char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (1);
	a = NULL;
	b = NULL;
	build_in(&a, argv);
	if (same_value(&a))
		error_exit(&a);
	if (!trie_ok(&a))
	{
		if (nbr_box(&a) == 2)
			swap_a(&a);
		else if (nbr_box(&a) == 3)
			sort_three(&a);
		else if (nbr_box(&a) > 3)
			sort_mid(&a, &b);
	}
	free_stack(&b);
	free_stack(&a);
	return (0);
}
