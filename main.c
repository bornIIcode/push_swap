/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytabia <ytabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:29:54 by ytabia            #+#    #+#             */
/*   Updated: 2025/01/21 11:31:29 by ytabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_type(t_list **stack_a, t_list **stack_b)
{
	if (!func_check_sorting(stack_a))
	{
		if (node_size(stack_a) == 2)
			func_check_2_elem(stack_a);
		else if (node_size(stack_a) == 3)
			func_check_3_elem(stack_a);
		else if (node_size(stack_a) == 4)
			func_check_4_elem(stack_a, stack_b);
		else if (node_size(stack_a) == 5)
			func_check_5_elem(stack_a, stack_b);
		else if (node_size(stack_a) > 5)
			func_sort_stack(stack_a, stack_b);
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc > 1)
	{
		parsing(argv, &stack_a);
		check_type(&stack_a, &stack_b);
		free_stack(stack_a);
	}
}
