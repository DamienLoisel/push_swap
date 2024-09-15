/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dloisel <dloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 19:45:46 by dloisel           #+#    #+#             */
/*   Updated: 2024/06/29 18:38:47 by dloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

long	ft_atol(const char *nptr, t_stack *stack, char **str)
{
	int		i;
	long	res;
	long	signe;

	i = 0;
	res = 0;
	signe = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i + 1] == '+' || nptr[i + 1] == '-')
			return (ft_error(stack, str), 0);
		else if (nptr[i] == '-')
			signe = -1;
		i++;
	}
	while ((nptr[i] != '\0'))
	{
		if ((nptr[i] < '0' || nptr[i] > '9'))
			return (ft_error(stack, str), 0);
		res = res * 10 + nptr[i] - '0';
		i++;
	}
	return (res * signe);
}

void	stack_init(t_stack *stack_a, int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 2)
		exit(1);
	if (argc == 2 && !argv[1][0])
	{
		ft_putstr_fd("Error\n", 2);
		exit(0);
	}
	else if (argc == 2)
		ft_init_quoted_str(stack_a, argv[1]);
	else
	{
		while (argv[i])
		{
			ft_add_to_stack(stack_a, \
			ft_new_element(ft_atol(argv[i], stack_a, NULL), stack_a, NULL));
			i++;
		}
	}
	ft_check_duplicate(stack_a);
}

void	ft_init_quoted_str(t_stack *stack_a, char *argv)
{
	int		i;
	char	**str;

	i = 0;
	str = ft_split(argv, ' ');
	if (str == NULL)
		ft_error(stack_a, NULL);
	while (str[i])
	{
		ft_add_to_stack(stack_a, \
		ft_new_element(ft_atol(str[i], stack_a, NULL), stack_a, str));
		i++;
	}
	ft_free_split(str);
}
