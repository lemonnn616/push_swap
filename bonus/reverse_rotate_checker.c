/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_checker.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iriadyns <iriadyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:47:18 by iriadyns          #+#    #+#             */
/*   Updated: 2024/11/28 12:48:45 by iriadyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*prev;
	t_stack	*current;

	if (*stack && (*stack)->next)
	{
		prev = NULL;
		current = *stack;
		while (current->next)
		{
			prev = current;
			current = current->next;
		}
		if (prev)
		{
			prev->next = NULL;
			current->next = *stack;
			*stack = current;
		}
	}
}

void	rra(t_stack **a)
{
	reverse_rotate(a);
}

void	rrb(t_stack **b)
{
	reverse_rotate(b);
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}
