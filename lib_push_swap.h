/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_push_swap.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:58:39 by rihoy             #+#    #+#             */
/*   Updated: 2023/12/06 14:02:56 by rihoy            ###   ########.fr       */
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
	int				place;
	struct s_pile	*next;
}	t_pile;

typedef struct s_donnee
{
	int	i;
	int	j;
	char	**sent;
}	d_donnee;
/* ************************************************************************** */
/*                             MAIN                                           */
/* ************************************************************************** */
void	print_pile(t_pile **pile);
int		str_isdigit(const char *str);
t_pile	**spawn_pile(const char **argv, t_pile **pile);

/* ************************************************************************** */
/*                             case                                           */
/* ************************************************************************** */
void	add_case(t_pile **piler, t_pile *case_last);
t_pile	*new_case(int content);
void	del_case(t_pile *case_curr);
void	clear_pile(t_pile **pile);

/* ************************************************************************** */
/*                             NUMB                                           */
/* ************************************************************************** */
int		number(const char *str);

/* ************************************************************************** */
/*                             SPLIT                                          */
/* ************************************************************************** */
int	count_words(const char *str);
char	*words(const char *str);
void	freesplit(char **sent);
char	**ft_split(const char *str);

/* ************************************************************************** */
/*                             REV_ROTA                                       */
/* ************************************************************************** */
void	rev_rota(t_pile **pile);
void	rev_rotall(t_pile **pile_a, t_pile **pile_b);

/* ************************************************************************** */
/*                             REV_ROTA                                       */
/* ************************************************************************** */
void	rotate_pile(t_pile **pile);
void	rotate_all(t_pile **pile_a, t_pile **pile_b);

/* ************************************************************************** */
/*                             REV_ROTA                                       */
/* ************************************************************************** */
void	swap_q(t_pile **pile);
void	swap_s(t_pile **pile_a, t_pile **pile_b);


#endif