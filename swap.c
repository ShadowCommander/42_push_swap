/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 20:35:11 by jtong             #+#    #+#             */
/*   Updated: 2021/11/05 14:03:02 by jtong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_swap_top(t_llist *list)
{
	t_node	*a;
	t_node	*b;

	a = ft_listpop(list);
	b = ft_listpop(list);
	ft_listpush(list, a);
	ft_listpush(list, b);
}

void	ps_sa(t_push_swap *ps)
{
	ps_swap_top(ps->a);
	ft_listadd(ps->instructions, ft_listnode("sa", 3));
	ps_print_stacks(ps);
}

void	ps_sb(t_push_swap *ps)
{
	ps_swap_top(ps->b);
	ft_listadd(ps->instructions, ft_listnode("sb", 3));
	ps_print_stacks(ps);
}

void	ps_ss(t_push_swap *ps)
{
	ps_swap_top(ps->a);
	ps_swap_top(ps->b);
	ft_listadd(ps->instructions, ft_listnode("ss", 3));
	ps_print_stacks(ps);
}
