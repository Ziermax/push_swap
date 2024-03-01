/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:10:38 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/02/28 17:54:22 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define STACK_A 69
# define STACK_B 420
# define STACKS 5
# define MAX_INT 2147483648

typedef struct s_stack
{
	int				number;
	int				cost;
	int				total_cost;
	struct s_stack	*target;
	struct s_stack	*next;
}	t_stack;

/*	Functions for printing stack info	*/
//void	print_stack(t_stack *stack);
//void	print_stacks(t_stack *stack_a, t_stack *stack_b);
//void	print_info(t_stack *stack);
/*	Functions of split file		*/
char	**split_arg(char *str, int *arg_count, char c);
void	free_split(char **split, int words);
/*	Functions of stacking file	*/
t_stack	*make_stack(int count, char **nums);
void	free_stack(t_stack **stack);
/*	Function of sorter file		*/
void	sort_stack(t_stack **stack_a, t_stack **stack_b);

#endif
