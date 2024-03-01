/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:21:03 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/02/29 17:32:36 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "push_swap.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# define FAILED 5

/*	Functions used for movement		*/
void	swap(t_stack **stack);
void	push(t_stack **from, t_stack **to);
void	rotate(t_stack **stack);
void	reverse_rotate(t_stack **stack);
/*	Functions of move file			*/
void	sa(t_stack **stack_a, t_stack **stack_b);
void	sb(t_stack **stack_a, t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a, t_stack **stack_b);
void	rb(t_stack **stack_a, t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a, t_stack **stack_b);
void	rrb(t_stack **stack_a, t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
/*	Functions for execute moves		*/
void	interpretate_moves(char *text, t_stack **stack_a, t_stack **stack_b);
void	execute_moves(t_stack **stack_a, t_stack **stack_b);

#endif
