/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:01:40 by rihoy             #+#    #+#             */
/*   Updated: 2023/12/29 19:06:40 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swaplib.h"

int	ft_atoi(char *str, t_stack **a, char **sent)
{
	int			neg;
	long int	nbr;

	nbr = 0;
	neg = 1;
	if (*str == '-')
	{
		neg = -1;
		str++;
	}
	while (*str)
	{
		nbr = *str - '0' + nbr * 10;
		if (nbr > INT_MAX || nbr < INT_MIN)
		{
			freesplit(sent);
			error_exit(a);
		}
		str++;
	}
	return ((int)nbr * neg);
}

bool	trie_ok(t_stack **a)
{
	t_stack	*curr;
	t_stack	*cmp;

	curr = *a;
	while (curr->next != NULL)
	{
		cmp = curr->next;
		if (curr->nbr > cmp->nbr)
			return (0);
		curr = curr->next;
	}
	return (1);
}

int	nbr_box(t_stack **a)
{
	t_stack	*curr;
	int		i;

	curr = *a;
	i = 0;
	while (curr)
	{
		i++;
		curr = curr->next;
	}
	return (i);
}
