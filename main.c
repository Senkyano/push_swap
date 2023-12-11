/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 20:36:56 by marvin            #+#    #+#             */
/*   Updated: 2023/12/09 20:36:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_V3.h"

int	main(int argc, const char *argv[])
{
	t_stack	*tower_a;
	t_stack	*tower_b;

	tower_a = NULL;
	tower_b = NULL;
	if (argc < 2)
		return (1);
	build_in(argv, &tower_a, &tower_b); // construire la tour
	if (!value_checkeur(tower_a)) // regarder si c'est tout bon
	{
		if (tower_len(tower_a) == 2) // regarde si on as que 2 room
			swap(tower_a);
		else if (tower_len(tower_a) == 3) // regarde si on as que 3 room
			three_room(tower_a);
		else // si on as plus que 3 room
			sort_tower(a, b);
	}
	clear_tower(tower_a); // nettoyer la tour ou detruire la tour
	return (0);
}
