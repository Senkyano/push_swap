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

#include "push_V3.h"

t_stack	*room(int content) // on cree la room pour stocker les informations
{
	t_stack	*in;

	in = malloc(sizeof(t_stack));
	if (!in)
		return (NULL);
	in->value = content;
	in->next = NULL;
}

void	add_room(t_stack **tower, t_stack *last_room) // on ajoute une room a la derniere room de la tour
{
	t_stack	*room;

	if (!tower)
	{
		*tower = last_room;
		return ;
	}
	room = *tower;
	while (room->next != NULL) // on parcours jusqu'a la derniere room
		room = room->next;
	room->next = last_room;
	last_room->prev = room;
}

void	clear_tower(t_stack **tower) // on nettoie ou detruit la tour
{
	t_stack	*room_clear;

	room_clear = *tower;
	while (room_clear->next != NULL)
	{
		if (room_clear->prev != NULL)
			free(room_clear->prev); // librer chaque room
		room_clear = room_clear->next;
	}
	*tower = room_clear->next;
	free(room_clear); // librer la derniere chambre
}

void	build_in(const char **argv, t_stack **a, t_stack **b) // construire la tour
{
	int	i;
	int	j;
	char	*sent;

	i = 0;
	while (argv[++i] != NULL)
	{
		sent = ft_split(argv[i]); // si on nous donne une chaine de caractere on extrait tout de la chaine
		j = -1;
		while (sent[++j] != NULL)
		{
			if (onlynum(sent[j])) // regarde si elle est constitue que de nombre
				add_room(a, room(ft_atoi(sent[j], a, b))); // ajoute a la suite de la tour
			else
				exit_error(a, b); // si il n'y as pas que des chiffre alors on proc la sortie error
		}
		freesplit(sent); // on n'oublie pas de librer la memoire pour valgrind
	}
	if (!same_value(a)) // si il y a des nombres/chiffre similaire alors on proc la sortie error
		exit_error(a, b); 
}

int	tower_len(t_stack **tower) // combien de room fait la tour
{
	t_stack	*room;
	int	i;

	i = 0;
	room = *tower;
	while (room != NULL)
	{
		room = room->next;
		i++;
	}
	return (i);
}
