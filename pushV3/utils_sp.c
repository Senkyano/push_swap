/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 15:07:09 by marvin            #+#    #+#             */
/*   Updated: 2023/12/09 15:07:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_V3.h"

void	exit_error(t_stack *tower_a, t_stack *tower_b)
{
	clear_tower(tower_a);
	clear_tower(tower_b);
	write(2, "Error\n", 6);
	exit(1);
}

int	ft_atoi(char *str)
{
	int	neg;
	int	nb;

	neg = 1;
	nb = 0;
	if (*str == '-')
	{
		neg = -1;
		str++;
	}
	while (*str)
	{
		nb = *str - '0' + (nb * 10);
		str++;
	}
	return (nb * neg);
}
