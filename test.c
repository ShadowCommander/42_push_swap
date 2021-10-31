/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <jtong@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 11:36:54 by user42            #+#    #+#             */
/*   Updated: 2021/10/18 13:12:34 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>

int		die(int ret, char *msg)
{
	if (msg)
	{
		write(1, msg, strlen(msg));
		write(1, "\n", 1);
	}
	return (ret);
}

void	ft_listprint(t_llist *list)
{
	t_node	*node;

	node = list->start;
	while (node)
	{
		printf("%d\n", (int)node->content);
		node = node->next;
	}
}

int		main(int argc, char **argv)
{
	t_push_swap	*ps;
	int			*num;
	int			i;

	if (argc < 2)
		return (die(1, NULL));
	ps = (t_push_swap *)malloc(sizeof(*ps));
	ps->a = ft_listnew();
	ps->b = ft_listnew();

	i = 1;
	while (i < argc)
	{
		if (!ft_isnum(argv[i], 0))
			return (die(1, "Error"));
		i++;
	}

	i = 1;
	while (i < argc)
	{
		num = (int *)malloc(sizeof(*num));
		*num = ft_atoi(argv[i]);
		ft_listadd(ps->a, ft_listnode(num, sizeof(num)));
		i++;
	}

	

	ft_listclear(ps->a, 1);
	ft_listclear(ps->b, 1);
	free(ps);
}
