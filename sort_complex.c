/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfleskes <viktor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 13:28:57 by vfleskes          #+#    #+#             */
/*   Updated: 2026/11/26 14:41:03 by vfleskes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(int max_idx)
{
	int	bits;

	bits = 0;
	while ((max_idx >> bits) > 0)
		bits++;
	return (bits);
}

void	sort_complex(t_node **a, t_node **b)
{
	int		size;
	int		max_bits;
	int		bit;

	size = stack_size(*a);
	max_bits = get_max_bits(size - 1);
	bit = 0;
	if (is_sorted(*a))
		return ;
	while (bit < max_bits)
	{
		size = stack_size(*a);
		while (size > 0)
		{
			if ((((*a)->index >> bit) & 1) == 0)
				pb(a, b);
			else
				ra(a);
			size--;
		}
		while (*b)
			pa(a, b);
		bit++;
	}
}
