/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltouzali <ltouzali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:35:47 by ltouzali          #+#    #+#             */
/*   Updated: 2024/01/24 14:17:46 by ltouzali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotatea(t_stack **stacka, int s)
{
	t_stack	*temp;
	t_stack	*last;

	if (*stacka && (*stacka)->next)
	{
		temp = *stacka;
		*stacka = (*stacka)->next;
		temp->next = NULL;
		last = *stacka;
		while (last->next)
		{
			last = last->next;
		}
		last->next = temp;
		if (s)
			ft_putstr("ra\n");
	}
}

void	rotateb(t_stack **stackB, int s)
{
	t_stack	*temp;
	t_stack	*last;

	if (*stackB && (*stackB)->next)
	{
		temp = *stackB;
		*stackB = (*stackB)->next;
		temp->next = NULL;
		last = *stackB;
		while (last->next)
		{
			last = last->next;
		}
		last->next = temp;
		if (s)
			ft_putstr("rb\n");
	}
}

void	rotateab(t_stack **stacka, t_stack **stackB)
{
	rotatea(stacka, 0);
	rotateb(stackB, 0);
	ft_putstr("rr\n");
}
