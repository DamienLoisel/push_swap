/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dloisel <dloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 23:53:12 by dloisel           #+#    #+#             */
/*   Updated: 2024/06/30 17:29:23 by dloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_big_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	max_size;

	i = 0;
	max_size = stack_a->size;
	while (stack_a->size > 3)
	{
		if (stack_a->size > max_size / 2
			&& stack_a->stack_node->value < (ft_check_max(stack_a)->value
				- ft_check_min(stack_a)->value) / 2 && i++ < stack_a->size)
			ra(stack_a, 1);
		else
			pb(stack_a, stack_b, 1);
	}
	ft_sort_3(stack_a);
	while (stack_b->size > 0)
	{
		ft_find_cheapest_move(stack_a, stack_b);
		ft_apply_cheapest_move(stack_a, stack_b);
	}
	ft_get_index(stack_a);
	ft_min_on_top(stack_a);
}

void	ft_find_cheapest_move(t_stack *stack_a, t_stack *stack_b)
{
	ft_get_index(stack_a);
	ft_get_index(stack_b);
	ft_set_target_node(stack_a, stack_b, -1, -1);
	ft_set_move_cost(stack_a, stack_b);
	ft_set_cheapest(stack_b);
}

void	ft_apply_cheapest_move(t_stack *stack_a, t_stack *stack_b)
{
	t_stack_node	*cheapest;

	cheapest = ft_get_cheapest(stack_b);
	if (cheapest->above_median && cheapest->target_node->above_median)
		ft_rotate_both(stack_a, stack_b, cheapest);
	else if (!(cheapest->above_median) && \
	!(cheapest->target_node->above_median))
		ft_reverse_rotate_both(stack_a, stack_b, cheapest);
	ft_correct_rotate(stack_b, cheapest, 'b');
	ft_correct_rotate(stack_a, cheapest->target_node, 'a');
	pa(stack_a, stack_b, true);
}

void	ft_min_on_top(t_stack *stack_a)
{
	t_stack_node	*min;

	min = ft_check_min(stack_a);
	if (min->above_median)
		while (stack_a->stack_node != min)
			ra(stack_a, true);
	else
		while (stack_a->stack_node != min)
			rra(stack_a, true);
}
