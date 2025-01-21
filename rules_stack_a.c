/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_stack_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytabia <ytabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:04:03 by ytabia            #+#    #+#             */
/*   Updated: 2025/01/21 12:05:37 by ytabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	func_sa(t_list **stack_a, int flag)
{
	int	tmp;

	if ((*stack_a) == NULL || (*stack_a)->next == NULL)
		return ;
	tmp = (*stack_a)->data;
	(*stack_a)->data = (*stack_a)->next->data;
	(*stack_a)->next->data = tmp;
	if (flag == 0)
		write(1, "sa\n", 3);
}

void	func_pa(t_list **stack_a, t_list **stack_b, int flag)
{
	t_list	*top;

	if (!stack_a || !stack_b || !(*stack_b))
		return ;
	top = creat_node_a(stack_b);
	top->next = (*stack_a);
	(*stack_a) = top;
	if (flag == 0)
		write(1, "pa\n", 3);
}

void	func_ra(t_list **stack_a, int flag)
{
	t_list	*new_node;
	t_list	*tmp;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	new_node = creat_node_b(stack_a);
	tmp = (*stack_a);
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = new_node;
	if (flag == 0)
		write(1, "ra\n", 3);
}

void	func_rra(t_list **stack_a, int flag)
{
	t_list	*last;
	t_list	*before_last;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	before_last = *stack_a;
	while (before_last->next->next != NULL)
	{
		before_last = before_last->next;
	}
	last = before_last->next;
	before_last->next = NULL;
	last->next = *stack_a;
	*stack_a = last;
	if (flag == 0)
		write(1, "rra\n", 4);
}
