/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaplib.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:28:34 by rihoy             #+#    #+#             */
/*   Updated: 2023/12/20 18:43:23 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWAPLIB_H
# define SWAPLIB_H

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
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;
// STACK
t_stack		*box(int value);
void		add_box(t_stack **a, t_stack *box);
void		build_in(t_stack **a, const char **argv);
void		free_stack(t_stack **a);
// OPERATIONS
void		push_to_a(t_stack **from, t_stack **to);
void		push_to_b(t_stack **from, t_stack **to);
void		rev_rota(t_stack **box);
void		rev_rota_a(t_stack **box);
void		rev_rota_b(t_stack **box);
void		rev_rota_all(t_stack **a, t_stack **b);
void		rota(t_stack **box);
void		rota_a(t_stack **box);
void		rota_b(t_stack **box);
void		rota_all(t_stack **a, t_stack **b);
void		swap_b(t_stack **box);
void		swap_a(t_stack **box);
void		swap(t_stack **box);
void		swap_all(t_stack **a, t_stack **b);
/* ************************************************************************** */

/* ************************************************************************** */
// DATA
typedef	struct s_data
{
	int		i;
	int		j;
	int		cost;
	int		min_cost;
	int		cost_ra;
	int		cost_rb;
	int		cost_rra;
	int		cost_rrb;
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
}	t_ref;
t_ref		sort_ref(t_ref ref);
t_ref		tab_reference(t_stack **a);
t_stack		*mid_pos_ref(t_stack **a, t_ref ref);
/* ************************************************************************** */

// ERROR
void		error_exit(t_stack **a);
void		error_algo(t_stack	**a, t_stack **b);
bool		same_value(t_stack **a);
bool		onlydigit(char *str);
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
// ALGO
void		sort_mid(t_stack **a, t_stack **b);
void		sort_three(t_stack **a);
void		sort_more(t_stack **a, t_stack **b);
int			chunk_creator(t_stack **a, t_stack **b, t_ref ref, int i);
// UTILS ALGO
bool		hightest(t_stack **a, t_stack *mid);
t_data min_value(t_stack **a);
int	back_front(int back, int here, int front);
int	front_back(int back, int here, int front);
// COST_OP
t_stack	*last_box(t_stack **b);
int	cost_ra(t_stack **a, t_stack *btw);
int	cost_rra(t_stack **a, t_stack *btw);
int	cost_rb(t_stack **b, t_stack *srch);
int	cost_rrb(t_stack **b, t_stack *srch);

#endif