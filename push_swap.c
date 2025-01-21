/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytabia <ytabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:49:55 by ytabia            #+#    #+#             */
/*   Updated: 2025/01/21 14:19:11 by ytabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	func_check_2_elem(t_list **stack)
{
	if (func_check_sorting(stack) == 1)
		return ;
	func_sa(stack, 0);
}

void	func_check_3_elem(t_list **stack)
{
	int	max;
	int	min;

	if (*stack == NULL)
		return ;
	max = func_check_largest(stack);
	min = func_check_smallest(stack);
	if (func_check_sorting(stack) == 1)
		return ;
	if (max == (*stack)->data)
		func_ra(stack, 0);
	else if (min == (*stack)->next->next->data)
		func_rra(stack, 0);
	else if (max == (*stack)->next->data)
	{
		func_rra(stack, 0);
		func_sa(stack, 0);
	}
	if ((*stack)->data > (*stack)->next->data)
		func_sa(stack, 0);
}

void	func_check_4_elem(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	int		min;
	int		size;
	int		i;

	i = 0;
	tmp = *stack_a;
	min = func_check_smallest(stack_a);
	size = node_size(stack_a);
	if (func_check_sorting(stack_a) == 1)
		return ;
	while (tmp->data != min && i++)
		tmp = tmp->next;
	while ((*stack_a)->data != min)
	{
		if (size / 2 >= i)
			func_ra(stack_a, 0);
		else
			func_rra(stack_a, 0);
	}
	func_pb(stack_a, stack_b, 0);
	func_check_3_elem(stack_a);
	func_pa(stack_a, stack_b, 0);
}

void	func_check_5_elem(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	int		min;
	int		size;
	int		i;

	i = 0;
	tmp = *stack_a;
	size = node_size(stack_a);
	min = func_check_smallest(stack_a);
	if (func_check_sorting(stack_a) == 1)
		return ;
	while (tmp->data != min && i++)
		tmp = tmp->next;
	while ((*stack_a)->data != min)
	{
		if (size / 2 >= i)
			func_ra(stack_a, 0);
		else
			func_rra(stack_a, 0);
	}
	func_pb(stack_a, stack_b, 0);
	func_check_4_elem(stack_a, stack_b);
	func_pa(stack_a, stack_b, 0);
}
