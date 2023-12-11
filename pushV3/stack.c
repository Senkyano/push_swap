/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 15:15:58 by marvin            #+#    #+#             */
/*   Updated: 2023/12/09 15:15:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_sp.h"

t_stack	*room(int content, int index)
{
	t_stack	*in;

	in = malloc(sizeof(t_stack));
	if (!in)
		return (NULL);
	in->index = index;
	in->value = content;
	in->next = NULL;
}

void	add_room(t_stack *tower, t_stack *last_room)
{
	t_stack	*room;

	if (!tower)
	{
		tower = room;
		return ;
	}
	room = tower;
	while (room->next != NULL)
		room = room->next;
	room->next = last_room;
	last_room->prev = room;
}

void	clear_tower(t_stack *tower)
{
	t_stack	*room_clear;
	t_stack *room;

	room = tower->next;
	room_clear = tower;
	while (room != NULL)
	{
		free(room_clear);
		room_clear = room;
		room = room->next;
	}
	free(room_clear);
	free(tower);
}

void	build_in(const char **argv, t_stack *tower_a, t_stack *tower_b)
{
	t_data	key;

	key.i = 0;
	key.index = 0;
	while (argv[++key.i] != NULL)
	{
		key.sent = ft_split(argv[key.i]);
		key.j = -1;
		while (key.sent[++key.j] != NULL)
		{
			key.index++;
			if (onlynum(key.sent[key.j]))
				add_room(tower_a, room(ft_atoi(key.sent[key.j]), key.index));
			else
				exit_error(tower_a, tower_b);
		}
		freesplit(key.sent);
	}
}

void	show_room(t_stack *tower)
{
	t_stack	*room;

	room = tower;
	while (room != NULL)
	{
		printf("|%d|-", room->num);
		room = room->next;
	}
}

int	tower_len(t_stack *tower)
{
	t_stack	*room;
	int	i;

	i = 0;
	room = tower;
	while (room != NULL)
	{
		room = room->next;
		i++;
	}
	return (i);
}
