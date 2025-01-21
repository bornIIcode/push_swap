/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_cr_stack_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytabia <ytabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:03:05 by ytabia            #+#    #+#             */
/*   Updated: 2025/01/21 12:03:13 by ytabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	remove_node_a(t_list **stack_a)
{
	int		save_data;
	t_list	*tmp;

	save_data = (*stack_a)->data;
	tmp = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	free(tmp);
	return (save_data);
}

t_list	*creat_node_b(t_list **stack_a)
{
	t_list	*node;
	int		save_data;

	save_data = remove_node_a(stack_a);
	node = malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->data = save_data;
	node->next = NULL;
	return (node);
}
