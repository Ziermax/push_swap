/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:34:33 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/03/05 20:37:34 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "sorter.h"

/*	SET EVERY NODE'S TARGET DIRECTION OF STACK
 *	*/
void	set_target(t_stack *from, t_stack *to)
{
	while (from)
	{
		from->target = find_target(to, from);
		from = from->next;
	}
}

/*	SET EVERY NODE'S COST VALUE OF STACK
 *	*/
void	set_cost(t_stack *stack)
{
	t_stack	*to_top;
	int		middle;
	int		position;

	middle = stack_len(stack);
	position = 0;
	to_top = stack;
	while (to_top)
	{
		if (position <= middle / 2)
			to_top->cost = position;
		else
			to_top->cost = position - middle;
		position += 1;
		to_top = to_top->next;
	}
}

/*	SET COST VALUES FOR EACH STACK
 *	SET TARGET DIRECTIONS FOR STACK B
 *	SET EVERY NODE'S TOTAL COST OF STACK B
 *	TOTAL COST IS THE UNION BETWEEN THE COST OF A NODE AND ITS TARGET
 *	*/
void	set_total_cost(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*curnt;

	set_cost(stack_a);
	set_cost(stack_b);
	set_target(stack_b, stack_a);
	curnt = stack_b;
	while (curnt)
	{
		curnt->total_cost = find_total_cost(curnt->cost, curnt->target->cost);
		curnt = curnt->next;
	}
}
