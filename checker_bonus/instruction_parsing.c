/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_parsing.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dloisel <dloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 19:52:55 by dloisel           #+#    #+#             */
/*   Updated: 2024/06/29 21:17:47 by dloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && (s1[i] != '\0' || s2[i] != '\0'))
		i++;
	return (s1[i] - s2[i]);
}

static void	ft_free_all(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->stack_node)
		ft_free_push_swap(stack_a, NULL);
	if (stack_b->stack_node)
		ft_free_push_swap(stack_b, NULL);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	ft_instruction_parsing(char *instructions, \
t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strcmp(instructions, "sa\n") == 0)
		sa(stack_a, false);
	else if (ft_strcmp(instructions, "sb\n") == 0)
		sb(stack_b, false);
	else if (ft_strcmp(instructions, "ss\n") == 0)
		ss(stack_a, stack_b, false);
	else if (ft_strcmp(instructions, "pa\n") == 0)
		pa(stack_a, stack_b, false);
	else if (ft_strcmp(instructions, "pb\n") == 0)
		pb(stack_a, stack_b, false);
	else if (ft_strcmp(instructions, "ra\n") == 0)
		ra(stack_a, false);
	else if (ft_strcmp(instructions, "rb\n") == 0)
		rb(stack_b, false);
	else if (ft_strcmp(instructions, "rr\n") == 0)
		rr(stack_a, stack_b, false);
	else if (ft_strcmp(instructions, "rra\n") == 0)
		rra(stack_a, false);
	else if (ft_strcmp(instructions, "rrb\n") == 0)
		rrb(stack_b, false);
	else if (ft_strcmp(instructions, "rrr\n") == 0)
		rrr(stack_a, stack_b, false);
	else
		ft_free_all(stack_a, stack_b);
}
