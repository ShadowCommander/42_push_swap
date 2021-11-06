/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 17:41:01 by jtong             #+#    #+#             */
/*   Updated: 2021/11/06 17:53:15 by jtong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_ctoi(int c)
{
	if (ft_isdigit(c))
		return (c - '0');
	else if (ft_isupper(c))
		return (c - ('A' - 10));
	else if (ft_islower(c))
		return (c - ('a' - 10));
	return (c);
}

int	ps_atoi(t_push_swap *ps, const char *ptr)
{
	t_strtol	v;

	v = (t_strtol){ptr, 0, 1, 0, 0, 0};
	while (ft_isspace(*v.s))
		v.s++;
	if (*v.s == '-' && ft_isalnum(v.s[1]))
		v.neg = -1;
	if ((*v.s == '-' || *v.s == '+') && ft_isalnum(v.s[1]))
		v.s++;
	v.cutoff = (INT_MAX * v.neg) / 10;
	v.cutlim = (INT_MAX * v.neg) % 10;
	while (ft_isalnum(*v.s) && ft_ctoi(*v.s) < 10)
	{
		v.c = ft_ctoi(*v.s);
		if (v.acc >= v.cutoff * v.neg && v.c > v.cutlim + (v.neg == -1))
			die(&ps, NULL);
		v.acc = (v.acc * 10) + (v.c * v.neg);
		v.s++;
	}
	return (v.acc);
}
