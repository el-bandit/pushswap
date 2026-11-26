/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfleskes <viktor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 12:28:49 by vfleskes          #+#    #+#             */
/*   Updated: 2026/11/26 18:51:48 by vfleskes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long long	ft_atoi(const char *nptr)
{
	int			i;
	long long	res;
	int			sign;

	i = 0;
	res = 0;
	sign = 1;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10;
		res = res + (nptr[i] - '0');
		i++;
	}
	return (res * sign);
}

static int	add_num(char *str, t_node **a)
{
	int			i;
	long long	num;
	t_node		*newnode;

	i = 0;
	while (str[i])
	{
		while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
			i++;
		if (((str[i] == '-' || str[i] == '+') && (str[i + 1] >= '0'
					&& str[i + 1] <= '9')) || (str[i] >= '0' && str[i] <= '9'))
		{
			num = ft_atoi(&str[i]);
			if (num > INT_MAX || num < INT_MIN)
				return (ft_lstclear(a), 1);
			newnode = ft_lstnew(num);
			if (newnode == NULL)
				return (ft_lstclear(a), 1);
			ft_lstadd_back(a, newnode);
			while (str[i] == '-' || str[i] == '+'
				|| (str[i] >= '0' && str[i] <= '9'))
				i++;
			while (str[i] == ' ')
				i++;
		}
		else
			return (1);
	}
	return (0);
}

static int	ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	i = 0;
	if (str1[i] == '\0' && str2[i] == '\0')
		return (1);
	while ((str1[i] != '\0' || str2[i] != '\0'))
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

static int	check_arg(char **str)
{
	int	num;
	int	i;

	num = 0;
	i = 1;
	if (ft_strcmp(str[i], "--bench") == 0)
	{
		num = 10;
		i++;
	}
	if (ft_strcmp(str[i], "--simple") == 0)
		return (num + 1);
	else if (ft_strcmp(str[i], "--medium") == 0)
		return (num + 2);
	else if (ft_strcmp(str[i], "--complex") == 0)
		return (num + 3);
	else if (ft_strcmp(str[i], "--adaptive") == 0)
		return (num + 4);
	else
		return (num + 5);
}

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;
	int		i;
	int		num;

	a = NULL;
	b = NULL;
	i = 0;
	if (ac > 1)
	{
		num = check_arg(av);
		if (num != 5)
			i++;
		if (num >= 11 && num <= 14)
			i++;
		while (i++ < ac - 1)
			if (add_num(av[i], &a) == 1)
				return (write(2, "Error\n", 6), 1);
		assign_index(a);
		if (check_doubles(&a) == 1)
			return (ft_lstclear(&a), write(2, "Error\n", 6), 1);
		chose_algo(num, &a, &b);
	}
	return (0);
}
