/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaplib.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:28:34 by rihoy             #+#    #+#             */
/*   Updated: 2023/12/13 18:27:44 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWAPLIB_H
# define SWAPLIB_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct s_stack
{
	int	nbr;
	int	index;
	struct s_stack	*ref;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

typedef	struct s_data
{
	int		i;
	int		j;
	t_stack	*box;
	char	**sent;
}	t_data;

// ERROR
void	error_exit(t_stack **a);
bool	same_value(t_stack **a);
bool	onlydigit(char *str);
// SPLIT
int	count_words(const char *str);
char	*words(const char *str);
void	freesplit(char **sent);
char	**ft_split(const char *str);
// STACK
t_stack	*box(int value);
void	add_box(t_stack	**a, t_stack *box);
void	build_in(t_stack **a, const char **argv);
void	free_stack(t_stack **a);
// UTILS
int	ft_atoi(char *str, t_stack **a, char **sent);
void	print_stack(t_stack **a);
bool	trie_ok(t_stack **a);
int	nbr_box(t_stack **a);
// OPERATIONS
void	push_to_a(t_stack **from, t_stack **to);
void	push_to_b(t_stack **from, t_stack **to);
void	rev_rota(t_stack **box);
void	rev_rota_a(t_stack **box);
void	rev_rota_b(t_stack **box);
void	rev_rota_all(t_stack **a, t_stack **b);
void	rota(t_stack **box);
void	rota_a(t_stack **box);
void	rota_b(t_stack **box);
void	rota_all(t_stack **a, t_stack **b);
void	swap_b(t_stack **box);
void	swap_a(t_stack **box);
void	swap(t_stack **box);
void	swap_all(t_stack **a, t_stack **b);
// ALGO
void	sort_three(t_stack **a);
void	more_than_three(t_stack **a, t_stack **b);
void	three_for_a(t_stack **a, t_stack **b);
// UTILS ALGO
t_stack	*mid_pos(t_stack **a);
bool	hightest(t_stack **a, t_stack *mid);

int		*tab_ref(t_stack **a);
bool	already_add(int *ref, int nbr);
void	print_tab(int *ref);

#endif