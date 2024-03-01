/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rot_moves_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:38:35 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/02/29 16:38:43 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	rra(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	stack_b = NULL;
}

void	rrb(t_stack **stack_a, t_stack **stack_b)
{
	stack_a = NULL;
	reverse_rotate(stack_b);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}
