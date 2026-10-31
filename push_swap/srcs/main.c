/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehras <mehras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:43:21 by codespace         #+#    #+#             */
/*   Updated: 2026/10/31 12:06:25 by mehras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"
 
void	set_d(t_stack *a, t_stack *b)
{
	ssize_t	i;
	ssize_t	size_a;
	ssize_t	size_b;
 
	i = 0;
	size_a = ft_stacksize(a);
	size_b = ft_stacksize(b);
	while (a || b)
	{
		if (a)
		{
			a->d_up = i;
			a->d_down = size_a - i;
			a = a->next;
		}
		if (b)
		{
			b->d_up = i;
			b->d_down = size_b - i;
			b = b->next;
		}
		i++;
	}
}
 
static bool	is_sorted_2(t_ps *ps)
{
	ssize_t	i;
 
	i = 0;
	while (++i < ps->size)
		if (ps->idx[i - 1] > ps->idx[i])
			return (0);
	return (1);
}
 
int	main(int argc, char **argv)
{
	t_ps	ps;
	bool	ok;
 
	if (argc < 2)
		return (1);
	init(&ps);
	ps.in = ft_splits((ssize_t)(argc - 1), &argv[1]);
	ft_nums(&ps);
	if (!ps.out)
		return (ft_free_free(ps.in, ft_strstrstrlen(ps.in)), 1);
	if (!check(&ps))
		return (1);
	ok = 1;
	if (!is_sorted_2(&ps))
		ok = solve(&ps);
	free(ps.lis);
	free(ps.idx);
	return (!ok);
}
