/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_push_swap.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:58:39 by rihoy             #+#    #+#             */
/*   Updated: 2023/12/07 16:20:29 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_PUSH_SWAP_H
# define LIB_PUSH_SWAP_H

#include <unistd.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_pile
{
	int				num;
	int				manip;
	char			pile;
	struct s_pile	*next;
}	t_pile;

typedef struct s_donnee
{
	int	i;
	int	j;
	int	pos;
	char	**sent;
}	d_donnee;

/* ************************************************************************** */
/*                             MAIN                                           */
/* ************************************************************************** */
void	clear_all(t_pile **pile_a, t_pile **pile_b);
int	errormsg(t_pile **pile_a, t_pile **pile_b);

void	printite(char *str, char c);

/* ************************************************************************** */
/*                             ALGO                                           */
/* ************************************************************************** */
void	algo(t_pile **pile_a, t_pile **pile_b, int sizecase);
void	three_case(t_pile **pile_a);
void	algomore(t_pile **pile_a);
void	firstlast(t_pile **pile_a);

/* ************************************************************************** */
/*                             CHECK                                          */
/* ************************************************************************** */
int		check_value(t_pile **pile_a);
int		same_value(t_pile **pile_a);
int		str_isdigit(const char *str);
int		number_case(t_pile **pile_a);

/* ************************************************************************** */
/*                             case                                           */
/* ************************************************************************** */
void	add_case(t_pile **piler, t_pile *case_last);
t_pile	*new_case(int content);
void	del_case(t_pile *case_curr);
void	clear_pile(t_pile **pile);

/* ************************************************************************** */
/*                             CASE2                                          */
/* ************************************************************************** */
t_pile	**spawn_pile(const char **argv, t_pile **pile);
void	print_pile(t_pile **pile);

/* ************************************************************************** */
/*                             NUMB                                           */
/* ************************************************************************** */
int		number(const char *str);

/* ************************************************************************** */
/*                             SPLIT                                          */
/* ************************************************************************** */
int		count_words(const char *str);
char	*words(const char *str);
void	freesplit(char **sent);
char	**ft_split(const char *str);

/* ************************************************************************** */
/*                             PUSH                                           */
/* ************************************************************************** */
void	push_case(t_pile **pile_curr, t_pile **pile_to);

/* ************************************************************************** */
/*                             REV_ROTA                                       */
/* ************************************************************************** */
void	rev_rota(t_pile **pile);
void	rev_rotall(t_pile **pile_a, t_pile **pile_b);

/* ************************************************************************** */
/*                               ROTA                                         */
/* ************************************************************************** */
void	rota(t_pile **pile);
void	rotate_all(t_pile **pile_a, t_pile **pile_b);

/* ************************************************************************** */
/*                               SWAP                                         */
/* ************************************************************************** */
void	swap_q(t_pile **pile);
void	swap_s(t_pile **pile_a, t_pile **pile_b);


#endif