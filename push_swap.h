/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtong <jtong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 15:04:54 by jtong             #+#    #+#             */
/*   Updated: 2021/10/17 15:31:36 by jtong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

/* swap a */
void	ps_sa(t_push_swap *ps);
/* swap b */
void	ps_sb(t_push_swap *ps);
/* swap both */
void	ps_ss(t_push_swap *ps);
/* push a */
void	ps_pa(t_push_swap *ps);
/* push b */
void	ps_pb(t_push_swap *ps);
/* rotate a */
void	ps_ra(t_push_swap *ps);
/* rotate b */
void	ps_rb(t_push_swap *ps);
/* rotate both */
void	ps_rr(t_push_swap *ps);
/* reverse rotate a */
void	ps_rra(t_push_swap *ps);
/* reverse rotate b */
void	ps_rrb(t_push_swap *ps);
/* reverse rotate both */
void	ps_rrr(t_push_swap *ps);

/* sort push_swap */
void	ps_sort(t_push_swap *ps);
#endif
