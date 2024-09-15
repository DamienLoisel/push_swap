/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dloisel <dloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 18:55:30 by dloisel           #+#    #+#             */
/*   Updated: 2024/06/29 19:10:24 by dloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>

# define RED "\x1b[31m"
# define GREEN "\x1b[32m"
# define YELLOW "\x1b[33m"
# define BLUE "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN "\x1b[36m"
# define RESET "\x1b[0m"

typedef struct s_stack_node
{
	int					value;
	int					index;
	int					move_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*prev;
	struct s_stack_node	*next;
}	t_stack_node;

typedef struct s_stack
{
	t_stack_node	*stack_node;
	int				size;
}	t_stack;

//push_swap_utils
void			push(t_stack *stack, int value);
int				pop(t_stack *stack);
void			sa(t_stack *a, bool printable);
void			sb(t_stack *b, bool printable);
void			ss(t_stack *a, t_stack *b, bool printable);
void			pa(t_stack *a, t_stack *b, bool printable);
void			pb(t_stack *a, t_stack *b, bool printable);
void			ra(t_stack *a, bool printable);
void			rb(t_stack *b, bool printable);
void			rr(t_stack *a, t_stack *b, bool printable);
void			rra(t_stack *a, bool printable);
void			rrb(t_stack *b, bool printable);
void			rrr(t_stack *a, t_stack *b, bool printable);

//stack_init
long			ft_atol(const char *nptr, t_stack *stack, char **str);
void			stack_init(t_stack *stack_a, int argc, char **argv);
void			ft_init_quoted_str(t_stack *stack_a, char *argv);

//stack_manip
void			ft_add_to_stack(t_stack	*stack, t_stack_node *new_element);
t_stack_node	*ft_new_element(long value, t_stack *stack_a, char **str);

//stack_parsing
void			ft_check_duplicate(t_stack *stack_a);
int				ft_is_sorted(t_stack *stack);

//free_and_error
void			ft_free_split(char	**str);
void			ft_error(t_stack *stack, char **str);
void			ft_free_push_swap(t_stack *stack, char **str);

//little_sort
void			ft_which_sort(t_stack *stack_a, t_stack *stack_b);
void			ft_sort_3(t_stack *stack_a);
void			ft_sort_4(t_stack *stack_a, t_stack *stack_b);
void			ft_sort_5_part1(t_stack *stack_a);
void			ft_sort_5_part2(t_stack *stack_a, t_stack *stack_b);

//big_sort
void			ft_big_sort(t_stack *stack_a, t_stack *stack_b);
void			ft_find_cheapest_move(t_stack *stack_a, t_stack *stack_b);
void			ft_apply_cheapest_move(t_stack *stack_a, t_stack *stack_b);
void			ft_min_on_top(t_stack *stack_a);

//sort_utils1
t_stack_node	*ft_check_min(t_stack *stack);
t_stack_node	*ft_check_max(t_stack *stack);
void			ft_get_index(t_stack *stack);
void			ft_set_target_node(t_stack *stack_a, \
t_stack *stack_b, int i, int j);
void			ft_set_move_cost(t_stack *stack_a, t_stack *stack_b);

//sort_utils2
void			ft_set_cheapest(t_stack *stack);
t_stack_node	*ft_get_cheapest(t_stack *stack);
void			ft_rotate_both(t_stack *stack_a, \
t_stack *stack_b, t_stack_node *cheapest_node);
void			ft_reverse_rotate_both(t_stack *stack_a, t_stack *stack_b, \
t_stack_node *cheapest_node);
void			ft_correct_rotate(t_stack *stack, \
t_stack_node *top_node, char which_stack);
#endif
