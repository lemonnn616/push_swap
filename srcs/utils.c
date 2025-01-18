/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iriadyns <iriadyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:55:27 by iriadyns          #+#    #+#             */
/*   Updated: 2024/11/28 11:48:48 by iriadyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_length(t_stack *stack)
{
	int		size;
	t_stack	*current;

	size = 0;
	current = stack;
	while (current)
	{
		size++;
		current = current->next;
	}
	return (size);
}

void	free_stacks(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (a)
	{
		while (*a)
		{
			tmp = (*a)->next;
			free(*a);
			*a = tmp;
		}
		*a = NULL;
	}
	if (b)
	{
		while (*b)
		{
			tmp = (*b)->next;
			free(*b);
			*b = tmp;
		}
		*b = NULL;
	}
}

int	stack_is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	assign_positions(t_stack **stack)
{
	t_stack	*cur;
	int		i;

	if (!stack || !*stack)
		return ;
	cur = *stack;
	i = 0;
	while (cur)
	{
		cur->pos = i;
		cur = cur->next;
		i++;
	}
}
