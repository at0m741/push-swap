/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltouzali <ltouzali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 16:11:52 by ltouzali          #+#    #+#             */
/*   Updated: 2024/01/24 14:17:14 by ltouzali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pusha(t_stack **stacka, t_stack **stackb)
{
	t_stack	*tmp;

	if (*stackb)
	{
		tmp = *stackb;
		*stackb = (*stackb)->next;
		tmp->next = *stacka;
		*stacka = tmp;
	}
	ft_putstr("pa\n");
}

void	pushb(t_stack **stacka, t_stack **stackb)
{
	t_stack	*tmp;

	if (*stacka)
	{
		tmp = *stacka;
		*stacka = (*stacka)->next;
		tmp->next = *stackb;
		*stackb = tmp;
	}
	ft_putstr("pb\n");
}
