/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dloisel <dloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 17:21:51 by dloisel           #+#    #+#             */
/*   Updated: 2024/06/29 20:50:58 by dloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../include/ft_printf/ft_printf.h"
# include "../include/libft/libft.h"
# include "../include/push_swap.h"
# include "../include/get_next_line/get_next_line.h"
# include <limits.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>

void	ft_instruction_parsing(char *instructions, \
t_stack *stack_a, t_stack *stack_b);

#endif
