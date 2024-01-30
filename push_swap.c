/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltouzali <ltouzali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:32:49 by ltouzali          #+#    #+#             */
/*   Updated: 2024/01/24 16:49:08 by ltouzali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_choice(t_stack **stackA, t_stack **stackB)
{
	int	len;

	len = stack_size(*stackA);
	if (len == 1)
		return ;
	if (len <= 3)
		big_brain_sort(stackA);
	else if (len <= 5)
		sort_five(stackA, stackB);
	else
	{
		butterfly_sort(stackA, stackB);
		big_brain_sort(stackA);
		find_best_try_to_pusha(stackA, stackB);
	}
}

t_stack	*add_to_stack(char *num_str, t_stack *stacka)
{
	int		k;
	long	num;

	k = 0;
	num = ft_atol(num_str);
	while (num_str[k])
	{
		if (!ft_isdigit(num_str[k]))
		{
			freelst(stacka);
			error_checker();
			return (NULL);
		}
		k++;
	}
	if (num > INT_MAX || num < INT_MIN)
	{
		freelst(stacka);
		error_checker();
		return (NULL);
	}
	else
		ft_lstadd_back(&stacka, ft_lstnew(ft_atol(num_str)));
	return (stacka);
}

t_stack	*process_arg(char *arg, t_stack *stacka)
{
	char	**tab;
	int		j;

	j = 0;
	tab = ft_split(arg, ' ');
	if (!tab || !tab[0])
	{
		cleanup(stacka, tab);
		error_checker();
		return (NULL);
	}
	while (tab[j])
	{
		stacka = add_to_stack(tab[j], stacka);
		if (!stacka)
		{
			cleanup(stacka, tab);
			error_checker();
			return (NULL);
		}
		j++;
	}
	freetab(tab);
	return (stacka);
}

int	parser(char *argv)
{
	if (ft_isnum(argv) == 0)
	{
		return (1);
	}
	return (0);
}

t_stack	*spliter(char **argv)
{
	t_stack	*stacka;
	int		i;

	i = 1;
	stacka = NULL;
	while (argv[i])
	{
		stacka = process_arg(argv[i], stacka);
		if (!stacka)
			return (NULL);
		if (check_doublon(stacka) == 1 && check_if_sorted(stacka) != 0)
		{
			freelst(stacka);
			error_checker();
			return (NULL);
		}
		i++;
	}
	return (stacka);
}
