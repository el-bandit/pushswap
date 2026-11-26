/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_operations3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfleskes <viktor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 15:41:38 by vfleskes          #+#    #+#             */
/*   Updated: 2026/11/25 22:17:13 by vfleskes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Le dernier argument deviens le premier*/
static int	reverse_rotate(t_node **stack)
{
	t_node	*last;
	t_node	*curr;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	curr = *stack;
	while (curr->next->next)
		curr = curr->next;
	last = curr->next;
	curr->next = NULL;
	last->next = *stack;
	*stack = last;
	return (1);
}

void	rra(t_node **a)
{
	if (reverse_rotate(a))
		write(1, "rra\n", 4);
}

void	rrb(t_node **b)
{
	if (reverse_rotate(b))
		write(1, "rrb\n", 4);
}

void	rrr(t_node **a, t_node **b)
{
	int	rev_rotated_a;
	int	rev_rotated_b;

	rev_rotated_a = reverse_rotate(a);
	rev_rotated_b = reverse_rotate(b);
	if (rev_rotated_a || rev_rotated_b)
		write(1, "rrr\n", 4);
}
