/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iriadyns <iriadyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:23:51 by iriadyns          #+#    #+#             */
/*   Updated: 2024/11/28 11:48:05 by iriadyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target;
	int				a_cost;
	int				b_cost;
	struct s_stack	*next;
}	t_stack;

// ft_utils
int		abs(int nb);
void	ft_putstr(char *str);
int		is_num(char *av);
void	print_error(void);

// swap
void	swap(t_stack **stack);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);

// push
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);

// rotate 
void	rotate(t_stack **stack);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);

// reverse_rotate
void	reverse_rotate(t_stack **stack);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

// add_to_stack
void	add_nums_to_stack(char *input_str, t_stack **stack_a);
t_stack	*create_stack_node(int value);
void	add_to_stack(t_stack **stack_head, int value_new_node);

// check_duplic
int		has_duplicate(t_stack *start, int value);
int		stack_is_duplicated(t_stack *col);

// utils
void	free_stacks(t_stack **a, t_stack **b);
int		stack_length(t_stack *stack);
int		stack_is_sorted(t_stack *stack);
void	assign_positions(t_stack **stack);

// find_max_value
t_stack	*find_max_value_node(t_stack **stack_a);
void	update_max_value_node(t_stack **max_value_node, int *max_value,
			t_stack *current_node);

// sort_stack
void	sort_stacks_three(t_stack **stack);
void	sort_stacks(t_stack **a, t_stack **b);

// stack_b
void	push_to_b(t_stack **stack_a, t_stack **stack_b);
void	fill_stack_b(t_stack **a, t_stack **b, int a_len);

// find target
int		find_target(t_stack **stack_a, int index_b);
void	find_min(t_stack *s, int *min_index, int *min_position);
void	find_bigger(t_stack *s, int index_b, int *target_index,
			int *target_position);

// calculate_costs
void	calculate_costs(t_stack **a, t_stack **b);
int		calculate_cost(int position, int total_size);

// move
void	lowest_movement(t_stack **stack_a, t_stack **stack_b);
void	move(t_stack **a, t_stack **b, int a_cost, int b_cost);
void	rotate_ab(t_stack **stack, int *cost, int is_b);

// final_sort
void	final_stack_sort(t_stack **stack_a);
int		find_min_index_pos(t_stack **stack);

// main
void	push_swap(t_stack **stack_a, t_stack **stack_b);

#endif