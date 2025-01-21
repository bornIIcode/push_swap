/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytabia <ytabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 19:13:39 by ytabia            #+#    #+#             */
/*   Updated: 2025/01/20 19:13:43 by ytabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	free_and_error(char *line, t_list *stack_a, t_list *stack_b)
{
	free(line);
	free_stack(stack_a);
	free_stack(stack_b);
	error_print();
}

void	check_operations(t_list **stack_a, t_list **stack_b, char *line)
{
	if (ft_strcmp(line, "sa\n") == 0)
		func_sa(stack_a, 1);
	else if (ft_strcmp(line, "sb\n") == 0)
		func_sb(stack_b, 1);
	else if (ft_strcmp(line, "ra\n") == 0)
		func_ra(stack_a, 1);
	else if (ft_strcmp(line, "rb\n") == 0)
		func_rb(stack_b, 1);
	else if (ft_strcmp(line, "pa\n") == 0)
		func_pa(stack_a, stack_b, 1);
	else if (ft_strcmp(line, "pb\n") == 0)
		func_pb(stack_a, stack_b, 1);
	else if (ft_strcmp(line, "rra\n") == 0)
		func_rra(stack_a, 1);
	else if (ft_strcmp(line, "rrb\n") == 0)
		func_rrb(stack_b, 1);
	else if (ft_strcmp(line, "ss\n") == 0)
		func_ss(stack_a, stack_b, 1);
	else if (ft_strcmp(line, "rr\n") == 0)
		func_rr(stack_a, stack_b, 1);
	else if (ft_strcmp(line, "rrr\n") == 0)
		func_rrr(stack_a, stack_b, 1);
	else
		free_and_error(line, *stack_a, *stack_b);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	*line;

	line = NULL;
	stack_a = NULL;
	stack_b = NULL;
	if (argc > 1)
	{
		parsing(argv, &stack_a);
		while (1)
		{
			line = get_next_line(STDIN_FILENO);
			if (!line)
				break ;
			check_operations(&stack_a, &stack_b, line);
			free(line);
		}
		if (func_check_sorting(&stack_a) == 1 && node_size(&stack_b) == 0)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
		(free_stack(stack_a), free_stack(stack_b));
	}
}
