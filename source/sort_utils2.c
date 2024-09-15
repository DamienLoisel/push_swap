/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dloisel <dloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 20:35:25 by dloisel           #+#    #+#             */
/*   Updated: 2024/06/28 21:56:55 by dloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_set_cheapest(t_stack *stack)
{
	t_stack_node	*cheapest_node;
	t_stack_node	*current;
	long			cheapest_value;
	int				i;

	cheapest_value = LONG_MAX;
	i = 0;
	if (!stack)
		return ;
	current = stack->stack_node;
	while (i < stack->size)
	{
		if (cheapest_value > current->move_cost)
		{
			cheapest_value = current->move_cost;
			cheapest_node = current;
		}
		current->cheapest = false;
		current = current->next;
		i++;
	}
	cheapest_node->cheapest = true;
}

t_stack_node	*ft_get_cheapest(t_stack *stack)
{
	t_stack_node	*cheapest;
	int				i;

	i = 0;
	cheapest = NULL;
	while (i < stack->size)
	{
		if (stack->stack_node->cheapest)
			cheapest = stack->stack_node;
		i++;
		stack->stack_node = stack->stack_node->next;
	}
	return (cheapest);
}

void	ft_rotate_both(t_stack *stack_a, t_stack *stack_b, t_stack_node \
*cheapest_node)
{
	while (stack_b->stack_node != cheapest_node && \
	stack_a->stack_node != cheapest_node->target_node)
		rr(stack_a, stack_b, true);
	ft_get_index(stack_a);
	ft_get_index(stack_b);
}

void	ft_reverse_rotate_both(t_stack *stack_a, t_stack *stack_b, \
t_stack_node *cheapest_node)
{
	while (stack_b->stack_node != cheapest_node \
	&& stack_a->stack_node != cheapest_node->target_node)
		rrr(stack_a, stack_b, true);
	ft_get_index(stack_a);
	ft_get_index(stack_b);
}

void	ft_correct_rotate(t_stack *stack, t_stack_node *top_node, \
char which_stack)
{
	while (stack->stack_node != top_node)
	{
		if (which_stack == 'a')
		{
			if (top_node->above_median)
				ra(stack, true);
			else
				rra(stack, true);
		}
		else if (which_stack == 'b')
		{
			if (top_node->above_median)
				rb(stack, true);
			else
				rrb(stack, true);
		}
	}
}
