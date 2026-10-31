/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehras <mehras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 10:50:00 by mehras            #+#    #+#             */
/*   Updated: 2026/10/31 10:53:36 by mehras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static int	fits(ssize_t prev, ssize_t v, ssize_t next)
{
	if (prev < next)
		return (prev < v && v < next);
	return (v > prev || v < next);
}
 
static ssize_t	kept_before_top(t_stack *a)
{
	t_stack	*t;
 
	t = ft_stacklast(a);
	while (t && !t->lis)
		t = t->prev;
	return (t->num);
}
 
static ssize_t	kept_after(t_stack *from, t_stack *a)
{
	while (from && !from->lis)
		from = from->next;
	if (from)
		return (from->num);
	while (!a->lis)
		a = a->next;
	return (a->num);
}
 
int	try_swap(t_stack **a, t_stack **b, ssize_t *left)
{
	t_stack	*x;
	int		ok;
 
	if (!*a || !(*a)->next || (*a)->lis == (*a)->next->lis)
		return (0);
	if (!(*a)->lis)
	{
		x = *a;
		ok = fits(x->next->num, x->num, kept_after(x->next->next, *a));
	}
	else
	{
		x = (*a)->next;
		ok = fits(kept_before_top(*a), x->num, (*a)->num);
	}
	if (!ok)
		return (0);
	s(a, b, "sa");
	x->lis = 1;
	(*left)--;
	return (1);
}