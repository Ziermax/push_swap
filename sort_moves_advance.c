/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_moves_advance.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:47:03 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/02/27 20:43:19 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "sorter.h"

/*	IF COST IS POSITIVE ROTATE A STACK
 *	IF COST IS NEGATIVE REVERSE ROTATE A STACK
 *	ROTATION IS MADE UNTIL NODE IS AT START OF STACK
 *	*/
void	top_node(t_stack *node, t_stack **stack, int print)
{
	int	cost;

	if (node->cost != 0)
		cost = node->cost;
	else
		cost = find_cost(*stack, node);
	if (cost >= 0)
		while (*stack != node)
			rotate_stack(stack, print);
	else
		while (*stack != node)
			rev_rot_stack(stack, print);
}

/*	ROTATE BOTH STACKS AT THE SAME TIME
 *	UNTIL BOTH NODES ARE AT START OF EACH STACK
 *	*/
void	ultra_rotate(t_stack *ideal, t_stack **stack_a, t_stack **stack_b)
{
	while (*stack_a != ideal->target && *stack_b != ideal)
	{
		rotate_stack(stack_a, 0);
		rotate_stack(stack_b, STACKS);
	}
	while (*stack_a != ideal->target)
		rotate_stack(stack_a, STACK_A);
	while (*stack_b != ideal)
		rotate_stack(stack_b, STACK_B);
}

/*	REVERSE ROTATE BOTH STACKS AT THE SAME TIME
 *	UNTIL BOTH NODES ARE AT START OF EACH STACK
 *	*/
void	ultra_rev_rot(t_stack *ideal, t_stack **stack_a, t_stack **stack_b)
{
	while (*stack_a != ideal->target && *stack_b != ideal)
	{
		rev_rot_stack(stack_a, 0);
		rev_rot_stack(stack_b, STACKS);
	}
	while (*stack_a != ideal->target)
		rev_rot_stack(stack_a, STACK_A);
	while (*stack_b != ideal)
		rev_rot_stack(stack_b, STACK_B);
}

/*	IF IDEAL AND TARGET NODE'S COST HAVE THE SAME SIGN
 *	 MAKE ULTRA_ROTATION
 *	IF NOT
 *	 MAKE TOP_NODE FOR EACH NODE
 *	*/
void	ultra_top(t_stack *ideal, t_stack **stack_a, t_stack **stack_b)
{
	if (ideal->cost > 0 && ideal->target->cost > 0)
		ultra_rotate(ideal, stack_a, stack_b);
	else if (ideal->cost < 0 && ideal->target->cost < 0)
		ultra_rev_rot(ideal, stack_a, stack_b);
	else
	{
		top_node(ideal->target, stack_a, STACK_A);
		top_node(ideal, stack_b, STACK_B);
	}
}
