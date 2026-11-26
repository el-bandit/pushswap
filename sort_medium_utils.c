/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arngomes <arngomes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 10:09:36 by arngomes          #+#    #+#             */
/*   Updated: 2026/11/25 14:06:51 by arngomes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_node *s)
{
	int	n;

	n = 0;
	while (s)
	{
		n++;
		s = s->next;
	}
	return (n);
}

/* l'index c'est la position qu'aurait la valeur si la pile etait triee */
void	assign_index(t_node *a)
{
	t_node	*cur;
	t_node	*cmp;

	cur = a;
	while (cur)
	{
		cur->index = 0;
		cmp = a;
		while (cmp)
		{
			if (cmp->value < cur->value)
				cur->index++;
			cmp = cmp->next;
		}
		cur = cur->next;
	}
}

int	ft_isqrt(int n)
{
	int	r;

	r = 0;
	while ((r + 1) * (r + 1) <= n)
		r++;
	return (r);
}

int	find_index_pos(t_node *s, int index)
{
	int	pos;

	pos = 0;
	while (s && s->index != index)
	{
		pos++;
		s = s->next;
	}
	return (pos);
}
