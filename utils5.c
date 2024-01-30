/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltouzali <ltouzali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:01:25 by ltouzali          #+#    #+#             */
/*   Updated: 2024/01/24 16:44:09 by ltouzali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_checker(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	ft_isnum(char *c)
{
	int	i;

	i = 0;
	if (c[i] == '-' || c[i] == '+' || c[i] == ' ')
		i++;
	if (c[i] == 0)
		return (0);
	while (c[i])
	{
		if (!(c[i] >= '0' && c[i] <= '9') && c[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	cleanup(t_stack *stacka, char **tab)
{
	if (stacka)
		ft_lstclear(&stacka, free);
	if (tab)
		freetab(tab);
}
