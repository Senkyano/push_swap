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
#include <limits.h>
#include <stdlib.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				push_cost;
	int				median;
	int				cheapest;
	struct s_stack	*target_room;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

// typedef struct s_stack
// {
// 	int				value; // La valeur exact
// 	int				rank; // determine son classement entre 0 et 1
// 	int				len; // determine sa longueur qui fait
// 	int				pos; // 1 = Oui && 0 = Non
// 	struct s_stack	*next;
// 	struct s_stack	*prev;
// }	t_stack;

// ERROR
void	exit_error(t_stack *tower_a, t_stack *tower_b);
int		onlynum(char *str);
int		same_value(t_stack *tower);
int		value_checkeur(t_stack *tower);
// UTILS
int		ft_atoi(char *str, t_stack **tower_a, t_stack **tower_b);
t_stack	*find_min(t_stack *room);
t_stack	*find_max(t_stack *room);
t_stack	*find_last(t_stack *room);
// UTILS ALGO
static void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
static void	rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
static void	move_a_to_b(t_stack **a, t_stack **b);
static void	move_b_to_a(t_stack **a, t_stack **b);
static void	min_on_top(t_stack **a);
// STACK
t_stack	*room(int content);
void	add_room(t_stack **tower, t_stack *last_room);
void	clear_tower(t_stack **tower);
void	build_in(const char **argv, t_stack **a, t_stack **b);
int	tower_len(t_stack **tower);
// INIT_B_TO_A
static void	set_target_b(t_stack *a, t_stack *b);
void	init_room_b(t_stack *a, t_stack *b);
// INIT_A_TO_B
void	set_cheapest(t_stack *room);
static void	cost_analysis_a(t_stack	*room_a, t_stack *room_b);
static void	set_target_a(t_stack *room_a, t_stack *room_b);
void	curr_index(t_stack *room);
void	init_room_a(t_stack	*room_a, t_stack *room_b);
// SPLIT
char	**ft_split(const char *str);
void	freesplit(char **sent);
char	*words(const char *str);
int	count_words(const char *str);
// ALGO
void	sort_tower(t_stack **tower_a, t_stack **tower_b);
void	three_room(t_stack **tower);
// SWAP
void	swap(t_stack **tower);
void	swap_a(t_stack **tower);
void	swap_b(t_stack **tower);
void	swap_all(t_stack **tower_a, t_stack **tower_b);
// ROTA
void	rota_all(t_stack **tower_a, t_stack **tower_b);
void	rota_b(t_stack **tower);
void	rota_a(t_stack **tower);
void	rota(t_stack **tower);
// REV_ROTA
void	rev_rota(t_stack **tower);
void	rev_rota_a(t_stack **tower);
void	rev_rota_b(t_stack **tower);
void	rev_rota_all(t_stack **tower_a, t_stack **tower_b);
// PUSH
void	push_to_b(t_stack **tower_from, t_stack **tower_to);
void	push_to_a(t_stack **tower_from, t_stack **tower_to);

#endif