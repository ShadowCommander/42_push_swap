/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtong <jtong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 15:04:54 by jtong             #+#    #+#             */
/*   Updated: 2021/11/06 19:49:21 by jtong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include "libft_list.h"
# include <stdlib.h>
# include <unistd.h> 
# include <limits.h>

typedef struct s_push_swap
{
	t_llist	*a;
	t_llist	*b;
	t_llist	*instructions;
}				t_push_swap;

typedef struct s_array
{
	void	**arr;
	size_t	size;
	t_llist	*saved;
}				t_array;

typedef struct s_insert_vars
{
	int		a_spin;
	int		j;
	int		k;
	int		l;
	int		result;
	int		store;
}				t_insert_vars;

/* swap a */
void	ps_sa(t_push_swap *ps);
/* swap b */
void	ps_sb(t_push_swap *ps);
/* swap both */
void	ps_ss(t_push_swap *ps);
/* push to a */
void	ps_pa(t_push_swap *ps);
/* push to b */
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

/* run multiple sorts */
void	ps_run_sorts(t_push_swap *ps);

/* utils */
int		ps_get(t_node *node);
int		ps_print_get_size(t_push_swap *ps);
int		ps_is_sorted(t_push_swap *ps);
int		ps_is_list_sorted(t_llist *list);
void	ps_spin_calc(t_push_swap *ps, t_node *node, t_insert_vars *vars,
			int *rotations);
int		ps_find_biggest(t_llist *list);
int		ps_find_smallest(t_llist *list);
int		ps_find_next_bigger(int current, t_llist *list);
void	ps_delete_reset(t_array *reset);
void	ps_die(t_push_swap *ps, t_array *reset);
int		ps_atoi(t_push_swap *ps, const char *ptr);

void	ps_spin_a(t_push_swap *ps, int steps);

/* sort push_swap */
void	ps_sort(t_push_swap *ps);
void	ps_insertion_sort(t_push_swap *ps);

void	ps_inserter_sort(t_push_swap *ps);
void	ps_small_sort(t_push_swap *ps);

/* print */
void	ps_print_stacks(t_push_swap *ps);
#endif
