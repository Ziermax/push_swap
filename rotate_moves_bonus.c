/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_moves_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:38:13 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/02/29 16:38:21 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ra(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	stack_b = NULL;
}

void	rb(t_stack **stack_a, t_stack **stack_b)
{
	stack_a = NULL;
	rotate(stack_b);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}
