/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltouzali <ltouzali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:33:07 by ltouzali          #+#    #+#             */
/*   Updated: 2024/01/27 18:01:38 by ltouzali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_stack
{
	long			value;
	struct s_stack	*next;
}	t_stack;

//moves

void	rotatea(t_stack **stack, int s);
void	rotateb(t_stack **stack, int s);
void	swapa(t_stack **stack);
void	swapb(t_stack **stack);
void	pusha(t_stack **stackA, t_stack **stackB);
void	pushb(t_stack **stackA, t_stack **stackB);
void	reversea(t_stack **stack, int s);
void	reverseb(t_stack **stack, int s);
void	reverseab(t_stack **stackA, t_stack **stackB);

//utils

void	ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_lstnew(long value);
int		stack_size(t_stack *stack);
void	butterfly_sort(t_stack **a, t_stack **b);
int		find_max(t_stack *stack);
void	big_brain_sort(t_stack **a);
long	ft_atol(const char *nptr);
void	error_checker(void);
int		ft_isnum(char *c);
int		check_doublon(t_stack *stack);
int		check_if_sorted(t_stack *stackA);
t_stack	*ft_lstcopy(t_stack *stack);
int		ft_index(t_stack *stack, int value);
void	set_lst_to_index(t_stack *a);
char	**ft_split(char const *s, char c);
int		ft_strlen(char *c);
void	freetab(char **tab);
void	freelst(t_stack *stack);
int		ft_isdigit(int c);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	cleanup(t_stack *stacka, char **tab);
void	ft_lstclear(t_stack **lst, void (*del)(void*));
t_stack	*ft_lstlast(t_stack *lst);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

//sort

int		find_min(t_stack *stack);
int		find_max(t_stack *stack);
int		index_find_max(t_stack *stack);
void	find_best_try_to_pusha(t_stack **a, t_stack **b);
void	sort_five(t_stack **a, t_stack **b);

//parser

t_stack	*spliter(char **argv);
int		parser(char *argv);
t_stack	*process_arg(char *arg, t_stack *stacka);
t_stack	*add_to_stack(char *num_str, t_stack *stacka);
void	algo_choice(t_stack **stackA, t_stack **stackB);
int		check_overflow(t_stack *stacka);
#endif