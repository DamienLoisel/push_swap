/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dloisel <dloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:49:15 by dloisel           #+#    #+#             */
/*   Updated: 2024/06/27 15:05:10 by dloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_which_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 2)
		sa(stack_a, true);
	else if (stack_a->size == 3)
		ft_sort_3(stack_a);
	else if (stack_a->size == 4)
		ft_sort_4(stack_a, stack_b);
	else if (stack_a->size == 5)
	{
		ft_sort_5_part1(stack_a);
		ft_sort_5_part2(stack_a, stack_b);
	}
	else
		ft_big_sort(stack_a, stack_b);
}

void	ft_sort_3(t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	a = stack->stack_node->value;
	b = stack->stack_node->next->value;
	c = stack->stack_node->prev->value;
	if (a < c && c < b)
	{
		sa(stack, true);
		ra(stack, true);
	}
	else if (b < a && a < c)
		sa(stack, true);
	else if (b < c && c < a)
		ra(stack, true);
	else if (c < a && a < b)
		rra(stack, true);
	else if (c < b && b < a)
	{
		sa(stack, true);
		rra(stack, true);
	}
}

void	ft_sort_4(t_stack *stack_a, t_stack *stack_b)
{
	int	a;
	int	b;
	int	c;
	int	d;

	a = stack_a->stack_node->value;
	b = stack_a->stack_node->next->value;
	c = stack_a->stack_node->next->next->value;
	d = stack_a->stack_node->prev->value;
	if (b < a && b < c && b < d)
		ra(stack_a, true);
	else if (c < a && c < b && c < d)
	{
		ra(stack_a, true);
		ra(stack_a, true);
	}
	else if (d < a && d < b && d < c)
		rra(stack_a, true);
	pb(stack_a, stack_b, true);
	ft_sort_3(stack_a);
	pa(stack_a, stack_b, true);
}

void	ft_sort_5_part1(t_stack *stack_a)
{
	int	a;
	int	b;
	int	c;
	int	d;
	int	e;

	a = stack_a->stack_node->value;
	b = stack_a->stack_node->next->value;
	c = stack_a->stack_node->next->next->value;
	d = stack_a->stack_node->next->next->next->value;
	e = stack_a->stack_node->prev->value;
	if (b < a && b < c && b < d && b < e)
		ra(stack_a, true);
	else if (c < a && c < b && c < d && c < e)
	{
		ra(stack_a, true);
		ra(stack_a, true);
	}
	else if (d < a && d < b && d < c && d < e)
	{
		rra(stack_a, true);
		rra(stack_a, true);
	}
	else if (e < a && e < b && e < c && e < d)
		rra(stack_a, true);
}

void	ft_sort_5_part2(t_stack *stack_a, t_stack *stack_b)
{
	pb(stack_a, stack_b, true);
	ft_sort_4(stack_a, stack_b);
	pa(stack_a, stack_b, true);
}
