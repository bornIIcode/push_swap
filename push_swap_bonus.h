/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytabia <ytabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:14:30 by ytabia            #+#    #+#             */
/*   Updated: 2025/01/21 14:14:32 by ytabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include "get_next_line.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct t_list
{
	int				data;
	int				index;
	struct t_list	*next;
}					t_list;

t_list				*creat_node_b(t_list **stack_b);
int					remove_node_a(t_list **stack_b);
void				func_sb(t_list **stack_b, int flag);
void				func_pb(t_list **stack_a, t_list **stack_b, int flag);
void				func_rb(t_list **stack_b, int flag);
void				func_rrb(t_list **stack_b, int flag);

t_list				*creat_node_a(t_list **stack_b);
int					remove_node_b(t_list **stack_b);
void				func_sa(t_list **stack_a, int flag);
void				func_pa(t_list **stack_a, t_list **stack_b, int flag);
void				func_ra(t_list **stack_a, int flag);
void				func_rra(t_list **stack_a, int flag);
void				func_ss(t_list **stack_a, t_list **stack_b, int flag);
void				func_rr(t_list **stack_a, t_list **stack_b, int flag);
void				func_rrr(t_list **stack_a, t_list **stack_b, int flag);

int					node_size(t_list **stack_a);
t_list				*new_node(int data);
void				free_stack(t_list *stack);
void				free_tokens(char **tokens);
void				check_dup_num(t_list **stack, long int number,
						char **tokens);
void				func_check_2_elem(t_list **stack);
void				func_check_3_elem(t_list **stack);
void				func_check_4_elem(t_list **stack_a, t_list **stack_b);
void				func_check_5_elem(t_list **stack_a, t_list **stack_b);
int					func_check_largest(t_list **stack);
int					func_check_smallest(t_list **stack);
int					func_check_sorting(t_list **stack);
void				check_type(t_list **stack_a, t_list **stack_b);
int					*stack_to_tab(t_list **stack_a);
int					*sort_tab(int *tab, unsigned int size);
int					func_chunks(t_list **stack_a);
void				func_sort_stack(t_list **stack_a, t_list **stack_b);
void				helper_func_b_to_a(t_list **stack_a, t_list **stack_b,
						int size_b);
void				helper_func_a_to_b(t_list **stack_a, t_list **stack_b,
						int size_a, int *tab);

void				parsing(char **argv, t_list **stack_a);
void				process_token(char *token, t_list **stack, char **tokens);
void				process_argument(char *arg, t_list **stack);
void				handle_error(t_list **stack, char **token);
void				error_print(void);
char				**ft_split(char const *s, char c);
char				*ft_substr(char const *s, unsigned int start, size_t len);
#endif