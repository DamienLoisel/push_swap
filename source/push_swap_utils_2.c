/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dloisel <dloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 20:48:35 by dloisel           #+#    #+#             */
/*   Updated: 2024/06/30 18:07:25 by dloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//Deplace le premier element de b vers a
void	pa(t_stack *a, t_stack *b, bool printable)
{
	if (!b->stack_node)
		return ;
	push(a, pop(b));
	a->size++;
	b->size--;
	if (printable)
		ft_printf("%s\n", "pa");
}

//Deplace le premier element de a vers b
void	pb(t_stack *a, t_stack *b, bool printable)
{
	if (!a->stack_node)
		return ;
	push(b, pop(a));
	a->size--;
	b->size++;
	if (printable)
		ft_printf("%s\n", "pb");
}

//Fait une rotation vers le haut de la pile a
void	ra(t_stack *a, bool printable)
{
	if (!a->stack_node)
		return ;
	a->stack_node = a->stack_node->next;
	if (printable)
		ft_printf("%s\n", "ra");
}

//Fait une rotation vers le haut de la pile a
void	rb(t_stack *b, bool printable)
{
	if (!b->stack_node)
		return ;
	b->stack_node = b->stack_node->next;
	if (printable)
		ft_printf("%s\n", "rb");
}
