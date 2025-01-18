/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_cheker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iriadyns <iriadyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:22:31 by iriadyns          #+#    #+#             */
/*   Updated: 2024/11/28 13:34:07 by iriadyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

bool	ft_strequ(const char *s1, const char *s2)
{
	if (!s1 || !s2)
		return (false);
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 == '\0' && *s2 == '\0');
}

bool	apply_instruction(char *line, t_stack **a, t_stack **b)
{
	if (ft_strequ(line, "sa\n"))
		sa(a);
	else if (ft_strequ(line, "sb\n"))
		sb(b);
	else if (ft_strequ(line, "ss\n"))
		ss(a, b);
	else if (ft_strequ(line, "pa\n"))
		pa(a, b);
	else if (ft_strequ(line, "pb\n"))
		pb(a, b);
	else if (ft_strequ(line, "ra\n"))
		ra(a);
	else if (ft_strequ(line, "rb\n"))
		rb(b);
	else if (ft_strequ(line, "rr\n"))
		rr(a, b);
	else if (ft_strequ(line, "rra\n"))
		rra(a);
	else if (ft_strequ(line, "rrb\n"))
		rrb(b);
	else if (ft_strequ(line, "rrr\n"))
		rrr(a, b);
	else
		return (false);
	return (true);
}

void	read_instructions(t_stack **stack_a, t_stack **stack_b)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
		{
			break ;
		}
		if (!apply_instruction(line, stack_a, stack_b))
		{
			free(line);
			ft_putendl_fd("Error", 2);
			exit(EXIT_FAILURE);
		}
		free(line);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	stack_b = NULL;
	stack_a = parse_arguments(argc, argv);
	read_instructions(&stack_a, &stack_b);
	if (stack_is_sorted(stack_a) && !stack_b)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
