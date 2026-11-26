/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arngomes <arngomes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 14:56:32 by arngomes          #+#    #+#             */
/*   Updated: 2026/11/26 16:08:42 by arngomes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* taille du chunk environ 1.5 * sqrt(n), ca donne 15 pour 100 et 33 pour 500 */
static int	chunk_size(int n)
{
	int	chunk;

	chunk = ft_isqrt(n) * 3 / 2;
	if (chunk < 1)
		chunk = 1;
	return (chunk);
}

/*
** etape 1, on envoie dans b tout ce qui a un index entre 0 et pushed + chunk
** les plus petits (index <= pushed) on les met en bas de b avec rb
** les autres on les laisse en haut, comme ca b est quasi trie
*/
static void	push_chunks(t_node **a, t_node **b, int chunk)
{
	int	pushed;

	pushed = 0;
	while (*a)
	{
		if ((*a)->index <= pushed)
		{
			pb(a, b);
			if ((*b)->next)
				rb(b);
			pushed++;
		}
		else if ((*a)->index <= pushed + chunk)
		{
			pb(a, b);
			pushed++;
		}
		else
			ra(a);
	}
}

/*
** etape 2, on remonte le plus grand de b avec rb ou rrb selon le plus court
** puis on fait pa, a se remplit dans l'ordre en partant du plus grand
*/
static void	push_back(t_node **a, t_node **b)
{
	int	size;
	int	pos;

	size = stack_size(*b);
	while (size > 0)
	{
		pos = find_index_pos(*b, size - 1);
		if (pos <= size / 2)
		{
			while (pos-- > 0)
				rb(b);
		}
		else
		{
			while (pos++ < size)
				rrb(b);
		}
		pa(a, b);
		size--;
	}
}

void	sort_medium(t_node **a, t_node **b)
{
	int	n;

	n = stack_size(*a);
	if (n < 2 || compute_disorder(*a) == 0.0)
		return ;
	push_chunks(a, b, chunk_size(n));
	push_back(a, b);
}
