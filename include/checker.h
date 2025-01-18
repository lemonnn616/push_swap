/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iriadyns <iriadyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:18:01 by iriadyns          #+#    #+#             */
/*   Updated: 2024/11/28 14:02:49 by iriadyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft.h"
# include <stdbool.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

// main
void	read_instructions(t_stack **stack_a, t_stack **stack_b);
bool	apply_instruction(char *line, t_stack **a, t_stack **b);
bool	ft_strequ(const char *s1, const char *s2);

// swap_checker
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);

// push_checker
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);

// rotate_checker
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);

// reverse_rotate_checker
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

// utils_1
bool	stack_is_sorted(t_stack *stack);
void	ft_putstr(char *str);
void	print_error(void);
void	free_stack(t_stack **stack);
bool	is_valid_number(const char *str);

// utils_2
t_stack	*create_new_node(int value);
void	add_to_stack(t_stack **stack, int value);
bool	has_duplicates(t_stack *stack);

// pars_arg
t_stack	*parse_arguments(int argc, char **argv);
int		is_num(char	*str);
#endif