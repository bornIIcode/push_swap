/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_cr_stack_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytabia <ytabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:57:01 by ytabia            #+#    #+#             */
/*   Updated: 2025/01/21 12:02:38 by ytabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	remove_node_b(t_list **stack_b)
{
	int		save_data;
	t_list	*tmp;

	save_data = (*stack_b)->data;
	tmp = (*stack_b);
	(*stack_b) = (*stack_b)->next;
	free(tmp);
	return (save_data);
}

t_list	*creat_node_a(t_list **stack_b)
{
	t_list	*node;
	int		save_data;

	save_data = remove_node_b(stack_b);
	node = malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->data = save_data;
	node->next = NULL;
	return (node);
}
