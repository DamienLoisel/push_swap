/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dloisel <dloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 18:56:10 by dloisel           #+#    #+#             */
/*   Updated: 2024/06/29 19:15:35 by dloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	stack_a.stack_node = NULL;
	stack_b.stack_node = NULL;
	stack_a.size = 0;
	stack_b.size = 0;
	stack_init(&stack_a, argc, argv);
	if (!ft_is_sorted(&stack_a))
		ft_which_sort(&stack_a, &stack_b);
	ft_free_push_swap(&stack_a, NULL);
	return (0);
}
