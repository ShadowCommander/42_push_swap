/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 20:34:16 by jtong             #+#    #+#             */
/*   Updated: 2021/11/03 08:40:08 by jtong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_rotate(t_llist *list)
{
	ft_listadd(list, ft_listpop(list));
}

void	ps_ra(t_push_swap *ps)
{
	ps_rotate(ps->a);
	ft_listadd(ps->instructions, ft_listnode("ra", 3));
	ps_print_stacks(ps);
}

void	ps_rb(t_push_swap *ps)
{
	ps_rotate(ps->b);
	ft_listadd(ps->instructions, ft_listnode("rb", 3));
	ps_print_stacks(ps);
}

void	ps_rr(t_push_swap *ps)
{
	ps_rotate(ps->a);
	ps_rotate(ps->b);
	ft_listadd(ps->instructions, ft_listnode("rr", 3));
	ps_print_stacks(ps);
}
