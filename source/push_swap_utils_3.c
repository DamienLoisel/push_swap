/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dloisel <dloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 21:02:58 by dloisel           #+#    #+#             */
/*   Updated: 2024/06/29 20:54:45 by dloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rr(t_stack *a, t_stack *b, bool printable)
{
	ra(a, false);
	rb(b, false);
	if (printable)
		ft_printf("%s\n", "rr");
}

//Le dernier elements de a devient le premier element de a
void	rra(t_stack *a, bool printable)
{
	if (!a->stack_node)
		return ;
	a->stack_node = a->stack_node->prev;
	if (printable)
		ft_printf("%s\n", "rra");
}

//Le dernier elements de b devient le premier element de b
void	rrb(t_stack *b, bool printable)
{
	if (!b->stack_node)
		return ;
	b->stack_node = b->stack_node->prev;
	if (printable)
		ft_printf("%s\n", "rrb");
}

//rra et rrb en meme temps
void	rrr(t_stack *a, t_stack *b, bool printable)
{
	rra(a, false);
	rrb(b, false);
	if (printable)
		ft_printf("%s\n", "rrr");
}
