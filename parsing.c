/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytabia <ytabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:47:48 by ytabia            #+#    #+#             */
/*   Updated: 2025/01/21 13:05:45 by ytabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*new_node(int data)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->data = data;
	node->next = NULL;
	return (node);
}

void	add_to_stack(t_list **stack, int data)
{
	t_list	*node;
	t_list	*tmp;

	node = new_node(data);
	if (*stack == NULL)
	{
		*stack = node;
		return ;
	}
	tmp = *stack;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = node;
}

void	process_token(char *token, t_list **stack, char **tokens)
{
	long int	number;
	int			k;

	k = 0;
	if (token[k] == '+' || token[k] == '-')
		k++;
	if (token[k] == '\0')
		handle_error(stack, tokens);
	while (token[k])
	{
		if (!ft_isdigit(token[k]))
		{
			handle_error(stack, tokens);
		}
		k++;
	}
	number = ft_atoi(token);
	if (number < INT_MIN || number > INT_MAX)
		handle_error(stack, tokens);
	check_dup_num(stack, number, tokens);
	add_to_stack(stack, number);
}

void	process_argument(char *arg, t_list **stack)
{
	char	**tokens;
	int		j;

	j = 0;
	tokens = ft_split(arg, ' ');
	if (!tokens[0])
	{
		free_tokens(tokens);
		handle_error(stack, NULL);
	}
	while (tokens[j])
	{
		process_token(tokens[j], stack, tokens);
		j++;
	}
	free_tokens(tokens);
}

void	parsing(char **argv, t_list **stack)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		process_argument(argv[i], stack);
		i++;
	}
}
