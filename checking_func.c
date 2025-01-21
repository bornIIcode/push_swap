/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytabia <ytabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:44:05 by ytabia            #+#    #+#             */
/*   Updated: 2025/01/21 14:12:41 by ytabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_dup_num(t_list **stack, long int number, char **tokens)
{
	t_list	*tmp;

	tmp = *stack;
	while (tmp != NULL)
	{
		if (tmp->data == number)
		{
			free_tokens(tokens);
			free_stack(*stack);
			error_print();
		}
		tmp = tmp->next;
	}
}

int	func_check_largest(t_list **stack)
{
	int		max;
	t_list	*tmp;

	tmp = *stack;
	max = tmp->data;
	while (tmp != NULL)
	{
		if (tmp->data > max)
			max = tmp->data;
		tmp = tmp->next;
	}
	return (max);
}

int	func_check_smallest(t_list **stack)
{
	int		min;
	t_list	*tmp;

	tmp = *stack;
	min = tmp->data;
	while (tmp != NULL)
	{
		if (tmp->data < min)
			min = tmp->data;
		tmp = tmp->next;
	}
	return (min);
}

int	func_check_sorting(t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	if (!tmp)
		return (0);
	while (tmp->next != NULL)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	node_size(t_list **stack_a)
{
	t_list	*tmp;
	int		size;

	size = 0;
	tmp = *stack_a;
	if (tmp == NULL)
		return (0);
	while (tmp != NULL)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}
