/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 18:16:25 by jtong             #+#    #+#             */
/*   Updated: 2021/11/06 17:55:04 by jtong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_exit(t_push_swap **ps, int print)
{
	t_node	*node;

	if (print)
	{
		node = (*ps)->instructions->start;
		while (node)
		{
			ft_putstr((char *)node->content);
			ft_putchar('\n');
			node = node->next;
		}
	}
	if (*ps == NULL)
		return ;
	if ((*ps)->a != NULL)
	{
		ft_listclear((*ps)->a, 1);
		if ((*ps)->b != NULL)
		{
			ft_listclear((*ps)->b, 1);
			if ((*ps)->instructions != NULL)
				ft_listclear((*ps)->instructions, 0);
		}
	}
	free(*ps);
}

void	die(t_push_swap **ps, t_array *reset)
{
	ft_putstr("Error\n");
	ps_delete_reset(reset);
	ps_exit(ps, 0);
	exit(-1);
}

int	parse_args(int argc, char **argv, t_push_swap *ps)
{
	int		i;
	int		num;
	t_node	*node;

	i = 0;
	while (argv[++i])
		if (!ft_isnum(argv[i], 1))
			return (-1);
	i = 1;
	while (i < argc)
	{
		num = ps_atoi(ps, argv[i]);
		node = ps->a->start;
		while (node)
		{
			if (num == ps_get(node))
				die(&ps, NULL);
			node = node->next;
		}
		ft_listadd(ps->a, ft_listnode(ft_strndup((char *)&num, sizeof(num)),
				sizeof(num)));
		i++;
	}
	return (0);
}

void	ps_init(t_push_swap **ps)
{
	*ps = (t_push_swap *)malloc(sizeof(*ps));
	if (*ps == NULL)
		die(ps, NULL);
	(*ps)->a = ft_listnew();
	if ((*ps)->a == NULL)
		die(ps, NULL);
	(*ps)->b = ft_listnew();
	if ((*ps)->b == NULL)
		die(ps, NULL);
	(*ps)->instructions = ft_listnew();
	if ((*ps)->instructions == NULL)
		die(ps, NULL);
}

int	main(int argc, char **argv)
{
	t_push_swap	*ps;

	ps_init(&ps);
	if (parse_args(argc, argv, ps) == -1)
		die(&ps, NULL);
	ps_run_sorts(ps);
	ps_exit(&ps, 1);
}
