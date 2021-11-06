/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 18:16:25 by jtong             #+#    #+#             */
/*   Updated: 2021/11/06 22:06:36 by jtong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_cleanup_args(t_push_swap *ps, int print)
{
	t_node	*list_node;

	if (print)
	{
		list_node = ps->instructions->start;
		while (list_node)
		{
			ft_putstr((char *)list_node->content);
			ft_putchar('\n');
			list_node = list_node->next;
		}
	}
	if (ps == NULL)
		return ;
	if (ps->a != NULL)
	{
		ft_listdelete(&ps->a, 1);
		if (ps->b != NULL)
		{
			ft_listdelete(&ps->b, 1);
			if (ps->instructions != NULL)
				ft_listdelete(&ps->instructions, 0);
		}
	}
	free(ps);
}

void	ps_die(t_push_swap *ps, t_array *reset)
{
	ft_putstr("Error\n");
	ps_delete_reset(reset);
	ps_cleanup_args(ps, 0);
	exit(-1);
}

void	ps_parse_args(char **splits, t_push_swap *ps)
{
	int		i;
	int		num;
	t_node	*list_node;

	i = -1;
	while (splits[++i])
		if (!ft_isnum(splits[i], 1))
			ps_die(ps, NULL);
	i = 0;
	while (splits[i])
	{
		num = ps_atoi(ps, splits[i]);
		list_node = ps->a->start;
		while (list_node)
		{
			if (num == ps_get(list_node))
				ps_die(ps, NULL);
			list_node = list_node->next;
		}
		ft_listadd(ps->a, ft_listnode(ft_memdup((char *)&num,
					sizeof(num)), sizeof(num)));
		i++;
	}
}

void	ps_init(t_push_swap **ps)
{
	*ps = (t_push_swap *)malloc(sizeof(**ps));
	if (*ps == NULL)
		ps_die(*ps, NULL);
	(*ps)->a = ft_listnew();
	if ((*ps)->a == NULL)
		ps_die(*ps, NULL);
	(*ps)->b = ft_listnew();
	if ((*ps)->b == NULL)
		ps_die(*ps, NULL);
	(*ps)->instructions = ft_listnew();
	if ((*ps)->instructions == NULL)
		ps_die(*ps, NULL);
}

int	main(int argc, char **argv)
{
	t_push_swap	*ps;
	int			i;
	int			j;
	char		**splits;

	ps_init(&ps);
	i = 1;
	while (i < argc)
	{
		splits = ft_strsplit(argv[i], ' ');
		ps_parse_args(splits, ps);
		j = -1;
		while (splits[++j])
			free(splits[j]);
		free(splits);
		i++;
	}
	if (ps->a->length <= 1 || ps_is_sorted(ps))
	{
		ps_cleanup_args(ps, 0);
		return (0);
	}
	ps_run_sorts(ps);
	ps_cleanup_args(ps, 1);
}
