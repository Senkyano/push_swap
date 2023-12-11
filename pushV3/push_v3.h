/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_v3.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 20:31:20 by marvin            #+#    #+#             */
/*   Updated: 2023/12/09 20:31:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_V3_H
# define PUSH_V3_H

#include <unistd.h>
#include <stdbool.h>
#include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				push_cost;
	bool			median;
	bool			cheapest;
	struct s_stack	*target;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

// typedef struct s_stack
// {
// 	int				value;
// 	int				index;
// 	int				valen;
// 	bool			median;
// 	struct s_stack	*next;
// 	struct s_stack	*prev;
// }	t_stack;

#endif