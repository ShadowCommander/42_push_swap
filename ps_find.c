/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 02:12:43 by jtong             #+#    #+#             */
/*   Updated: 2021/11/06 20:08:21 by jtong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_find_next_smaller(int current, t_llist *list)
{
	t_node	*node;
	int		next;
	int		i;
	int		dist;

	node = list->start;
	next = INT_MIN;
	i = 0;
	while (node)
	{
		if (ps_get(node) < current && ps_get(node) > next)
		{
			next = ps_get(node);
			dist = i;
		}
		i++;
		node = node->next;
	}
	if (next == INT_MIN)
		return (-1);
	return (dist);
}

int	ps_find_next_bigger(int current, t_llist *list)
{
	t_node	*node;
	int		next;
	int		i;
	int		dist;

	node = list->start;
	next = INT_MAX;
	i = 0;
	while (node)
	{
		if (ps_get(node) > current && ps_get(node) < next)
		{
			next = ps_get(node);
			dist = i;
		}
		i++;
		node = node->next;
	}
	if (next == INT_MAX)
		return (-1);
	return (dist);
}

void	find_place(int current, t_llist *list, int *k, int *l)
{
	int	dist;
	int	mid;

	mid = list->length / 2;
	dist = ps_find_next_smaller(current, list);
	if (dist == -1)
	{
		dist = ps_find_next_bigger(current, list);
		if (dist < mid)
			*k = dist + 1;
		else
			*l = list->length - dist - 1;
	}
	else
	{
		if (dist <= mid)
			*k = dist;
		else
			*l = list->length - dist;
	}
}

void	ps_spin_calc(t_push_swap *ps, t_node *node, t_insert_vars *vars,
		int *rotations)
{
	vars->k = 0;
	vars->l = 0;
	find_place(ps_get(node), ps->b, &vars->k, &vars->l);
	if (vars->a_spin < vars->k)
		vars->result = vars->k;
	else
		vars->result = vars->a_spin;
	if (vars->j < vars->l)
		vars->result += vars->l;
	else
		vars->result += vars->j;
	if (vars->result < vars->store)
	{
		rotations[0] = vars->a_spin;
		rotations[1] = vars->j;
		rotations[2] = vars->k;
		rotations[3] = vars->l;
		vars->store = vars->result;
	}
}

void	ps_is_duplicate(t_push_swap *ps, int num, t_node *node)
{
	while (node)
	{
		if (num == ps_get(node))
			ps_die(ps, NULL);
		node = node->next;
	}
}
