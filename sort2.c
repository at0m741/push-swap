/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltouzali <ltouzali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:53:01 by ltouzali          #+#    #+#             */
/*   Updated: 2024/01/17 13:56:13 by ltouzali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(t_stack *stack)
{
	int	max;

	if (stack != NULL)
		max = stack->value;
	while (stack)
	{
		if (stack->value > max)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
}

int	find_min(t_stack *stack)
{
	int	min;

	if (stack != NULL)
		min = stack->value;
	while (stack)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

int	index_find_max(t_stack *stack)
{
	int	max;
	int	i;
	int	index;

	i = 0;
	index = 0;
	if (stack != NULL)
		max = stack->value;
	while (stack)
	{
		if (stack->value > max)
		{
			max = stack->value;
			index = i;
		}
		stack = stack->next;
		i++;
	}
	return (index);
}
