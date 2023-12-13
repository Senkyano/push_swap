/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:28:22 by rihoy             #+#    #+#             */
/*   Updated: 2023/12/13 18:16:44 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swaplib.h"

// faire un tab de ref deja trie

int	main(int argc, const char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	int		*ref;

	if (argc < 2)
		return (1);
	a = NULL;
	b = NULL;
	build_in(&a, argv);
	ref = tab_ref(&a);
	print_tab(ref);
	if (same_value(&a) || !ref)
		error_exit(&a);
	// if (!trie_ok(&a))
	// {
	// 	if (nbr_box(&a) == 2)
	// 		swap_a(&a);
	// 	else if (nbr_box(&a) == 3)
	// 		sort_three(&a);
	// 	else if (nbr_box(&a) > 3)
	// 		more_than_three(&a, &b);
	// }
	free_stack(&a);
	return (0);
}

void	print_tab(int *ref)
{
	int	i;

	i = 0;
	while (ref[i])
	{
		printf("%d ", ref[i]);
		i++;
	}
	free(ref);
}
