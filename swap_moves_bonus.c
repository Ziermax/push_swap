/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_moves_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:37:56 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/02/29 16:37:59 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	sa(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	stack_b = NULL;
}

void	sb(t_stack **stack_a, t_stack **stack_b)
{
	stack_a = NULL;
	swap(stack_b);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
}
