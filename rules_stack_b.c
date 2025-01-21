/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_stack_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytabia <ytabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:06:35 by ytabia            #+#    #+#             */
/*   Updated: 2025/01/21 12:10:18 by ytabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	func_sb(t_list **stack_b, int flag)
{
	int	tmp;

	if (!stack_b || !(*stack_b) || !(*stack_b)->next)
		return ;
	tmp = (*stack_b)->data;
	(*stack_b)->data = (*stack_b)->next->data;
	(*stack_b)->next->data = tmp;
	if (flag == 0)
		write(1, "sb\n", 3);
}

void	func_pb(t_list **stack_a, t_list **stack_b, int flag)
{
	t_list	*top;

	if (!stack_a || !(*stack_a) || !stack_b)
		return ;
	top = creat_node_b(stack_a);
	top->next = (*stack_b);
	(*stack_b) = top;
	if (flag == 0)
		write(1, "pb\n", 3);
}

void	func_rb(t_list **stack_b, int flag)
{
	t_list	*new_node;
	t_list	*tmp;

	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	new_node = creat_node_a(stack_b);
	tmp = (*stack_b);
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = new_node;
	if (flag == 0)
		write(1, "rb\n", 3);
}

void	func_rrb(t_list **stack_b, int flag)
{
	t_list	*last;
	t_list	*before_last;

	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	before_last = *stack_b;
	while (before_last->next->next != NULL)
	{
		before_last = before_last->next;
	}
	last = before_last->next;
	before_last->next = NULL;
	last->next = *stack_b;
	*stack_b = last;
	if (flag == 0)
		write(1, "rrb\n", 4);
}
