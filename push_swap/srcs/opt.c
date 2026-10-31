/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehras <mehras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 10:41:53 by codespace         #+#    #+#             */
/*   Updated: 2026/10/31 11:23:45 by mehras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"
 
t_stack	*find_opt_mm(t_stack *a, t_stack *b, ssize_t *mm)
{
	if (b->opt_node && b->opt_node->prev)
		if (b->opt_node->prev->num < b->num && b->num < b->opt_node->num)
			return (b->opt_node);
	if ((b->num > mm[2] && b->num < a->num)
		|| (b->num < mm[1] && a->num == mm[1])
		|| (b->num > mm[0] && mm[2] == mm[0]))
		return (a);
	while (a && a->next)
	{
		if ((b->num < a->next->num && a->next->num == mm[1])
			|| ((a->num == mm[0]) && (b->num > a->num))
			|| (b->num < a->next->num && (b->num > a->num)))
			break ;
		a = a->next;
	}
	return (b->opt_node = a->next, a->next);
}
 
static void	set_moves(t_stack *b, t_stack *opt)
{
	ssize_t	min;
 
	b->d_uu = ((b->d_up >= opt->d_up) * b->d_up
			+ (b->d_up < opt->d_up) * opt->d_up);
	min = b->d_uu;
	b->d_dd = ((b->d_down >= opt->d_down) * b->d_down
			+ (b->d_down < opt->d_down) * opt->d_down);
	if (b->d_dd < min)
		min = b->d_dd;
	b->d_ud = opt->d_up + b->d_down;
	if (b->d_ud < min)
		min = b->d_ud;
	b->d_du = opt->d_down + b->d_up;
	if (b->d_du < min)
		min = b->d_du;
	b->d_opt = min;
}
 
static void	set_opt2(t_stack *b, ssize_t *min, ssize_t *num)
{
	if (*num == -1 || *min > b->d_opt
		|| (get_cfg()->tie && *min == b->d_opt))
	{
		*num = b->num;
		*min = b->d_opt;
	}
}
 
static void	mark_opt(t_stack *b, ssize_t num, ssize_t best)
{
	while (b)
	{
		b->opt = (num == b->num) * best + -1 * (num != b->num);
		b = b->next;
	}
}
 
void	set_opt(t_stack *a, t_stack *b)
{
	t_stack	*opt;
	t_stack	*tmp;
	ssize_t	best;
	ssize_t	num;
	ssize_t	mm[3];
 
	best = -1;
	num = -1;
	tmp = b;
	mm[0] = max(a);
	mm[1] = min(a);
	mm[2] = ft_stacklast(a)->num;
	while (b)
	{
		opt = find_opt_mm(a, b, mm);
		set_moves(b, opt);
		set_opt2(b, &best, &num);
		if (best == 0 && !get_cfg()->tie)
			break ;
		b = b->next;
	}
	mark_opt(tmp, num, best);
}
