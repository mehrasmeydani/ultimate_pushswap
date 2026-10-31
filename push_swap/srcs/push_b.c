/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehras <mehras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:32:13 by codespace         #+#    #+#             */
/*   Updated: 2026/10/31 12:19:36 by mehras           ###   ########.fr       */
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

static void	push_b_nonlisr(t_stack **a, t_stack **b, ssize_t pivot)
{
	ssize_t	n_to_push;
	int		left_over_rb;
 
	n_to_push = to_push(*a);
	left_over_rb = 0;
	while (n_to_push > 0)
	{
		if (try_swap(a, b, &n_to_push))
			continue ;
		if ((*a)->lis == 0 && n_to_push--)
		{
			if (left_over_rb)
				r(a, b, "rb");
			left_over_rb = (((*a)->num < pivot) != get_cfg()->bigger_is_bottom);
			p(a, b, "pb");
		}
		else if (left_over_rb && left_over_rb--)
			r(a, b, "rr");
		else
			r(a, b, "ra");
	}
	if (left_over_rb)
		r(a, b, "rb");
}
 
void	push_b_nonlis(t_stack **a, t_stack **b)
{
	ssize_t	pivot;
 
	pivot = ft_stacksize(*a) * get_cfg()->split / get_cfg()->splits;
	push_b_nonlisr(a, b, pivot);
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
