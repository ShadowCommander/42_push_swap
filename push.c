/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 20:34:02 by jtong             #+#    #+#             */
/*   Updated: 2021/11/03 08:40:15 by jtong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_push(t_llist *from, t_llist *to)
{
	ft_listpush(to, ft_listpop(from));
}

void	ps_pa(t_push_swap *ps)
{
	ps_push(ps->b, ps->a);
	ft_listadd(ps->instructions, ft_listnode("pa", 3));
	ps_print_stacks(ps);
}

void	ps_pb(t_push_swap *ps)
{
	ps_push(ps->a, ps->b);
	ft_listadd(ps->instructions, ft_listnode("pb", 3));
	ps_print_stacks(ps);
}
