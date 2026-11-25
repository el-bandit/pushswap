/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_operations2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfleskes <viktor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 13:11:22 by vfleskes          #+#    #+#             */
/*   Updated: 2026/11/25 22:17:18 by vfleskes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Met le premier numero de a dans b*/
void	pb(t_node **a, t_node **b)
{
	t_node	*node;

	if (!b || !a || !*a)
		return ;
	node = *a;
	*a = (*a)->next;
	node->next = *b;
	*b = node;
	write(1, "pb\n", 3);
}

/*Le premier argument deviens le dernier*/
static	int	rotate(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	first = *stack;
	*stack = first->next;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
	return (1);
}

void	ra(t_node **a)
{
	if (rotate(a))
		write(1, "ra\n", 3);
}

void	rb(t_node **b)
{
	if (rotate(b))
		write(1, "rb\n", 3);
}

void	rr(t_node **a, t_node **b)
{
	int	rotated_a;
	int	rotated_b;

	rotated_a = rotate(a);
	rotated_b = rotate(b);
	if (rotated_a || rotated_b)
		write(1, "rr\n", 3);
}
