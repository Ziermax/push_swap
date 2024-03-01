/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:30:44 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/02/28 17:51:57 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTER_H

# define SORTER_H

/*	Functions of stack_info file	*/
int		stack_len(t_stack *stack);
t_stack	*stack_smallest(t_stack *stack, t_stack *bottom);
t_stack	*stack_biggest(t_stack *stack, t_stack *top);
t_stack	*stack_middle(t_stack *stack);
int		check_sorted(int smallest, t_stack *stack);
/*	Functions of set_stack file		*/
int		find_cost(t_stack *stack, t_stack *to_top);
t_stack	*find_target(t_stack *target_stack, t_stack *to_push);
int		find_total_cost(int cost_a, int cost_b);
t_stack	*find_smallest_cost(t_stack *stack);
void	set_total_cost(t_stack *stack_a, t_stack *stack_b);
/*	Functions of sort_moves file	*/
void	swap_stack(t_stack **stack, int print);
void	push_stack(t_stack **from, t_stack **to, int print);
void	rotate_stack(t_stack **stack, int print);
void	rev_rot_stack(t_stack **stack, int print);
/*	Functions of advance_moves file	*/
void	top_node(t_stack *node, t_stack **stack, int print);
void	ultra_top(t_stack *ideal, t_stack **stack_a, t_stack **stack_b);

#endif
