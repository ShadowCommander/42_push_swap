void	ps_ra(t_push_swap *ps)
{
	ft_listadd(ps->a, ft_listpop(ps->a))
}

void	ps_rb(t_push_swap *ps)
{
	ft_listadd(ps->b, ft_listpop(ps->b))
}

void	ps_rr(t_push_swap *ps)
{
	ps_ra(ps);
	ps_rb(ps);
}
