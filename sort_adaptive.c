/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arngomes <arngomes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 12:26:29 by arngomes          #+#    #+#             */
/*   Updated: 2026/11/25 14:07:08 by arngomes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** on calcule le desordre avant de faire le moindre mouvement
** en dessous de 0.2 on prend sort_simple en O(n^2)
** en dessous de 0.5 on prend sort_medium en O(n sqrt n)
** sinon on prend sort_complex en O(n log n)
** on renvoie la complexite utilisee pour l'afficher avec --bench
*/
const char	*sort_adaptive(t_node **a, t_node **b)
{
	double	disorder;

	disorder = compute_disorder(*a);
	if (disorder < 0.2)
	{
		sort_simple(a, b);
		return ("O(n^2)");
	}
	if (disorder < 0.5)
	{
		sort_medium(a, b);
		return ("O(n\xe2\x88\x9an)");
	}
	sort_complex(a, b);
	return ("O(n log n)");
}
