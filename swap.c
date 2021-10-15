
void	swap_top(t_llist *list)
{
	t_node	*node;

	node = list->start->next;
	list->start->next = list->start->next->next;
	node->next = list->start;
	list->start = node;
}

void	ps_sa(t_push_swap *ps)
{
	swap_top(ps->a);
}

void	ps_sb(t_push_swap *ps)
{
	swap_top(ps->b);
}

void	ps_ss(t_push_swap *ps)
{
	swap_top(ps->a);
	swap_top(ps->b);
}
