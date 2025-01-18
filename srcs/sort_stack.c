/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iriadyns <iriadyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:59:51 by iriadyns          #+#    #+#             */
/*   Updated: 2024/11/27 17:01:04 by iriadyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stacks_three(t_stack **stack)
{
	int		initial_index;
	int		max_index;
	t_stack	*current_node;

	initial_index = (*stack)->index;
	max_index = initial_index;
	current_node = *stack;
	while (current_node)
	{
		if (current_node->index > max_index)
			max_index = current_node->index;
		current_node = current_node->next;
	}
	if ((*stack)->index == max_index)
		ra(stack);
	else if ((*stack)->next->index == max_index)
		rra(stack);
	if ((*stack)->index > (*stack)->next->index)
		sa(stack);
}

void	sort_stacks(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		target;

	push_to_b(a, b);
	if (!stack_is_sorted(*a))
		sort_stacks_three(a);
	while (*b)
	{
		tmp = *b;
		assign_positions(a);
		assign_positions(b);
		target = 0;
		while (tmp)
		{
			target = find_target(a, tmp->index);
			tmp->target = target;
			tmp = tmp->next;
		}
		calculate_costs(a, b);
		lowest_movement(a, b);
	}
	if (!stack_is_sorted(*a))
		final_stack_sort(a);
}
