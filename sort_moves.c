/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:54:43 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/02/25 16:27:35 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	SWAP FIRST AND SECOND NODE OF STACK
 *	WRITE STACK SWAPED
 *	*/
void	swap_stack(t_stack **stack, int print)
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
	if (print == STACK_A)
		write(1, "sa\n", 3);
	else if (print == STACK_B)
		write(1, "sb\n", 3);
	else if (print == STACKS)
		write(1, "ss\n", 3);
}

/*	PUSH FIRST NODE FROM A STACK TO START OF ANOTHER STACK
 *	WRITE STACK PUSHED
 *	*/
void	push_stack(t_stack **from, t_stack **to, int print)
{
	t_stack	*first;

	if (!*from)
		return ;
	first = *from;
	*from = first->next;
	first->next = *to;
	*to = first;
	if (print == STACK_B)
		write(1, "pa\n", 3);
	else if (print == STACK_A)
		write(1, "pb\n", 3);
}

/*	TAKES STACK'S FIRST NODE AND APPEND IT TO END OF STACK
 *	WRITE STACK ROTATED
 *	*/
void	rotate_stack(t_stack **stack, int print)
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
	if (print == STACK_A)
		write(1, "ra\n", 3);
	else if (print == STACK_B)
		write(1, "rb\n", 3);
	else if (print == STACKS)
		write(1, "rr\n", 3);
}

/*	TAKES STACK'S LAST NODE AND APPEND IT TO START OF STACK
 *	WRITE STACK REVERSE ROTATED
 *	*/
void	rev_rot_stack(t_stack **stack, int print)
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
	if (print == STACK_A)
		write(1, "rra\n", 4);
	else if (print == STACK_B)
		write(1, "rrb\n", 4);
	else if (print == STACKS)
		write(1, "rrr\n", 4);
}
