/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehras <mehras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 10:34:10 by codespace         #+#    #+#             */
/*   Updated: 2026/10/31 11:12:11 by mehras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"
 
void	uu(t_stack **a, t_stack **b)
{
	t_stack	*opt_a;
	t_stack	*opt_b;
	ssize_t	i;
 
	i = -1;
	opt_b = *b;
	while (opt_b)
	{
		if (opt_b->opt != -1)
			break ;
		opt_b = opt_b->next;
	}
	opt_a = find_opt(*a, opt_b);
	while (++i < (opt_a->d_up * (opt_a->d_up <= opt_b->d_up)
			+ opt_b->d_up * (opt_a->d_up > opt_b->d_up)))
		r(a, b, "rr");
	while (i < opt_a->d_up && ++i > -1)
		r(a, b, "ra");
	while (i < opt_b->d_up && ++i > -1)
		r(a, b, "rb");
}
 
void	dd(t_stack **a, t_stack **b)
{
	t_stack	*opt_a;
	t_stack	*opt_b;
	ssize_t	i;
 
	i = -1;
	opt_b = *b;
	while (opt_b)
	{
		if (opt_b->opt != -1)
			break ;
		opt_b = opt_b->next;
	}
	opt_a = find_opt(*a, opt_b);
	while (++i < (opt_a->d_down * (opt_a->d_down <= opt_b->d_down)
			+ opt_b->d_down * (opt_a->d_down > opt_b->d_down)))
		rr(a, b, "rrr");
	while (i < opt_a->d_down && ++i > -1)
		rr(a, b, "rra");
	while (i < opt_b->d_down && ++i > -1)
		rr(a, b, "rrb");
}
 
void	ud(t_stack **a, t_stack **b)
{
	t_stack	*opt_a;
	t_stack	*opt_b;
	ssize_t	i;
 
	i = -1;
	opt_b = *b;
	while (opt_b)
	{
		if (opt_b->opt != -1)
			break ;
		opt_b = opt_b->next;
	}
	opt_a = find_opt(*a, opt_b);
	while (++i < opt_a->d_up)
		r(a, b, "ra");
	i = -1;
	while (++i < opt_b->d_down)
		rr(a, b, "rrb");
}
 
void	du(t_stack **a, t_stack **b)
{
	t_stack	*opt_a;
	t_stack	*opt_b;
	ssize_t	i;
 
	i = -1;
	opt_b = *b;
	while (opt_b)
	{
		if (opt_b->opt != -1)
			break ;
		opt_b = opt_b->next;
	}
	opt_a = find_opt(*a, opt_b);
	while (++i < opt_b->d_up)
		r(a, b, "rb");
	i = -1;
	while (++i < opt_a->d_down)
		rr(a, b, "rra");
}
 
t_stack	*find_opt(t_stack *a, t_stack *b)
{
	ssize_t	mm[3];
 
	mm[0] = max(a);
	mm[1] = min(a);
	mm[2] = ft_stacklast(a)->num;
	return (find_opt_mm(a, b, mm));
}
