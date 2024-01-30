/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltouzali <ltouzali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:32:39 by ltouzali          #+#    #+#             */
/*   Updated: 2024/01/21 15:55:13 by ltouzali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	big_brain_sort(t_stack **a)
{
	int	max;

	max = find_max(*a);
	if (max == (*a)->next->value)
		reversea(a, 1);
	if (max == (*a)->value)
		rotatea(a, 1);
	if ((*a)->value > (*a)->next->value)
		swapa(a);
}

void	sort_five(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(*a);
	while (size > 3)
	{
		if ((*a)->value == 4)
		{
			pushb(a, b);
			rotateb(b, 1);
			size--;
		}
		else if ((*a)->value == 5)
		{
			pushb(a, b);
			size--;
		}
		else
			rotatea(a, 1);
	}
	big_brain_sort(a);
	pusha(a, b);
	pusha(a, b);
	while (check_if_sorted(*a) == 0)
		rotatea(a, 1);
}

void	butterfly_sort(t_stack **a, t_stack **b)
{
	int	size;
	int	min;
	int	median;

	while (stack_size(*a) > 3)
	{
		size = stack_size(*a);
		min = size / 2;
		if (min < 3)
			min = 3;
		median = (size - min) / 2 + min;
		while (size > 3 && size > min)
		{
			if ((*a)->value > min)
			{
				pushb(a, b);
				if ((*b)->value < median && stack_size(*b) > 1)
					rotateb(b, 1);
				size--;
			}
			else
				rotatea(a, 1);
		}
	}
	big_brain_sort(a);
}

void	find_best_try_to_pusha(t_stack **a, t_stack **b)
{
	while (*b)
	{
		if (index_find_max(*b) < stack_size(*b) / 2)
		{
			while ((*b)->value != find_max(*b))
				rotateb(b, 1);
			pusha(a, b);
		}
		else
		{
			while ((*b)->value != find_max(*b))
				reverseb(b, 1);
			if (ft_lstlast(*b)->value > (*b)->value)
				reversea(a, 1);
			else
				pusha(a, b);
		}
	}
	reversea(a, 1);
	reversea(a, 1);
	reversea(a, 1);
}
