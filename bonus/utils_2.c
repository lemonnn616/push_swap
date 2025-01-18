/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iriadyns <iriadyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:55:12 by iriadyns          #+#    #+#             */
/*   Updated: 2024/11/28 13:04:49 by iriadyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_stack	*create_new_node(int value)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		print_error();
	node->value = value;
	node->index = -1;
	node->next = NULL;
	return (node);
}

void	add_to_stack(t_stack **stack, int value)
{
	t_stack	*node;
	t_stack	*current;

	node = create_new_node(value);
	if (!*stack)
		*stack = node;
	else
	{
		current = *stack;
		while (current->next)
			current = current->next;
		current->next = node;
	}
}

bool	has_duplicates(t_stack *stack)
{
	t_stack	*current;
	t_stack	*checker;

	current = stack;
	while (current)
	{
		checker = current->next;
		while (checker)
		{
			if (current->value == checker->value)
				return (true);
			checker = checker->next;
		}
		current = current->next;
	}
	return (false);
}
