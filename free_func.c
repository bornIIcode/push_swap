/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytabia <ytabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:28:36 by ytabia            #+#    #+#             */
/*   Updated: 2025/01/21 11:46:58 by ytabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_list *stack)
{
	t_list	*tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}

void	free_tokens(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

int	func_chunks(t_list **stack_a)
{
	int	chunk;

	chunk = 0;
	if (node_size(stack_a) <= 130)
		chunk = 16;
	else if (node_size(stack_a) <= 230 && node_size(stack_a) > 130)
		chunk = 45;
	else if (node_size(stack_a) > 230)
		chunk = 51;
	return (chunk);
}

void	error_print(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	handle_error(t_list **stack, char **token)
{
	int	i;

	i = 0;
	if (token == NULL || *token == NULL)
	{
		free(token);
		free_stack(*stack);
		error_print();
	}
	while (token[i])
	{
		free(token[i]);
		i++;
	}
	free(token);
	free_stack(*stack);
	error_print();
}
