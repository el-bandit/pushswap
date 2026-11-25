/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfleskes <viktor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 10:38:49 by vfleskes          #+#    #+#             */
/*   Updated: 2026/11/25 22:15:17 by vfleskes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/*Finds all numbers index, rotates until the smallest number is at the front
and puts the number into b*/
void	sort_simple(t_node **a, t_node **b)
{
	int	size;
	int	pos;
	int	index;

	assign_index(*a);
	size = stack_size(*a);
	index = 0;
	while (size > 0)
	{
		pos = find_index_pos(*a, index);
		if (pos <= size / 2)
			while ((*a)->index != index)
				ra(a);
		else
			while ((*a)->index != index)
				rra(a);
		pb(a, b);
		index++;
		size--;
	}
	while (*b)
		pa(a, b);
}
