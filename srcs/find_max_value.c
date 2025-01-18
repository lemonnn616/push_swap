/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_max_value.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iriadyns <iriadyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:57:35 by iriadyns          #+#    #+#             */
/*   Updated: 2024/11/28 17:00:53 by iriadyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_max_value_node(t_stack **stack_a)
{
	t_stack	*current_node;
	t_stack	*max_value_node;
	int		max_value;

	current_node = *stack_a;
	max_value_node = NULL;
	max_value = INT_MIN;
	while (current_node)
	{
		update_max_value_node(&max_value_node, &max_value, current_node);
		current_node = current_node->next;
	}
	return (max_value_node);
}

void	update_max_value_node(t_stack **max_value_node, int *max_value,
		t_stack *current_node)
{
	if (current_node->index == 0)
	{
		if (*max_value_node == NULL || current_node->value > *max_value)
		{
			*max_value = current_node->value;
			*max_value_node = current_node;
		}
	}
}
