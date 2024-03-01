/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:58:28 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/02/25 16:45:50 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	MEASURE THE LENGTH OF STACK
 *	RETURN LENGTH
 *	*/
int	stack_len(t_stack *stack)
{
	int	len;

	len = 0;
	while (stack)
	{
		len += 1;
		stack = stack->next;
	}
	return (len);
}

/*	FIND SMALLEST NUMBER IN STACK GREATER THAN BOTTOM'S NUMBER
 *	IF BOTTOM IS NULL
 *	 FIND SMALLEST NUMBER IN STACK
 *	RETURN SMALLEST-NUMBER'S NODE DIRECTION
 *	*/
t_stack	*stack_smallest(t_stack *stack, t_stack *bottom)
{
	int		minimum;
	int		bot_nbr;
	t_stack	*smallest;

	minimum = 2147483647;
	smallest = NULL;
	if (bottom)
		bot_nbr = bottom->number;
	else
		bot_nbr = -2147483648;
	while (stack)
	{
		if (bottom == NULL && stack->number == -2147483648)
			return (stack);
		if (stack->number < minimum && stack->number > bot_nbr)
		{
			minimum = stack->number;
			smallest = stack;
		}
		stack = stack->next;
	}
	return (smallest);
}

/*	FIND BIGGEST NUMBER IN STACK LESS THAN TOP'S NUMBER
 *	IF TOP IS NULL
 *	 FIND BIGGEST NUMBER IN STACK
 *	RETURN BIGGEST-NUMBER'S NODE DIRECTION
 *	*/
t_stack	*stack_biggest(t_stack	*stack, t_stack *top)
{
	int		maximum;
	int		top_nbr;
	t_stack	*biggest;

	maximum = -2147483648;
	biggest = NULL;
	if (top)
		top_nbr = top->number;
	else
		top_nbr = 2147483647;
	while (stack)
	{
		if (top == NULL && stack->number == 2147483647)
			return (stack);
		if (stack->number > maximum && stack->number < top_nbr)
		{
			maximum = stack->number;
			biggest = stack;
		}
		stack = stack->next;
	}
	return (biggest);
}

/*	FIND THE MIDDLE NUMBER IN STACK
 *	RETURN MIDDLE-NUMBER'S NODE DIRECTION
 *	*/
t_stack	*stack_middle(t_stack *stack)
{
	t_stack	*biggest;
	t_stack	*smallest;

	smallest = stack_smallest(stack, NULL);
	biggest = stack_biggest(stack, NULL);
	while (smallest->number < biggest->number)
	{
		smallest = stack_smallest(stack, smallest);
		biggest = stack_biggest(stack, biggest);
	}
	return (smallest);
}

/*	SEARCH SMALLEST NUMBER IN STACK
 *	FROM THERE COMPARE THAT EVERY NUMBER IS BIGGER THAN PREVIUS NUMBER
 *	RETURN 1 IF IT ISS SORTED
 *	RETURN 0 IF NOT
 *	*/
int	check_sorted(int smallest, t_stack *stack)
{
	t_stack	*first;
	t_stack	*final;

	first = stack;
	final = stack;
	while (stack->number != smallest && stack)
		stack = stack->next;
	while (stack)
	{
		final = stack->next;
		if (!stack->next)
		{
			final = first;
			if (stack->number > first->number)
				break ;
		}
		else if (stack->number > stack->next->number)
			break ;
		stack = final;
	}
	if (final->number == smallest)
		return (1);
	return (0);
}
