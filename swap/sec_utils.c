/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sec_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:35:15 by rihoy             #+#    #+#             */
/*   Updated: 2023/12/20 19:44:32 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swaplib.h"

int	front_back(int back, int here, int front)
{
	if (!(back < here && front > here))
		return (1);
	return (0);
}

int	back_front(int back, int here, int front)
{
	if (!(back > here && front < here))
		return (1);
	return (0);
}
