/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:19:34 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/02/27 20:39:18 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "sorter.h"

/*	PUSH EVERY NODE IN STACK A TO STACK B
 *	UNTIL THERE ARE 3 NODES LEFT IN STACK A
 *	IF PUSHED NODE IS ABOVE MIDDLE'S NUMBER VALUE
 *	 ROTATE STACK B TO PUT LAST NODE PUSHED
 *	*/
void	push_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int		nodes;
	t_stack	*middle;

	nodes = stack_len(*stack_a);
	middle = stack_middle(*stack_a);
	if (nodes-- > 3)
		push_stack(stack_a, stack_b, STACK_A);
	if (nodes == 4)
	{
		nodes -= 1;
		push_stack(stack_a, stack_b, STACK_A);
	}
	while (nodes > 3)
	{
		push_stack(stack_a, stack_b, STACK_A);
		if ((*stack_b)->number > middle->number)
			rotate_stack(stack_b, STACK_B);
		nodes--;
	}
}

/*	SORT A STACK WITH 3 NODES
 *	PUT LAST BIGGEST NUMBER NODE
 *	SWAP FIRST AND SECOND NODE IF FIRST IS GREATER THAN SECOND
 *	*/
void	sort_three(t_stack **stack, int print)
{
	t_stack	*biggest;

	biggest = stack_biggest(*stack, NULL);
	if ((*stack)->number == biggest->number)
		rotate_stack(stack, print);
	if ((*stack)->next->number == biggest->number)
		rev_rot_stack(stack, print);
	if ((*stack)->number > (*stack)->next->number)
		swap_stack(stack, print);
}

/*	SET TOTAL COST OF STACK B
 *	RAISE SMALLEST-COST AND ITS TARGET NODES
 *	PUSH SMALLEST-COST NODE TO STACK A
 *	UNTIL STACK B IS EMPTY
 *	*/
void	push_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*ideal;

	while (*stack_b)
	{
		set_total_cost(*stack_a, *stack_b);
		ideal = find_smallest_cost(*stack_b);
		ultra_top(ideal, stack_a, stack_b);
		(*stack_b)->cost = 0;
		push_stack(stack_b, stack_a, STACK_B);
	}
}

/*	IF STACK IS SORTED
 *	 TOP SMALLEST NUMBER NODE TO START OF LIST
 *	IF NOT
 *	 MAKE SORT OPERATIONS - TOP SMALLEST NUMBER NODE TO START OF LIST
 *	*/
void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*smallest;

	smallest = stack_smallest(*stack_a, NULL);
	if (check_sorted(smallest->number, *stack_a))
		return (top_node(smallest, stack_a, STACK_A));
	push_a_to_b(stack_a, stack_b);
	sort_three(stack_a, STACK_A);
	push_b_to_a(stack_a, stack_b);
	smallest->cost = 0;
	top_node(smallest, stack_a, STACK_A);
}
