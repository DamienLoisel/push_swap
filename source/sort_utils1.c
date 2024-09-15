/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dloisel <dloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:52:37 by dloisel           #+#    #+#             */
/*   Updated: 2024/06/28 21:41:08 by dloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack_node	*ft_check_max(t_stack *stack)
{
	t_stack_node	*max;
	int				i;

	i = 0;
	max = stack->stack_node;
	while (i < stack->size)
	{
		if (stack->stack_node->value > max->value)
			max = stack->stack_node;
		stack->stack_node = stack->stack_node->next;
		i++;
	}
	return (max);
}

t_stack_node	*ft_check_min(t_stack *stack)
{
	t_stack_node	*min;
	int				i;

	i = 0;
	min = stack->stack_node;
	while (i < stack->size)
	{
		if (stack->stack_node->value < min->value)
			min = stack->stack_node;
		stack->stack_node = stack->stack_node->next;
		i++;
	}
	return (min);
}

void	ft_get_index(t_stack *stack)
{
	int	i;
	int	median;

	i = 0;
	median = stack->size / 2;
	while (i < stack->size)
	{
		stack->stack_node->index = i;
		if (i <= median)
			stack->stack_node->above_median = true;
		else
			stack->stack_node->above_median = false;
		stack->stack_node = stack->stack_node->next;
		i++;
	}
}

void	ft_set_target_node(t_stack *stack_a, t_stack *stack_b, int i, int j)
{
	t_stack_node	*current_a;
	t_stack_node	*target_node;
	long			current_best_match;

	while (++i < stack_b->size)
	{
		current_best_match = LONG_MAX;
		current_a = stack_a->stack_node;
		j = -1;
		while (++j < stack_a->size)
		{
			if (current_a->value > stack_b->stack_node->value
				&& current_a->value < current_best_match)
			{
				current_best_match = current_a->value;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (current_best_match == LONG_MAX)
			stack_b->stack_node->target_node = ft_check_min(stack_a);
		else
			stack_b->stack_node->target_node = target_node;
		stack_b->stack_node = stack_b->stack_node->next;
	}
}

void	ft_set_move_cost(t_stack *stack_a, t_stack *stack_b)
{
	int	size_a;
	int	size_b;
	int	i;

	size_a = stack_a->size;
	size_b = stack_b->size;
	i = 0;
	while (i < stack_b->size)
	{
		stack_b->stack_node->move_cost = stack_b->stack_node->index;
		if (!(stack_b->stack_node->above_median))
			stack_b->stack_node->move_cost = size_b - \
			(stack_b->stack_node->index);
		if (stack_b->stack_node->target_node->above_median)
			stack_b->stack_node->move_cost += \
			stack_b->stack_node->target_node->index;
		else
			stack_b->stack_node->move_cost += size_a - \
			(stack_b->stack_node->target_node->index);
		stack_b->stack_node = stack_b->stack_node->next;
		i++;
	}
}
