/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 20:13:41 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/02/27 20:46:04 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	IF ARGUMENT COUNT == 1
 *	 SPLIT DE ARGUMENT
 *	MAKE STACK WITH ARGUMENT VECTOR
 *	FREE SPLIT IF DONE
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
	if (!stack_a->next)
		return (free_stack(&stack_a), 0);
	sort_stack(&stack_a, &stack_b);
	free_stack(&stack_a);
}
/*
void	print_stack(t_stack *stack)
{
	int	i;

	i = 0;
	if (!stack)
		printf("\n\n");
	while (stack)
	{
		printf("NODE %d\t", i++);
		printf("[%p]: ", stack);
		printf(" | nxt: '%p'", stack->next);
		if (!stack->next)
			printf("           ");
		printf(" | number: '%d'\n\n", stack->number);
		stack = stack->next;
	}
}*/
/*
void	print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	printf("\n-----------------------------------------------------\n");
	printf("StackA:\n");
	print_stack(stack_a);
	printf("-----------------------------------------------------\n");
	printf("\n-----------------------------------------------------\n");
	printf("StackB:\n");
	print_stack(stack_b);
	printf("-----------------------------------------------------\n\n");
}*/
/*
void	print_info(t_stack *stack)
{
	int	i;

	i = 0;
	if (!stack)
		printf("\n\n");
	while (stack)
	{
		printf("NODE %d\t", i++);
		printf("[%p]: ", stack);
		printf(" | number: '%d'", stack->number);
		printf(" | cost: '%d'", stack->cost);
		printf(" | TARGET [%p]: ", stack->target);
		printf(" | target_number: '%d'", stack->target->number);
		printf(" | target_cost: '%d'", stack->target->cost);
		printf(" | total_cost: '%d'\n\n", stack->total_cost);
		stack = stack->next;
	}
}*/
