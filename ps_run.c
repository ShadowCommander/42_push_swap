/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_run.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 23:00:49 by jtong             #+#    #+#             */
/*   Updated: 2021/11/06 18:15:35 by jtong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_reset(t_push_swap *ps, t_array *reset)
{
	size_t	i;

	ps->a->length = reset->size;
	ps->a->start = reset->arr[0];
	i = 0;
	while (reset->arr[i])
	{
		((t_node *)reset->arr[i])->next = reset->arr[i + 1];
		if (((t_node *)reset->arr[i])->next == NULL)
			ps->a->end = reset->arr[i];
		i++;
	}
	ps->b->start = NULL;
	ps->b->end = NULL;
	ps->b->length = 0;
}

t_array	*ps_create_reset(t_push_swap *ps)
{
	t_array	*reset;
	t_node	*node;
	size_t	i;

	reset = (t_array *)malloc(sizeof(*reset));
	if (reset == NULL)
		die(&ps, reset);
	reset->size = ps->a->length;
	reset->arr = (void **)malloc(sizeof(*reset->arr) * (reset->size + 1));
	if (reset->arr == NULL)
		die(&ps, reset);
	node = ps->a->start;
	i = 0;
	while (node)
	{
		reset->arr[i] = node;
		i++;
		node = node->next;
	}
	reset->arr[i] = NULL;
	reset->saved = ft_listnew();
	if (reset->saved == NULL)
		die(&ps, reset);
	reset->saved->length = (size_t)-1;
	return (reset);
}

void	ps_delete_reset(t_array *reset)
{
	if (reset->arr != NULL)
	{
		free(reset->arr);
		if (reset->saved != NULL)
			free(reset->saved);
	}
	if (reset != NULL)
		free(reset);
}

/* loop sorting algos */
void	ps_run_sorts(t_push_swap *ps)
{
	static void	(*sort_functions[])(t_push_swap *ps) = {&ps_inserter_sort,
					&ps_small_sort, NULL};
	t_array		*reset;
	int			i;
	int			j;

	reset = ps_create_reset(ps);
	if (reset == NULL)
		die(&ps, NULL);
	i = 0;
	while (sort_functions[i])
	{
		sort_functions[i](ps);
		if (ps->instructions->length < reset->saved->length)
		{
			j = ps->instructions->length;
			while (reset->saved->start)
				ft_listfree(ft_listpop(reset->saved), 0);
			while (j-- > 0)
				ft_listadd(reset->saved, ft_listpop(ps->instructions));
		}
		ps_reset(ps, reset);
		i++;
	}
	ps_delete_reset(reset);
}
