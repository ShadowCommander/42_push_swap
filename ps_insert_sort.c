/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_insert_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 07:01:09 by jtong             #+#    #+#             */
/*   Updated: 2021/11/06 15:26:01 by jtong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_insert_find_calculate_move(t_push_swap *ps, int *rotations)
{
	int				mid;
	t_node			*node;
	t_insert_vars	vars;

	mid = ps->a->length / 2;
	node = ps->a->start;
	vars.a_spin = 0;
	vars.j = 0;
	vars.store = INT_MAX;
	while (vars.a_spin <= mid)
	{
		ps_spin_calc(ps, node, &vars, rotations);
		vars.a_spin++;
		node = node->next;
	}
	vars.j = ps->a->length - vars.a_spin;
	vars.a_spin = 0;
	while (node)
	{
		ps_spin_calc(ps, node, &vars, rotations);
		vars.j--;
		node = node->next;
	}
}

void	ps_spin_a(t_push_swap *ps, int steps)
{
	if (ps->a->length - ft_abs(steps) < ft_abs(steps))
	{
		if (steps >= 0)
			steps = -ps->a->length + steps;
		else
			steps = ps->a->length + steps;
	}
	while (steps != 0)
	{
		if (steps >= 0)
		{
			ps_ra(ps);
			steps--;
		}
		else
		{
			ps_rra(ps);
			steps++;
		}
	}
}

void	ps_spin_b(t_push_swap *ps, int steps)
{
	if (ps->b->length - ft_abs(steps) < ft_abs(steps))
	{
		if (steps >= 0)
			steps = -ps->b->length + steps;
		else
			steps = ps->b->length + steps;
	}
	while (steps != 0)
	{
		if (steps >= 0)
		{
			ps_rb(ps);
			steps--;
		}
		else
		{
			ps_rrb(ps);
			steps++;
		}
	}
}

void	ps_inserter_sort(t_push_swap *ps)
{
	int	rotations[4];
	int	shift;

	ps_pb(ps);
	if (ps->b->start && ps->b->start->next
		&& ps_get(ps->b->start) < ps_get(ps->b->start->next))
		ps_sb(ps);
	while (ps->a->length > 0)
	{
		ft_bzero(rotations, sizeof(rotations));
		ps_insert_find_calculate_move(ps, rotations);
		ps_spin_a(ps, rotations[0]);
		ps_spin_b(ps, rotations[2]);
		ps_spin_a(ps, rotations[1] * -1);
		ps_spin_b(ps, rotations[3] * -1);
		ps_pb(ps);
	}
	shift = ps_find_biggest(ps->b);
	ps_spin_b(ps, shift);
	while (ps->b->length > 0)
		ps_pa(ps);
}
