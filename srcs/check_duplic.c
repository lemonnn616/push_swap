/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iriadyns <iriadyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:53:07 by iriadyns          #+#    #+#             */
/*   Updated: 2024/11/27 16:54:40 by iriadyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_duplicate(t_stack *start, int value)
{
	t_stack	*tmp;

	tmp = start;
	while (tmp)
	{
		if (tmp->value == value)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	stack_is_duplicated(t_stack *col)
{
	t_stack	*tmp;

	tmp = col;
	while (tmp)
	{
		if (has_duplicate(tmp->next, tmp->value))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
