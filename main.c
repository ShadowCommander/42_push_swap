struct	s_push_swap
{
	t_llist *a;
	t_llist *b;
}
typedef struct s_push_swap	t_push_swap;

int		parse_args(int argc, char **argv, t_push_swap *ps)
{
	int		i;
	int		num;

	if (!input_valid(argc, argv))
		return (-1);
	i = 0;
	while (i < argc)
	{
		num = ft_atoi(argv[i]);
		ft_listpush(ps->a, ft_listnode(&num, sizeof(num)))
		i++;
	}
}

void	ps_sort(t_push_swap *ps)
{
	// if first and second and third and forth need to be swapped
	// if first and second need to be swapped
	// if last and first
	// 
	if (ps_check_first(ps)
}

int		main(int argc, char **argv)
{
	t_push_swap *ps;

	ps_init(ps)
	parse_args(argc, argv, ps);
	ps_sort(ps);
	ps_print(ps);
}
