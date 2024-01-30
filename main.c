/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltouzali <ltouzali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:16:50 by ltouzali          #+#    #+#             */
/*   Updated: 2024/01/24 16:48:36 by ltouzali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lolilol_parser(char *argv, t_stack **stacka)
{
	int		j;
	char	**tab;

	j = 0;
	tab = ft_split(argv, ' ');
	if (tab == NULL || tab[0] == NULL)
	{
		freetab(tab);
		freelst(*stacka);
		error_checker();
	}
	while (tab[j])
	{
		if (parser(tab[j]) == 1)
		{
			freelst(*stacka);
			freetab(tab);
			error_checker();
		}
		ft_lstadd_back(stacka, ft_lstnew(ft_atol(tab[j++])));
	}
	freetab(tab);
}

void	multiple_args(int argc, char **argv, t_stack **stacka, t_stack **stackb)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		lolilol_parser(argv[i], stacka);
		i++;
	}
	if (!*stacka || check_doublon(*stacka) == 1 || \
		check_overflow(*stacka) == 1)
	{
		freelst(*stacka);
		error_checker();
	}
	if (check_if_sorted(*stacka) != 0)
	{
		freelst(*stacka);
		exit(0);
	}
	set_lst_to_index(*stacka);
	algo_choice(stacka, stackb);
}

int	main(int argc, char **argv)
{
	t_stack	*stacka;
	t_stack	*stackb;

	stacka = NULL;
	stackb = NULL;
	if (argc == 1)
		exit(0);
	if (argc < 2)
	{
		freelst(stacka);
		error_checker();
		return (0);
	}
	multiple_args(argc, argv, &stacka, &stackb);
	freelst(stacka);
	return (0);
}
