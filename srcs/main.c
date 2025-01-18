/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iriadyns <iriadyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:13:07 by iriadyns          #+#    #+#             */
/*   Updated: 2024/11/28 17:18:03 by iriadyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*max_value_node;
	int		stack_size;
	int		total_elements;

	if (stack_is_duplicated(*stack_a))
	{
		free_stacks(stack_a, NULL);
		print_error();
	}
	stack_size = stack_length(*stack_a);
	total_elements = stack_size + 1;
	while (--total_elements > 0)
	{
		max_value_node = find_max_value_node(stack_a);
		max_value_node->index = total_elements;
	}
	if (!stack_is_sorted(*stack_a))
	{
		if (stack_size == 2)
			sa(stack_a);
		else if (stack_size == 3)
			sort_stacks_three(stack_a);
		else if (stack_size > 3)
			sort_stacks(stack_a, stack_b);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;

	stack_b = NULL;
	stack_a = NULL;
	i = 0;
	while (++i < argc)
		add_nums_to_stack(argv[i], &stack_a);
	push_swap(&stack_a, &stack_b);
	free_stacks(&stack_a, &stack_b);
	return (0);
}
