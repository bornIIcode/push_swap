/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytabia <ytabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:41:56 by ytabia            #+#    #+#             */
/*   Updated: 2025/01/20 20:42:43 by ytabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*stack_to_tab(t_list **stack_a)
{
	int		*tab;
	int		size;
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = *stack_a;
	size = node_size(stack_a);
	tab = malloc(sizeof(int) * size);
	while (i < size)
	{
		tab[i] = tmp->data;
		i++;
		tmp = tmp->next;
	}
	return (tab);
}

int	*sort_tab(int *tab, unsigned int size)
{
	unsigned int	i;
	int				tmp;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
	return (tab);
}

void	func_sort_stack(t_list **stack_a, t_list **stack_b)
{
	int	size_a;
	int	size_b;
	int	*tab;

	tab = stack_to_tab(stack_a);
	size_a = node_size(stack_a);
	size_b = node_size(stack_b);
	tab = sort_tab(tab, size_a);
	while (*stack_a)
	{
		helper_func_a_to_b(stack_a, stack_b, size_a, tab);
	}
	while (*stack_b)
	{
		helper_func_b_to_a(stack_a, stack_b, size_b);
	}
	free(tab);
}

void	helper_func_a_to_b(t_list **stack_a, t_list **stack_b
, int size_a, int *tab)
{
	t_list	*tmp;
	int		index;
	int		size_b;

	size_b = node_size(stack_b);
	tmp = *stack_a;
	index = 0;
	while (tab[index] != tmp->data && index < size_a)
		index++;
	if (index < size_b)
	{
		func_pb(stack_a, stack_b, 0);
		func_rb(stack_b, 0);
		size_b++;
	}
	else if (index < size_b + func_chunks(stack_a))
	{
		func_pb(stack_a, stack_b, 0);
		size_b++;
	}
	else
		func_ra(stack_a, 0);
}

void	helper_func_b_to_a(t_list **stack_a, t_list **stack_b, int size_b)
{
	int		max;
	int		index;
	t_list	*tmp;

	size_b = node_size(stack_b);
	max = func_check_largest(stack_b);
	index = 0;
	tmp = *stack_b;
	while (tmp->data != max)
	{
		index++;
		tmp = tmp->next;
	}
	while ((*stack_b)->data != max)
	{
		if (index <= size_b / 2)
			func_rb(stack_b, 0);
		else
			func_rrb(stack_b, 0);
	}
	func_pa(stack_a, stack_b, 0);
	size_b--;
}
