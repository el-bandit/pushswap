/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfleskes <viktor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 12:23:48 by vfleskes          #+#    #+#             */
/*   Updated: 2026/11/25 22:16:19 by vfleskes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	stack_length(t_node *stack)
{
	int	length;

	length = 0;
	while (stack)
	{
		length++;
		stack = stack->next;
	}
	return (length);
}

/*trouver la position du plus petit numero*/
static int	find_min_pos(t_node *stack)
{
	int	min_value;
	int	min_pos;
	int	pos;

	min_value = stack->value;
	min_pos = 0;
	pos = 0;
	while (stack)
	{
		if (stack->value < min_value)
		{
			min_value = stack->value;
			min_pos = pos;
		}
		pos++;
		stack = stack->next;
	}
	return (min_pos);
}

/*Mettre le plus petit numero dans b*/
static void	push_min_to_b(t_node **a, t_node **b)
{
	int	size;
	int	pos;
	int	rotations;

	size = stack_length(*a);
	pos = find_min_pos(*a);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			ra(a);
	}
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
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first > second && second < third)
		sa(a);
	else if (first < second && second > third && first > third)
		rra(a);
	else if (first < second && second > third)
	{
		sa(a);
		ra(a);
	}
}

void	sort_small(t_node **a, t_node **b)
{
	int	size;
	int	pushes_needed;

	size = stack_length(*a);
	if (size < 2 || size > 5)
		return ;
	if (size == 2)
	{
		if ((*a)->value > (*a)->next->value)
			sa(a);
		return ;
	}
	pushes_needed = size - 3;
	while (pushes_needed-- > 0)
		push_min_to_b(a, b);
	sort_three(a);
	while (*b)
		pa(a, b);
}
