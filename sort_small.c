/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfleskes <viktor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 12:23:48 by vfleskes          #+#    #+#             */
/*   Updated: 2026/11/26 14:37:40 by vfleskes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_node *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static void	push_index_to_b(t_node **a, t_node **b, int index, int size)
{
	int	pos;
	int	rotations;

	pos = find_index_pos(*a, index);
	if (pos <= size / 2)
		while (pos-- > 0)
			ra(a);
	else
	{
		rotations = size - pos;
		while (rotations-- > 0)
			rra(a);
	}
	pb(a, b);
}

static void	sort_three(t_node **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && first > third)
		ra(a);
	else if (second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (second > third)
		rra(a);
	else if (first > second)
		sa(a);
}

void	sort_small(t_node **a, t_node **b)
{
	int	size;
	int	pushes;
	int	index;

	size = stack_size(*a);
	if (size < 2 || size > 5 || is_sorted(*a))
		return ;
	if (size == 2)
		return (sa(a));
	if (size == 3)
		return (sort_three(a));
	pushes = size - 3;
	index = 0;
	while (pushes-- > 0)
		push_index_to_b(a, b, index++, size--);
	sort_three(a);
	while (*b)
		pa(a, b);
}
