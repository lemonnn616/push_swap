/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_target.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iriadyns <iriadyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:06:05 by iriadyns          #+#    #+#             */
/*   Updated: 2024/11/27 17:07:18 by iriadyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_bigger(t_stack *s, int index_b, int *target_index,
		int *target_position)
{
	while (s)
	{
		if (s->index > index_b && s->index < *target_index)
		{
			*target_index = s->index;
			*target_position = s->pos;
		}
		s = s->next;
	}
}

void	find_min(t_stack *s, int *min_index, int *min_position)
{
	while (s)
	{
		if (s->index < *min_index)
		{
			*min_index = s->index;
			*min_position = s->pos;
		}
		s = s->next;
	}
}

int	find_target(t_stack **stack_a, int index_b)
{
	int	target_index;
	int	target_position;
	int	min_index;
	int	min_position;

	target_index = INT_MAX;
	target_position = INT_MAX;
	min_index = INT_MAX;
	min_position = -1;
	find_bigger(*stack_a, index_b, &target_index, &target_position);
	if (target_position == INT_MAX)
	{
		find_min(*stack_a, &min_index, &min_position);
		return (min_position);
	}
	return (target_position);
}
