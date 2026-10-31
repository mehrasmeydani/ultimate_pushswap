/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehras <mehras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:25:58 by codespace         #+#    #+#             */
/*   Updated: 2026/10/31 11:13:15 by mehras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"
 
static void	rotate(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*last;
 
	tmp = (*a)->next;
	last = ft_stacklast(*a);
	(*a)->prev = last;
	last->next = *a;
	(*a)->next = NULL;
	tmp->prev = NULL;
	*a = tmp;
}
 
void	r(t_stack **a, t_stack **b, char *c)
{
	if (c[1] == 'a')
	{
		if (!*a || !(*a)->next)
			return ;
		rotate(a);
	}
	if (c[1] == 'b')
	{
		if (!*b || !(*b)->next)
			return ;
		rotate(b);
	}
	if (c[1] == 'r')
	{
		r(a, b, " a");
		r(a, b, " b");
	}
	if (c[0] != ' ')
		put_op(c);
}
 
static void	rrotate(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*last;
 
	last = ft_stacklast(*a);
	tmp = last->prev;
	(*a)->prev = last;
	last->next = *a;
	tmp->next->prev = NULL;
	tmp->next = NULL;
	*a = (*a)->prev;
}
 
void	rr(t_stack **a, t_stack **b, char *c)
{
	if (c[2] == 'a')
	{
		if (!*a || !(*a)->next)
			return ;
		rrotate(a);
	}
	if (c[2] == 'b')
	{
		if (!*b || !(*b)->next)
			return ;
		rrotate(b);
	}
	if (c[2] == 'r')
	{
		rr(a, b, "  a");
		rr(a, b, "  b");
	}
	if (c[0] != ' ')
		put_op(c);
}