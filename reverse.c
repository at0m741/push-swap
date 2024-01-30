/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltouzali <ltouzali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 16:50:31 by ltouzali          #+#    #+#             */
/*   Updated: 2024/01/24 14:17:24 by ltouzali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reversea(t_stack **stack, int s)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (*stack && (*stack)->next)
	{
		tmp = *stack;
		tmp2 = *stack;
		while (tmp->next)
			tmp = tmp->next;
		while (tmp2->next->next)
			tmp2 = tmp2->next;
		tmp->next = *stack;
		tmp2->next = NULL;
		*stack = tmp;
		if (s)
			ft_putstr("rra\n");
	}
}

void	reverseb(t_stack **stack, int s)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (*stack && (*stack)->next)
	{
		tmp = *stack;
		tmp2 = *stack;
		while (tmp->next)
			tmp = tmp->next;
		while (tmp2->next->next)
			tmp2 = tmp2->next;
		tmp->next = *stack;
		tmp2->next = NULL;
		*stack = tmp;
		if (s)
			ft_putstr("rrb\n");
	}
}

void	reverseab(t_stack **stackA, t_stack **stackB)
{
	reversea(stackA, 0);
	reverseb(stackB, 0);
	ft_putstr("rrr\n");
}
