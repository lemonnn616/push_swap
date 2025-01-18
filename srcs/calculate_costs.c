/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_costs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iriadyns <iriadyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:07:45 by iriadyns          #+#    #+#             */
/*   Updated: 2024/11/27 17:17:09 by iriadyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_cost(int position, int total_size)
{
	if (position > total_size / 2)
		return (position - total_size);
	return (position);
}

void	calculate_costs(t_stack **a, t_stack **b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		len_a;
	int		len_b;

	tmp_a = *a;
	tmp_b = *b;
	len_a = stack_length(tmp_a);
	len_b = stack_length(tmp_b);
	while (tmp_b)
	{
		tmp_b->b_cost = calculate_cost(tmp_b->pos, len_b);
		tmp_b->a_cost = calculate_cost(tmp_b->target, len_a);
		tmp_b = tmp_b->next;
	}
}
