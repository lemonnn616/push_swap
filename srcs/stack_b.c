/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iriadyns <iriadyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:02:50 by iriadyns          #+#    #+#             */
/*   Updated: 2024/11/27 17:04:06 by iriadyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	pushed;

	size = stack_length(*stack_a);
	fill_stack_b(stack_a, stack_b, size);
	pushed = stack_length(*stack_b);
	while (size - pushed > 3)
	{
		pb(stack_a, stack_b);
		pushed++;
	}
}

void	fill_stack_b(t_stack **a,
		t_stack **b, int a_len)
{
	int	pushes;
	int	half_size;
	int	i;

	pushes = 0;
	half_size = a_len / 2;
	i = 0;
	while (a_len > 6 && i < a_len && pushes < half_size)
	{
		if ((*a)->index <= half_size)
		{
			pb(a, b);
			pushes++;
		}
		else
			ra(a);
		i++;
	}
}
