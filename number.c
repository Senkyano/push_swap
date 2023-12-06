/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:14:38 by rihoy             #+#    #+#             */
/*   Updated: 2023/11/30 16:26:41 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

int	number(const char *str)
{
	int	neg;
	int	nbr;
	int	i;
	
	i = 0;
	neg = 1;
	nbr = 0;
	if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9') && str[i])
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	return (nbr * neg);
}
