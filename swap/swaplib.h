/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaplib.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:28:34 by rihoy             #+#    #+#             */
/*   Updated: 2024/01/06 19:27:28 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWAPLIB_H
# define SWAPLIB_H

#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

/* ************************************************************************** */
// STACK
typedef struct s_stack
{
	int	nbr;
	char	pile;
	struct s_stack	*next;
}	t_stack;
// STACK
t_stack		*box(int value);
void		add_box(t_stack **a, t_stack *box);
void		build_in(t_stack **a, const char **argv);
void		free_stack(t_stack **a);
// OPERATIONS
void	action(char *str, char c);
void		push_to(t_stack **from, t_stack **to);
// void		push_to_b(t_stack **from, t_stack **to);
void		rev_rota(t_stack **box);
void		rev_rota_pile(t_stack **box);
// void		rev_rota_b(t_stack **box);
void		rev_rota_all(t_stack **a, t_stack **b);
void		rota(t_stack **box);
void		rota_pile(t_stack **box);
// void		rota_b(t_stack **box);
void		rota_all(t_stack **a, t_stack **b);
// void		swap_b(t_stack **box);
void		swap_pile(t_stack **box);
void		swap(t_stack **box);
void		swap_all(t_stack **a, t_stack **b);
/* ************************************************************************** */

/* ************************************************************************** */
// DATA
typedef	struct s_data
{
	int		i;
	int		j;
	int		size;
	int		inception;

	int		push;
	int		rota_from;
	int		rota_to;
	t_stack	*box;
	char	**sent;
}	t_data;
/* ************************************************************************** */

/* ************************************************************************** */
// REF
typedef	struct	s_ref
{
	int	*tab;
	int	size;
	int	half_taff;
	int non_taff;
	int	ind_mid;
	int	start_taff;
	int	end_taff;
}	t_ref;
// REFERENCE
t_ref		sort_ref(t_ref ref);
t_ref		tab_reference(t_stack **a);
t_stack		*mid_pos_ref(t_stack **a, t_ref ref);

///////////
bool	num_have(int *ref, int hv, int size);
t_ref	order_tab(t_stack **a);
void	printab(t_ref ref);
/* ************************************************************************** */

// ERROR
void		error_exit(t_stack **a);
void		error_algo(t_stack	**a, t_stack **b);
bool		same_value(t_stack **a);
bool		onlydigit(char *str);
void		free_all(t_stack **a, t_stack **b, t_ref ref);
// SPLIT
int			count_words(const char *str);
char		*words(const char *str);
void		freesplit(char **sent);
char		**ft_split(const char *str);
// UTILS
int			ft_atoi(char *str, t_stack **a, char **sent);
void		print_stack(t_stack **a);
bool		trie_ok(t_stack **a);
int			nbr_box(t_stack **a);
int	min_half(t_stack **a, int half); // sec_uti
// ALGO
void		sort_three(t_stack **a);
void	send_mid(t_stack **a, t_stack **b);
void	sort_algo(t_stack **a, t_stack **b);
int	chunk_creator(t_stack **a, t_stack **b, t_ref ref, int i);
t_stack	*last_box(t_stack **b);

///////////     RECURSIVE V2

t_ref	first_half(t_ref ref);// utils
int	chunk_diss(t_stack **a, t_stack **b, t_ref ref, int rev);//algo
int	rest_taff(t_ref ref, int ind);// utils


void	dissection(t_stack **a, t_stack **b, t_ref ref, t_data data);//algo
void	reintegration(t_stack **from, t_stack **to, t_ref ref);
void	chunk_split(t_stack **from, t_stack **to, t_ref ref);
t_ref	new_ref_from(t_ref ref);
t_ref	new_ref_to(t_ref ref);
void	only_a(t_stack **from, t_stack **to);
bool	checkeur(t_stack **a, t_ref ref);
// void	trie_b(t_stack **from, t_stack **to, t_ref ref);
// void	trie_a(t_stack **from, t_stack **a, t_ref ref);
t_ref	mid_lower(t_ref ref);
t_ref	mid_supsup(t_ref ref);
t_ref	mid_suplow(t_ref ref);
t_data	cuting_part(t_stack **from, t_stack **to, t_ref ref);
// void	ecomove(t_stack **from, t_stack **to, t_data dt);
// void	all_for(t_stack **from, t_stack **to, t_ref ref);
void	trie_four(t_stack **from, t_stack **to, t_ref ref);


// UTILS ALGO
void	print_tab(t_ref ref);
void	print_stack_half(t_stack **a, int size);

#endif