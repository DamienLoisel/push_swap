/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dloisel <dloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 15:22:47 by dloisel           #+#    #+#             */
/*   Updated: 2024/06/27 17:31:31 by dloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_free_split(char	**str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ft_error(t_stack *stack, char **str)
{
	ft_putstr_fd("Error\n", 2);
	ft_free_push_swap(stack, str);
	exit(1);
}

void	ft_free_push_swap(t_stack *stack, char **str)
{
	int				i;
	t_stack_node	*tmp;

	i = 0;
	while (i < stack->size)
	{
		tmp = stack->stack_node->next;
		free(stack->stack_node);
		stack->stack_node = tmp;
		i++;
	}
	if (str)
		ft_free_split(str);
}
