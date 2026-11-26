/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arngomes <arngomes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 09:10:53 by arngomes          #+#    #+#             */
/*   Updated: 2026/11/26 18:27:51 by vfleskes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stddef.h>
# include <limits.h>
# include <stdlib.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

/* operations */
void		sa(t_node **a);
void		sb(t_node **b);
void		ss(t_node **a, t_node **b);
void		pa(t_node **a, t_node **b);
void		pb(t_node **a, t_node **b);
void		ra(t_node **a);
void		rb(t_node **b);
void		rr(t_node **a, t_node **b);
void		rra(t_node **a);
void		rrb(t_node **b);
void		rrr(t_node **a, t_node **b);

/* strategies */
void		sort_simple(t_node **a, t_node **b);
void		sort_small(t_node **a, t_node **b);
void		sort_medium(t_node **a, t_node **b);
void		sort_complex(t_node **a, t_node **b);
const char	*sort_adaptive(t_node **a, t_node **b);
void		add_bench(t_node **a, t_node **b, int num);

/* disorder */
double		compute_disorder(t_node *a);

/* utils */
int			stack_size(t_node *s);
void		assign_index(t_node *a);
int			ft_isqrt(int n);
int			find_index_pos(t_node *s, int index);
int			is_sorted(t_node *stack);
int			check_doubles(t_node **a);
void		chose_algo(int num, t_node **a, t_node **b);

/* node operations */
void		ft_lstadd_back(t_node **lst, t_node *new);
t_node		*ft_lstnew(int num);
void		ft_lstclear(t_node **lst);

#endif