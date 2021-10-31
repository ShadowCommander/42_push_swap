#include "push_swap.h"

/*
 *
 * 4123
 * 1234
 *
 * 213685 sa
 * 123685 rra
 * 512368 rra
 * 851236 sa
 * 581236 rra
 * 658123 sa
 * 568123 ra
 * 681235 ra
 * 812356 ra
 * 123568
 * 9
 *
 * bubblesort
 * 213685 sa
 * 123685 ra
 * 236851 ra
 * 368512 ra
 * 685123 ra
 * 851236 sa
 * 581236 rra
 * 658123 sa
 * 568123 ra
 * 681235 ra
 * 812356 ra
 * 123568 
 * 11
 *
 * double
 * 213685		pb
 * 13685	2	pb
 * 3685		12	pb
 * 685		312	rr
 * 856		123	ss
 * 586		213	rrr
 * 658		321	pa
 * 23658	1	pa
 * 123658		
 * 8
 *
 * double
 * 123465
 */

void	ps_insert_sort(t_push_swap *ps)
{
}

/*
 * check whether forward or backward rotate does less steps
 *   sort both by making a copy
 *
 * when out of place push b
 * rotate until b < next
 *   simple is just b top
 *   complex is whichever b is next and cost analysis
 *
 *
 */
void	ps_insertion_sort(t_push_swap *ps)
{
	t_array	*reset;

	reset = ps_create_reset(ps);
	ps_insert_sort(t_push_swap *ps);
	ps_reset(ps, reset);
}

typedef struct	s_array
{
	void	**arr;
	size_t	size;
}				t_array;

void	ps_reset(t_push_swap *ps, t_array *reset)
{
	size_t	i;

	ps->a->size = reset->size;
	ps->a->start = reset->arr[0];
	i = 0;
	while (reset->arr[i])
	{
		reset->arr[i]->next = reset->arr[i + 1];
		if (reset->arr[i]->next == NULL)
			ps->a->end = reset->arr[i];
		i++;
	}
	ps->b->start = NULL;
	ps->b->end = NULL;
	ps->b->size = 0;
}

t_node	**ps_create_reset(t_push_swap *ps)
{
	t_array	*reset;
	t_node	*node;
	size_t	i;

	reset = (t_array *)malloc(sizeof(*reset));
	reset->size = ps->a->size;
	reset->arr = (t_node **)malloc(sizeof(*reset->arr) * reset->size);
	node = ps->a->start;
	i = 0;
	while (node)
	{
		reset->arr[i] = node;
		i++;
		node = node->next;
	}
	reset->arr[i] = NULL;
	return (reset);
}
