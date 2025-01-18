/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iriadyns <iriadyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:53:38 by iriadyns          #+#    #+#             */
/*   Updated: 2024/11/28 14:17:35 by iriadyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_stack	*parse_arguments(int argc, char **argv)
{
	t_stack	*stack_a;
	int		i;
	long	value;

	stack_a = NULL;
	i = 1;
	while (i < argc)
	{
		if (!is_num(argv[i]))
			print_error();
		value = ft_atol(argv[i]);
		if (value > INT_MAX || value < INT_MIN)
		{
			print_error();
		}
		add_to_stack(&stack_a, value);
		i++;
	}
	if (has_duplicates(stack_a))
		print_error();
	return (stack_a);
}

int	is_num(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (0);
	if ((str[i] == '-' || str[i] == '+') && str[i + 1] != '\0')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
