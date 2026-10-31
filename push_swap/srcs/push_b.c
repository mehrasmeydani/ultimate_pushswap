/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehras <mehras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:32:13 by codespace         #+#    #+#             */
/*   Updated: 2026/10/31 10:52:58 by mehras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static ssize_t	to_push(t_stack *a)
{
	ssize_t	n;
 
	n = 0;
	while (a)
	{
		n += !a->lis;
		a = a->next;
	}
	return (n);
}
 
/* After each pb, numbers below the pivot go to the bottom of B.
   The rb waits one step so it can merge with the next ra into rr. */
static void	push_b_nonlisr(t_stack **a, t_stack **b, ssize_t pivot)
{
	ssize_t	left;
	int		pend;
 
	left = to_push(*a);
	pend = 0;
	while (left > 0)
	{
		if (try_swap(a, b, &left))
			continue ;
		if ((*a)->lis == 0 && left--)
		{
			if (pend)
				r(a, b, "rb");
			pend = ((*a)->num < pivot);
			p(a, b, "pb");
		}
		else if (pend && pend--)
			r(a, b, "rr");
		else
			r(a, b, "ra");
	}
	if (pend)
		r(a, b, "rb");
}
 
static void	push_b_nonlisrr(t_stack **a, t_stack **b, ssize_t pivot)
{
	ssize_t	left;
 
	left = to_push(*a);
	while (left > 0)
	{
		if (try_swap(a, b, &left))
			continue ;
		if ((*a)->lis == 0 && left--)
		{
			p(a, b, "pb");
			if ((*b)->num < pivot)
				r(a, b, "rb");
		}
		else
			rr(a, b, "rra");
	}
}
 
void	push_b_nonlis(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	ssize_t	max_dr;
	ssize_t	max_drr;
 
	max_dr = 0;
	max_drr = -1;
	tmp = *a;
	while (tmp)
	{
		if (tmp->lis == 1)
		{
			if (max_drr == -1)
				max_drr = tmp->d_down;
			max_dr += 1;
		}
		else if (max_dr > 0)
			max_dr -= 1;
		tmp = tmp->next;
	}
	if (max_dr > max_drr)
		push_b_nonlisrr(a, b, ft_stacksize(*a) / 2);
	else
		push_b_nonlisr(a, b, ft_stacksize(*a) / 2);
}

void	sort_3(t_stack **a)
{
	if (is_sorted(*a))
		return ;
	if ((*a)->num == 1 && (*a)->next->num == 2)
		return (rr(a, NULL, "rra"));
	if ((*a)->num == 2)
		return (r(a, NULL, "ra"), sort_3(a));
	if ((*a)->num == 0 || (*a)->num == 1)
		return (s(a, NULL, "sa"), sort_3(a));
}
