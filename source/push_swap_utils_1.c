/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dloisel <dloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 20:27:18 by dloisel           #+#    #+#             */
/*   Updated: 2024/06/27 15:06:53 by dloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//Ajout au sommet de la pile
void	push(t_stack *stack, int value)
{
	t_stack_node	*new_node;
	t_stack_node	*tail;

	new_node = malloc(sizeof(t_stack_node));
	if (!new_node)
		return ;
	new_node->value = value;
	if (stack->stack_node == NULL)
	{
		new_node->next = new_node;
		new_node->prev = new_node;
	}
	else
	{
		tail = stack->stack_node->prev;
		new_node->next = stack->stack_node;
		new_node->prev = tail;
		tail->next = new_node;
		stack->stack_node->prev = new_node;
	}
	stack->stack_node = new_node;
}

//Retire un node du sommet de la pile
int	pop(t_stack *stack)
{
	int				value;
	t_stack_node	*head;
	t_stack_node	*new_head;
	t_stack_node	*tail;

	if (stack == NULL)
		return (-1);
	head = stack->stack_node;
	value = head->value;
	if (head == head->next)
	{
		free(head);
		stack->stack_node = NULL;
	}
	else
	{
		tail = head->prev;
		new_head = head->next;
		tail->next = new_head;
		new_head->prev = tail;
		free(head);
		stack->stack_node = new_head;
	}
	return (value);
}

//Inverse les 2 premiers elements de a
void	sa(t_stack *a, bool printable)
{
	int	temp;

	if (!a->stack_node || !a->stack_node->next)
		return ;
	temp = a->stack_node->value;
	a->stack_node->value = a->stack_node->next->value;
	a->stack_node->next->value = temp;
	if (printable)
		ft_printf("%s\n", "sa");
}

//Inverse les 2 premiers elements de b
void	sb(t_stack *b, bool printable)
{
	int	temp;

	if (!b->stack_node || !b->stack_node->next)
		return ;
	temp = b->stack_node->value;
	b->stack_node->value = b->stack_node->next->value;
	b->stack_node->next->value = temp;
	if (printable)
		ft_printf("%s\n", "sb");
}

//Fait sa() et sb() en meme temps
void	ss(t_stack *a, t_stack *b, bool printable)
{
	sa(a, false);
	sb(b, false);
	if (printable)
		ft_printf("%s\n", "ss");
}
