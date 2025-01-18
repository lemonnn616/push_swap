/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iriadyns <iriadyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:12:21 by iriadyns          #+#    #+#             */
/*   Updated: 2024/11/27 17:13:48 by iriadyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_index_pos(t_stack **stack)
{
	t_stack	*cur;
	int		min_pos;
	int		min_index;

	cur = *stack;
	if (!cur)
		return (-1);
	assign_positions(stack);
	min_pos = cur->pos;
	min_index = cur->index;
	while (cur)
	{
		if (cur->index < min_index)
		{
			min_index = cur->index;
			min_pos = cur->pos;
		}
		cur = cur->next;
	}
	return (min_pos);
}

void	final_stack_sort(t_stack **stack_a)
{
	int	min_index_pos;
	int	stack_len;

	stack_len = stack_length(*stack_a);
	min_index_pos = find_min_index_pos(stack_a);
	if (min_index_pos > stack_len / 2)
		while (min_index_pos++ < stack_len)
			rra(stack_a);
	else
		while (min_index_pos-- > 0)
			ra(stack_a);
}
