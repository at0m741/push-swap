/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltouzali <ltouzali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:50:39 by ltouzali          #+#    #+#             */
/*   Updated: 2024/01/19 16:49:38 by ltouzali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_index(t_stack *stack, int value)
{
	int	i;

	i = 1;
	while (stack)
	{
		if (value == 0)
		{
			i = 0;
			break ;
		}
		if (stack->value < value)
			i++;
		stack = stack->next;
	}
	return (i);
}

void	set_lst_to_index(t_stack *a)
{
	t_stack	*tmp;

	tmp = ft_lstcopy(a);
	if (!tmp)
		return ;
	while (a)
	{
		a->value = ft_index(tmp, a->value);
		a = a->next;
	}
	freelst(tmp);
}

int	ft_strlen(char *c)
{
	int	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}
