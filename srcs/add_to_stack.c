/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iriadyns <iriadyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:39:23 by iriadyns          #+#    #+#             */
/*   Updated: 2024/11/27 16:51:41 by iriadyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_nums_to_stack(char *input_str, t_stack **stack_a)
{
	char		**split_nums;
	long		num;
	int			i;

	split_nums = ft_split(input_str, ' ');
	i = 0;
	while (split_nums[i] != NULL)
	{
		if (is_num(split_nums[i]))
		{
			num = ft_atol(split_nums[i]);
			if (num > INT_MAX || num < INT_MIN)
			{
				free_stacks(stack_a, NULL);
				print_error();
			}
			add_to_stack(stack_a, num);
		}
		else
			print_error();
		free(split_nums[i]);
		i++;
	}
	free(split_nums);
}

t_stack	*create_stack_node(int value)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = 0;
	new_node->pos = -1;
	new_node->target = -1;
	new_node->a_cost = -1;
	new_node->b_cost = -1;
	new_node->next = NULL;
	return (new_node);
}

void	add_to_stack(t_stack **stack_head, int value_new_node)
{
	t_stack	*new_node;
	t_stack	*last_node;

	new_node = create_stack_node(value_new_node);
	if (!new_node)
		return ;
	if (!*stack_head)
	{
		*stack_head = new_node;
		return ;
	}
	last_node = *stack_head;
	while (last_node->next != NULL)
	{
		last_node = last_node->next;
	}
	last_node->next = new_node;
}
