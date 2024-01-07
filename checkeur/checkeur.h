/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkeur.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 00:32:07 by rihoy             #+#    #+#             */
/*   Updated: 2024/01/08 00:38:41 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKEUR_H
# define CHECKEUR_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_stack
{
	int	nbr;
	struct s_stack	*next;
}	t_stack;

#endif