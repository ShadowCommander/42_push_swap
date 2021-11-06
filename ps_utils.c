/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 22:58:08 by jtong             #+#    #+#             */
/*   Updated: 2021/11/06 15:19:57 by jtong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_get(t_node *node)
{
	return (*((int *)node->content));
}

int	ps_is_list_sorted(t_llist *list)
{
	t_node	*node;

	node = list->start;
	while (node && node->next)
	{
		if (ps_get(node) > ps_get(node->next))
			return (0);
		node = node->next;
	}
	return (1);
}

int	ps_is_sorted(t_push_swap *ps)
{
	if (ps->b->length > 0)
		return (0);
	return (ps_is_list_sorted(ps->a));
}

int	ps_find_biggest(t_llist *list)
{
	t_node	*node;
	int		largest;
	int		index;
	int		steps;

	node = list->start;
	largest = INT_MIN;
	index = 0;
	steps = 0;
	while (node)
	{
		if (ps_get(node) > largest)
		{
			largest = ps_get(node);
			steps = index;
		}
		index++;
		node = node->next;
	}
	return (steps);
}

int	ps_find_smallest(t_llist *list)
{
	t_node	*node;
	int		smallest;
	int		index;
	int		steps;

	node = list->start;
	smallest = INT_MAX;
	index = 0;
	steps = 0;
	while (node)
	{
		if (ps_get(node) < smallest)
		{
			smallest = ps_get(node);
			steps = index;
		}
		index++;
		node = node->next;
	}
	return (steps);
}
