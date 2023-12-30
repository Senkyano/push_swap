/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:34:41 by rihoy             #+#    #+#             */
/*   Updated: 2023/12/29 19:03:42 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swaplib.h"

t_stack	*box(int value)
{
	t_stack	*box;

	box = malloc(sizeof(t_stack));
	if (!box)
		return (NULL);
	box->nbr = value;
	box->pile = 'a';
	box->next = NULL;
	return (box);
}

void	add_box(t_stack	**a, t_stack *box)
{
	t_stack	*curr;

	curr = *a;
	if (!(*a))
		*a = box;
	else
	{
		while (curr->next != NULL)
			curr = curr->next;
		curr->next = box;
	}
}

void	build_in(t_stack **a, const char **argv)
{
	t_data	in;

	in.i = 0;
	while (argv[++in.i])
	{
		in.sent = ft_split(argv[in.i]);
		in.j = -1;
		while (in.sent[++in.j])
		{
			if (onlydigit(in.sent[in.j]))
			{
				in.box = box(ft_atoi(in.sent[in.j], a, in.sent));
				if (!in.box)
					error_exit(a);
				add_box(a, in.box);
			}
			else
			{
				freesplit(in.sent);
				error_exit(a);
			}
		}
		freesplit(in.sent);
	}
}

void	free_stack(t_stack **a)
{
	t_stack	*curr;

	while (*a)
	{
		curr = (*a)->next;
		free(*a);
		(*a) = curr;
	}
}

void	print_stack(t_stack **a)
{
	t_stack	*curr;

	curr = *a;
	while (curr)
	{
		printf("%d \n", curr->nbr);
		curr = curr->next;
	}
}
