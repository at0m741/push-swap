/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltouzali <ltouzali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:51:42 by ltouzali          #+#    #+#             */
/*   Updated: 2024/01/17 13:57:18 by ltouzali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstcopy(t_stack *stack)
{
	t_stack	*new;
	t_stack	*tmp;

	new = NULL;
	while (stack)
	{
		tmp = ft_lstnew(stack->value);
		ft_lstadd_back(&new, tmp);
		stack = stack->next;
	}
	return (new);
}

static int	count_word(char *s, char c)
{
	size_t	i;
	size_t	counter;

	i = 1;
	counter = 0;
	if (!*s)
		return (0);
	if (s[0] != c)
		counter++;
	while (s[i])
	{
		if (s[i] != c && s[i - 1] == c)
			counter++;
		i++;
	}
	return (counter);
}

static int	word_len(char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcpy(char *dest, const char *source, size_t len)
{
	size_t	i;

	i = 0;
	if (len != 0)
	{
		while (i < len - 1 && source[i] != '\0')
		{
			dest[i] = source[i];
			i++;
		}
		dest[i] = '\0';
	}
	while (source[i])
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		len;
	int		word;
	char	**str;

	if (!s)
		return (NULL);
	i = -1;
	len = 0;
	word = count_word((char *)s, c);
	str = malloc((word + 1) * sizeof(char *));
	if (str == NULL)
		return (NULL);
	while (++i < word)
	{
		while (len-- > 0 || *(char *)s == c)
			s++;
		len = word_len((char *)s, c);
		str[i] = malloc((len + 1) * sizeof(char));
		if (str[i] == NULL)
			return (NULL);
		ft_strlcpy(str[i], (char *)s, len + 1);
	}
	str[i] = 0;
	return (str);
}
