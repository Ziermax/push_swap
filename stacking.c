/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:49:16 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/02/25 20:50:17 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	FREE EVERY NODE IN STACK
 *	SET STACK'S POINTER TO NULL
 *	*/
void	free_stack(t_stack **stack)
{
	t_stack	*aux;
	t_stack	*tmp;

	if (!*stack)
		return ;
	aux = *stack;
	while (aux)
	{
		tmp = aux->next;
		free(aux);
		aux = tmp;
	}
	*stack = NULL;
}

/*	APPEND A NODE TO END OF STACK
 *	RETURN NODE APPENDED
 *	IF MALLOC FAILS
 *	 FREE STACK - RETURN NULL
 *	*/
t_stack	*push_node_end_stack(t_stack **stack)
{
	t_stack	*aux;
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (free_stack(stack), NULL);
	node->cost = 0;
	node->total_cost = 0;
	node->target = NULL;
	node->next = NULL;
	if (!*stack)
		return (*stack = node);
	aux = *stack;
	while (aux->next)
		aux = aux->next;
	aux->next = node;
	return (node);
}

/*	TAKE STRING AND TURN IT INTO INTEGER
 *	ADD INTEGER TO NODE'S NUMBER VAR
 *	IF STRING HAS WRONG FORMAT-NUMBER
 *	 FREE LIST
 *	*/
void	set_nbr_to_node(char *num, t_stack *node, t_stack **stack)
{
	long	nbr;
	int		sign;

	nbr = 0;
	sign = 1;
	if (*num == '-' || *num == '+')
	{
		if (*num == '-')
			sign = -1;
		num++;
		if (!*num)
			return (free_stack(stack));
	}
	while (*num)
	{
		if (*num < '0' || *num > '9')
			return (free_stack(stack));
		nbr = nbr * 10 + *num - '0';
		if ((nbr >= MAX_INT && sign > 0) || (nbr > MAX_INT && sign < 0))
			return (free_stack(stack));
		num++;
	}
	node->number = nbr * sign;
}

/*	SEARCH NUMBER IN STACK EXCEPT IN LAST NODE
 *	IF FOUND
 *	 FREE LIST
 *	*/
void	check_repeated(int number, t_stack **stack)
{
	t_stack	*aux;

	aux = *stack;
	while (aux->next)
	{
		if (number == aux->number)
			return (free_stack(stack));
		aux = aux->next;
	}
}

/*	MAKE STACK FROM ARRAY OF STRINGS
 *	RETURN STACK MADE
 *	IF STACK-MAKING FAIL
 *	 RETURN NULL
 *	*/
t_stack	*make_stack(int count, char **nums)
{
	t_stack	*stack;
	t_stack	*node;

	stack = NULL;
	while (count--)
	{
		node = push_node_end_stack(&stack);
		if (!node)
			return (NULL);
		set_nbr_to_node(*nums, node, &stack);
		if (!stack)
			return (NULL);
		check_repeated(node->number, &stack);
		if (!stack)
			return (NULL);
		nums++;
	}
	return (stack);
}
