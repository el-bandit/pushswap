/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arngomes <arngomes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 18:01:20 by arngomes          #+#    #+#             */
/*   Updated: 2026/11/25 14:07:28 by arngomes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** on regarde toutes les paires (i, j) avec i avant j dans la pile
** si a[i] > a[j] c'est une erreur
** disorder c'est le nombre d'erreurs divise par le nombre de paires
** donc 0 si c'est deja trie et 1 si c'est trie a l'envers
*/
double	compute_disorder(t_node *a)
{
	t_node	*i;
	t_node	*j;
	long	mistakes;
	long	total;

	mistakes = 0;
	total = 0;
	i = a;
	while (i)
	{
		j = i->next;
		while (j)
		{
			total++;
			if (i->value > j->value)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	if (total == 0)
		return (0.0);
	return ((double)mistakes / (double)total);
}
