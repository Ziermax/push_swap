/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stack_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 17:24:24 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/02/27 20:43:25 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "sorter.h"

/*	CALCULATE ROTATIONS NEEDED TO TOP A NODE
 *	RETURN NUMBER AND DIRECTION OF ROTATIONS
 *	*/
int	find_cost(t_stack *stack, t_stack *to_top)
{
	int	middle;
	int	position;

	middle = stack_len(stack);
	position = 0;
	while (stack)
	{
		if (stack == to_top)
			break ;
		position += 1;
		stack = stack->next;
	}
	if (position <= middle / 2)
		return (position);
	return (position - middle);
}

/*	FIND A NODE IN STACK WITH THE SMALLEST NUMBER
 *	THAT IS GREATER THAN TO-PUSH-NODE'S NUMBER
 *	RETURN NODE'S DIRECTION
 *	IF NO NUMBER IS GREATER THAN TO-PUSH-NODE'S NUMBER
 *	 RETURN SMALLEST-NUMBER-NODE IN STACK
 *	*/
t_stack	*find_target(t_stack *target_stack, t_stack *to_push)
{
	t_stack	*target;

	target = stack_smallest(target_stack, to_push);
	if (!target)
		target = stack_smallest(target_stack, NULL);
	return (target);
}

/*	RETURN NUMBER WITHOUT SIGN
 *	*/
int	modulus(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}

/*	IF THE 2 COSTS HAVE THE SAME SIGN
 *	 RETURN GREATER COST
 *	IF NOT
 *	 RETURN THE SUM OF BOTH
 *	*/
int	find_total_cost(int cost_a, int cost_b)
{
	int	modulus_a;
	int	modulus_b;

	modulus_a = modulus(cost_a);
	modulus_b = modulus(cost_b);
	if ((cost_a < 0 && cost_b < 0) || (cost_a > 0 && cost_b > 0))
	{
		if (modulus_a > modulus_b)
			return (modulus_a);
		else
			return (modulus_b);
	}
	return (modulus_a + modulus_b);
}

/*	SEARCH IN STACK FOR THE NODE WITH THE SMALLEST TOTAL COST
 *	RETURN NODE'S DIRECTION
 *	*/
t_stack	*find_smallest_cost(t_stack	*stack)
{
	int		smallest;
	t_stack	*smallest_node;

	smallest = 2147483647;
	smallest_node = NULL;
	if (stack->total_cost == 0)
		return (stack);
	while (stack)
	{
		if (stack->total_cost < smallest)
		{
			smallest = stack->total_cost;
			smallest_node = stack;
		}
		stack = stack->next;
	}
	return (smallest_node);
}
