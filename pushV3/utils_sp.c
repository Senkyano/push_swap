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

void	exit_error(t_stack *tower_a, t_stack *tower_b) // gerer les erreurs
{
	clear_tower(tower_a);
	if (tower_b != NULL)
		clear_tower(tower_b);
	write(2, "Error\n", 6);
	exit(1);
}

int	ft_atoi(char *str, t_stack **tower_a, t_stack **tower_b) // atoi de base
{
	int			neg;
	long int	nb;

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
		if (nb > INT_MAX || nb < INT_MIN)
			exit_error(tower_a, tower_b);
		str++;
	}
	return ((int)(nb * neg));
}

t_stack	*find_min(t_stack *room) // pour trouve le plus petit donc il nous faut le plus grand possible
{
	long	min;
	t_stack	*room_min;

	if (!room)
		return (NULL);
	min = LONG_MAX;
	while (room)
	{
		if (room->value < min)
		{
			min = room->value;
			room_min = room;
		}
		room = room->next;
	}
	return (room_min);
}

t_stack	*find_max(t_stack *room) // pour trouve le plus grand donc il nous faut le plus petit possible
{
	long		max;
	t_stack		*room_max;

	if (!room)
		return (NULL);
	max = LONG_MIN;
	while (room)
	{
		if (room->value > max)
		{
			max = room->value;
			room_max = room;
		}
		room = room->next;
	}
	return (room_max);
}

t_stack	*find_last(t_stack *room) // allé a la derniere cellule
{
	if (!room)
		return (NULL);
	while (room->next != NULL)
		room = room->next;
	return (room);
}
