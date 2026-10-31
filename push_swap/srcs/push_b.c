/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehras <mehras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:32:13 by codespace         #+#    #+#             */
/*   Updated: 2026/10/31 10:35:01 by mehras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	set_zero_b(t_push_b *push_b)
{
	push_b->a_direction = R;
	push_b->b_direction = R;
	push_b->n_a_rotation = 0;
	push_b->n_b_rotation = 0;
}

t_stack *find_optimal_push_b();


void	actual_push_b(t_stack **a, t_stack **b, t_push_b *push_b)
{
	ssize_t	i;

	i = -1;
	while (++i < push_b->n_a_rotation) {
		if (push_b->a_direction == push_b->b_direction)
		{
			if (push_b->a_direction == R)
			{				
				if (i < push_b->n_b_rotation)
					r(a, b, "rr");
				else
					r(a, b, "ra");
			}
			else
			{
				if (i < push_b->n_b_rotation)
					rr(a, b, "rrr");
				else
					rr(a, b, "rra");
			}
		}
		else
		{
			if (push_b->a_direction == R)
				r(a, b, "ra");
			else
				rr(a, b, "rra");
		}
	}
	p(a, b, "pb");
}

void	push_b_opt(t_stack **a, t_stack **b, t_push_b *push_b)
{
	t_stack *tmp;
	t_stack *tmp_2;
	t_stack *opt;

	set_d(*a, *b);
	tmp = *a;
	while (tmp && tmp->lis == 1)
		tmp = tmp->next;
	tmp_2 = ft_stacklast(*a);
	while (tmp_2 && tmp_2->lis)
		tmp_2 = tmp_2->prev;
	if (tmp_2->d_down > tmp->d_up)
	{
		push_b->a_direction = R;
		opt = tmp;
		push_b->n_a_rotation = opt->d_up;
	}
	else
	{
		push_b->a_direction = RR;
		opt = tmp_2;
		push_b->n_a_rotation = opt->d_down;
	}
	tmp_2 = NULL;
	if (*b)
	{
		tmp = *b;
		while (tmp)
		{
			if (tmp->num < opt->num)
				if (!tmp_2 || tmp->num > tmp_2->num)
					tmp_2 = tmp;
			tmp = tmp->next;
		}
		if (tmp_2)
		{
			if (tmp_2->d_up <= tmp_2->d_down)
			{
				push_b->b_direction = R;
				push_b->n_b_rotation = tmp_2->d_up;	
			}
			else
			{
				push_b->b_direction = RR;
				push_b->n_b_rotation = tmp_2->d_down;	
			}
		}
	}
	actual_push_b(a, b, push_b);
}

void	push_b_nonlis(t_stack **a, t_stack **b)
{
	t_stack		*tmp;
	t_push_b	push_b;
	ssize_t		lis_count;

	set_zero_b(&push_b);
	lis_count = 0;
	tmp = *a;
	while (tmp) {
		if (tmp->lis == 1)
			lis_count++;
		tmp = tmp->next;
	}
	while (ft_stacksize(*a) != lis_count) {
		push_b_opt(a, b, &push_b);
	}
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
