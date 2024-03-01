/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:50:21 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/02/29 16:44:19 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

/*	if argument count == 1
 *	 Split the argument
 *	Make stack with the argument vector
 *	Free split if done
 *	*/
t_stack	*ultra_make_stack(int argc, char **argv)
{
	t_stack	*stack;
	int		numbers;

	numbers = argc;
	if (argc == 1)
		argv = split_arg(*argv, &numbers, ' ');
	if (!argv)
		return (NULL);
	stack = make_stack(numbers, argv);
	if (argc == 1)
		free_split(argv, numbers);
	return (stack);
}

/*	Go throw every node in stack
 *	return 1 if every number is less than next number
 *	return 0 if found a number greater than next number
 *	*/
int	is_full_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->number > stack->next->number)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
		return (0);
	stack_a = ultra_make_stack(argc - 1, argv + 1);
	stack_b = NULL;
	if (!stack_a)
		return (write(2, "Error\n", 6));
	execute_moves(&stack_a, &stack_b);
	if (!stack_a && !stack_b)
		return (write(2, "Error\n", 6));
	if (is_full_sorted(stack_a) && stack_b == NULL)
		return (free_stack(&stack_a), write(1, "OK\n", 3));
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (write(1, "KO\n", 3));
}
