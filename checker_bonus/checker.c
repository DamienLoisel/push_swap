/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dloisel <dloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 17:49:17 by dloisel           #+#    #+#             */
/*   Updated: 2024/06/29 21:27:15 by dloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	char	*instruction;

	stack_a.stack_node = NULL;
	stack_b.stack_node = NULL;
	stack_a.size = 0;
	stack_b.size = 0;
	if (argc < 3)
		exit(1);
	stack_init(&stack_a, argc, argv);
	while (1)
	{
		instruction = get_next_line(1);
		if (instruction == NULL)
			break ;
		ft_instruction_parsing(instruction, &stack_a, &stack_b);
		free(instruction);
	}
	if (ft_is_sorted(&stack_a) == 1 && stack_b.stack_node == NULL)
		return (ft_putstr_fd("OK\n", 1), ft_free_push_swap(&stack_a, NULL), 0);
	else
		return (ft_putstr_fd("KO\n", 1), ft_free_push_swap(&stack_a, NULL), \
		ft_free_push_swap(&stack_b, NULL), 1);
	return (0);
}
