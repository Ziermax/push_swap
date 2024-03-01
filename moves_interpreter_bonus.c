/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_interpreter_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:02:16 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/02/29 17:31:23 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

/*	Select one of three cases and execute movement read
 *	if no case is valid
 *	 Free stacks
 *	*/
void	do_swap_case(char **text, t_stack **stack_a, t_stack **stack_b)
{
	*text += 1;
	if (**text == 'a')
		sa(stack_a, stack_b);
	else if (**text == 'b')
		sb(stack_a, stack_b);
	else if (**text == 's')
		ss(stack_a, stack_b);
	else
		return (free_stack(stack_a), free_stack(stack_b));
}

/*	Select one of two cases and execute movement read
 *	if no case is valid
 *	 Free stacks
 *	*/
void	do_push_case(char **text, t_stack **stack_a, t_stack **stack_b)
{
	*text += 1;
	if (**text == 'a')
		pa(stack_a, stack_b);
	else if (**text == 'b')
		pb(stack_a, stack_b);
	else
		return (free_stack(stack_a), free_stack(stack_b));
}

/*	Select one of four cases and execute movement read
 *	if no case is valid
 *	 Free stacks
 *	*/
void	do_rev_rot_case(char **text, t_stack **stack_a, t_stack **stack_b)
{
	*text += 1;
	if (**text == '\n')
		rr(stack_a, stack_b);
	else if (**text == 'a')
		rra(stack_a, stack_b);
	else if (**text == 'b')
		rrb(stack_a, stack_b);
	else if (**text == 'r')
		rrr(stack_a, stack_b);
	else
		return (free_stack(stack_a), free_stack(stack_b));
	if (**text == '\n')
		*text -= 1;
}

/*	Select one of three cases and execute movement read
 *	if no case is valid
 *	 Free stacks
 *	*/
void	do_rotation_case(char **text, t_stack **stack_a, t_stack **stack_b)
{
	*text += 1;
	if (**text == 'a')
		ra(stack_a, stack_b);
	else if (**text == 'b')
		rb(stack_a, stack_b);
	else if (**text == 'r')
		do_rev_rot_case(text, stack_a, stack_b);
	else
		return (free_stack(stack_a), free_stack(stack_b));
}

/*	Select one of three cases
 *	if no case is valid or selection doesn't end in '\n'
 *	 Free stacks
 *	*/
void	interpretate_moves(char *text, t_stack **stack_a, t_stack **stack_b)
{
	if (*text == '\0')
		return ;
	if (*text == 's')
		do_swap_case(&text, stack_a, stack_b);
	else if (*text == 'p')
		do_push_case(&text, stack_a, stack_b);
	else if (*text == 'r')
		do_rotation_case(&text, stack_a, stack_b);
	else
		return (free_stack(stack_a), free_stack(stack_b));
	if (!*stack_a && !*stack_b)
		return ;
	text += 1;
	if (*text != '\n')
		return (free_stack(stack_a), free_stack(stack_b));
}
