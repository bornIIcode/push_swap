/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_stack_ab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytabia <ytabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:06:10 by ytabia            #+#    #+#             */
/*   Updated: 2025/01/21 12:06:11 by ytabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	func_ss(t_list **stack_a, t_list **stack_b, int flag)
{
	func_sa(stack_a, 1);
	func_sb(stack_b, 1);
	if (flag == 0)
		write(1, "ss\n", 3);
}

void	func_rr(t_list **stack_a, t_list **stack_b, int flag)
{
	func_ra(stack_a, 1);
	func_rb(stack_b, 1);
	if (flag == 0)
		write(1, "rr\n", 1);
}

void	func_rrr(t_list **stack_a, t_list **stack_b, int flag)
{
	func_rra(stack_a, 1);
	func_rrb(stack_b, 1);
	if (flag == 0)
		write(1, "rrr\n", 4);
}
