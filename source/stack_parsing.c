/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dloisel <dloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:26:56 by dloisel           #+#    #+#             */
/*   Updated: 2024/06/26 16:29:25 by dloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_check_duplicate(t_stack *stack_a)
{
	int				i;
	int				j;
	t_stack_node	*head;
	t_stack_node	*tail;

	i = 0;
	head = stack_a->stack_node;
	while (i < stack_a->size)
	{
		tail = head->next;
		j = i + 1;
		while (j < stack_a->size)
		{
			if (head->value == tail->value)
				ft_error(stack_a, NULL);
			tail = tail->next;
			j++;
		}
		head = head->next;
		i++;
	}
}

int	ft_is_sorted(t_stack *stack)
{
	int				i;
	int				j;
	t_stack_node	*head;
	t_stack_node	*tail;

	i = 0;
	head = stack->stack_node;
	while (i < stack->size)
	{
		tail = head->next;
		j = i + 1;
		while (j < stack->size)
		{
			if (head->value > tail->value)
				return (0);
			tail = tail->next;
			j++;
		}
		head = head->next;
		i++;
	}
	return (1);
}
