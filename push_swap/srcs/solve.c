/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehras <mehras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 11:10:04 by mehras            #+#    #+#             */
/*   Updated: 2026/10/31 12:11:05 by mehras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"
 
static void	run_one(t_ps *ps, ssize_t split, t_buf *best)
{
	t_stack	*a;
	t_stack	*b;
	t_buf	*cur;
	t_buf	tmp;
 
	a = make_stack(ps);
	if (!a)
		return ;
	b = NULL;
	get_cfg()->split = split;
	cur = get_buf();
	cur->len = 0;
	cur->fail = 0;
	cur->limit = best->len;
	push_swap(&a, &b, ps->size);
	ft_stackclear(&a);
	ft_stackclear(&b);
	if (cur->fail || (best->len != -1 && cur->len >= best->len))
		return ;
	tmp = *best;
	*best = *cur;
	*cur = tmp;
}

static void	simulate_runs(t_ps *ps, t_buf *best)
{
	ssize_t	mode;
	ssize_t	split;
 
	mode = -1;
	while (++mode < 4)
	{
		get_cfg()->tie = mode % 2;
		get_cfg()->bigger_is_bottom = mode / 2;
		split = -1;
		while (++split <= get_cfg()->splits)
			run_one(ps, split, best);
	}
}
 
bool	solve(t_ps *ps)
{
	t_buf	best;
 
	get_cfg()->splits = 40;
	ft_bzero(&best, sizeof(t_buf));
	best.len = -1;
	simulate_runs(ps, &best);
	if (best.len > 0)
		print_ops(&best);
	free(best.ops);
	free(get_buf()->ops);
	return (best.len != -1);
}