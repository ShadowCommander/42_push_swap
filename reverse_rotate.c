void	ps_rra(t_push_swap *ps)
{
	ft_listpush(ps->a, ft_listcut(ps->a))
}

void	ps_rrb(t_push_swap *ps)
{
	ft_listpush(ps->b, ft_listcut(ps->b))
}

void	ps_rrr(t_push_swap *ps)
{
	ps_rra(ps);
	ps_rrb(ps);
}
