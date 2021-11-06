/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 23:32:39 by jtong             #+#    #+#             */
/*   Updated: 2021/11/06 18:16:51 by jtong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
int	ps_print_get_size(t_push_swap *ps)
{
	t_node	*node;
	int		out;
	int		num;

	node = ps->a->start;
	out = 0;
	while (node)
	{
		num = ft_intlen(*(int *)node->content);
		if (out < num)
			out = num;
		node = node->next;
	}
	node = ps->b->start;
	while (node)
	{
		num = ft_intlen(*(int *)node->content);
		if (out < num)
			out = num;
		node = node->next;
	}
	return (out);
}

void	ps_print_stacks_h(t_push_swap *ps)
{
	t_node	*node;
	char	*num;
	int		padding;

	if (ps->instructions->length > 0)
	{
		ft_putchar(' ');
		ft_putstr(ps->instructions->end->content);
		ft_putchar('\n');
	}
	padding = ps_print_get_size(ps) + 1;
	node = ps->a->start;
	ft_putstr("a:");
	while (node)
	{
		num = ft_itoa(*(int *)node->content);
		write(1, "          ", padding - ft_strlen(num));
		ft_putstr(num);
		free(num);
		node = node->next;
	}
	ft_putstr("\nb:");
	node = ps->b->start;
	while (node)
	{
		num = ft_itoa(*(int *)node->content);
		write(1, "          ", padding - ft_strlen(num));
		ft_putstr(num);
		free(num);
		node = node->next;
	}
	ft_putchar('\n');
}

void	ps_print_stacks_v(t_push_swap *ps)
{
	size_t	i;
	t_node	*a;
	t_node	*b;

	if (ps->a->length == 0 && ps->b->length == 0)
		return ;
	if (ps->instructions->end)
	{
		ft_putchar('\t');
		ft_putstr(ps->instructions->end->content);
		ft_putchar('\n');
	}
	a = ps->a->start;
	b = ps->b->start;
	if (ps->a->length > ps->b->length)
		i = ps->a->length;
	else
		i = ps->b->length;
	while (i > 0)
	{
		ft_putchar('\t');
		if (i <= ps->a->length && a)
		{
			ft_putnbr(*(int *)a->content);
			a = a->next;
		}
		if (i <= ps->b->length && b)
		{
			ft_putchar('\t');
			ft_putnbr(*(int *)b->content);
			b = b->next;
		}
		ft_putchar('\n');
		i--;
	}
	ft_putstr("----------------------------------------\n");
}
*/

void	ps_print_stacks(t_push_swap *ps)
{
}
