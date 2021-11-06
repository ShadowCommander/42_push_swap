/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_short_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 08:43:32 by jtong             #+#    #+#             */
/*   Updated: 2021/11/06 18:21:36 by jtong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_small_sort2(t_push_swap *ps)
{
	int	steps;

	while (ps->b->length > 0)
	{
		steps = ps_find_next_bigger(ps_get(ps->b->start), ps->a);
		if (steps > -1)
			ps_spin_a(ps, steps);
		ps_pa(ps);
	}
	steps = ps_find_biggest(ps->a);
	ps_spin_a(ps, steps + 1);
}

void	ps_small_sort(t_push_swap *ps)
{
	if (ps->a->length == 2)
		ps_ra(ps);
	else if (ps->a->length <= 5)
	{
		while (ps->a->length > 3)
			ps_pb(ps);
		if (ps->b->length > 1
			&& ps_get(ps->b->start) > ps_get(ps->b->start->next))
			ps_sb(ps);
		if ((ps_find_smallest(ps->a) + 1) % 3 == ps_find_biggest(ps->a))
			ps_sa(ps);
		if (!ps_is_list_sorted(ps->a))
		{
			if (ps_get(ps->a->start) > ps_get(ps->a->start->next))
				ps_ra(ps);
			else
				ps_rra(ps);
		}
		ps_small_sort2(ps);
	}
}
