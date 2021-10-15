void	ps_pa(t_push_swap *ps)
{
	ft_listpush(ps->a, ft_listpop(ps->b))
}

void	ps_pb(t_push_swap *ps)
{
	ft_listpush(ps->b, ft_listpop(ps->a))
}
