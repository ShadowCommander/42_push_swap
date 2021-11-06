/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 20:34:35 by jtong             #+#    #+#             */
/*   Updated: 2021/11/03 08:40:01 by jtong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_reverse_rotate(t_llist *list)
{
	ft_listpush(list, ft_listlop(list));
}

void	ps_rra(t_push_swap *ps)
{
	ps_reverse_rotate(ps->a);
	ft_listadd(ps->instructions, ft_listnode("rra", 3));
	ps_print_stacks(ps);
}

void	ps_rrb(t_push_swap *ps)
{
	ps_reverse_rotate(ps->b);
	ft_listadd(ps->instructions, ft_listnode("rrb", 3));
	ps_print_stacks(ps);
}

void	ps_rrr(t_push_swap *ps)
{
	ps_reverse_rotate(ps->a);
	ps_reverse_rotate(ps->b);
	ft_listadd(ps->instructions, ft_listnode("rrr", 3));
	ps_print_stacks(ps);
}
