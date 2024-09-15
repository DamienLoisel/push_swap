/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manip.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dloisel <dloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:57:23 by dloisel           #+#    #+#             */
/*   Updated: 2024/06/25 16:08:35 by dloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_add_to_stack(t_stack	*stack, t_stack_node *new_element)
{
	if (stack->stack_node == NULL)
	{
		stack->stack_node = new_element;
		stack->stack_node->next = new_element;
		stack->stack_node->prev = new_element;
	}
	else
	{
		stack->stack_node->prev->next = new_element;
		new_element->prev = stack->stack_node->prev;
		new_element->next = stack->stack_node;
		stack->stack_node->prev = new_element;
	}
	stack->size++;
}

t_stack_node	*ft_new_element(long value, t_stack *stack_a, char **str)
{
	t_stack_node	*new_element;

	if ((value) > INT_MAX || (value) < INT_MIN)
		return (ft_error(stack_a, str), NULL);
	new_element = malloc(sizeof(t_stack_node));
	if (!new_element)
		return (ft_error(stack_a, str), NULL);
	new_element->value = value;
	new_element->next = new_element;
	new_element->prev = new_element;
	return (new_element);
}
