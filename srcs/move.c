/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iriadyns <iriadyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:09:49 by iriadyns          #+#    #+#             */
/*   Updated: 2024/11/27 17:11:35 by iriadyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lowest_movement(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		a_cost;
	int		b_cost;
	int		lowest_cost;
	int		tmp_cost;

	tmp = *stack_b;
	a_cost = 0;
	b_cost = 0;
	while (tmp)
	{
		tmp_cost = abs(tmp->a_cost) + abs(tmp->b_cost);
		if (tmp_cost < lowest_cost)
		{
			lowest_cost = tmp_cost;
			a_cost = tmp->a_cost;
			b_cost = tmp->b_cost;
		}
		tmp = tmp->next;
	}
	if (lowest_cost != INT_MAX)
		move(stack_a, stack_b, a_cost, b_cost);
}

void	move(t_stack **a, t_stack **b, int a_cost, int b_cost)
{
	if (a_cost < 0 && b_cost < 0)
	{
		while (a_cost < 0 && b_cost < 0)
		{
			(a_cost)++;
			(b_cost)++;
			rrr(a, b);
		}
	}
	else if (a_cost > 0 && b_cost > 0)
	{
		while (a_cost > 0 && b_cost > 0)
		{
			a_cost--;
			b_cost--;
			rr(a, b);
		}
	}
	rotate_ab(a, &a_cost, 0);
	rotate_ab(b, &b_cost, 1);
	pa(a, b);
}

void	rotate_ab(t_stack **stack, int *cost, int is_b)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			if (is_b)
				rb(stack);
			else
				ra(stack);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			if (is_b)
				rrb(stack);
			else
				rra(stack);
			(*cost)++;
		}
	}
}
