/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   primary_movements_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:38:56 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/02/29 16:39:26 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	Swap between first and second node in stack
 *	*/
void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!*stack)
		return ;
	if (!(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	*stack = second;
	second->next = first;
}

/*	Push first node of from-stack to the start of to-stack
 *	*/
void	push(t_stack **from, t_stack **to)
{
	t_stack	*first;

	if (!*from)
		return ;
	first = *from;
	*from = first->next;
	first->next = *to;
	*to = first;
}

/*	Take first node of stack
 *	Append node to end of stack
 *	*/
void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!*stack)
		return ;
	if (!(*stack)->next)
		return ;
	first = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	*stack = first->next;
	last->next = first;
	first->next = NULL;
}

/*	Take last node of stack
 *	Append node to start of stack
 *	*/
void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*before_last;

	if (!*stack)
		return ;
	if (!(*stack)->next)
		return ;
	last = *stack;
	while (last->next)
	{
		before_last = last;
		last = last->next;
	}
	last->next = *stack;
	*stack = last;
	before_last->next = NULL;
}
