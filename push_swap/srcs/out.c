/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehras <mehras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 11:10:52 by mehras            #+#    #+#             */
/*   Updated: 2026/10/31 12:01:18 by mehras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"
 
t_buf	*get_buf(void)
{
	static t_buf	buf;
 
	return (&buf);
}
 
static char	*op_name(ssize_t i)
{
	static char	*names[11] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb",
		"rr", "rra", "rrb", "rrr"};
 
	return (names[i]);
}
 
static bool	grow(t_buf *b)
{
	char	*new;
 
	new = (char *)malloc(b->cap * 2 + 64);
	if (!new)
		return (b->fail = 1, 0);
	if (b->ops)
		ft_memcpy(new, b->ops, b->len);
	free(b->ops);
	b->ops = new;
	b->cap = b->cap * 2 + 64;
	return (1);
}
 
void	put_op(char *c)
{
	t_buf	*b;
	ssize_t	i;
 
	b = get_buf();
	if (b->limit > 0 && b->len >= b->limit)
		b->fail = 1;
	if (b->fail || (b->len == b->cap && !grow(b)))
		return ;
	i = 0;
	while (i < 11 && ft_strncmp(op_name(i), c, 4))
		i++;
	b->ops[b->len++] = (char)i;
}
 
void	print_ops(t_buf *b)
{
	char	*out;
	ssize_t	i;
	ssize_t	j;
	ssize_t	k;
 
	out = (char *)malloc(b->len * 4 + 1);
	if (!out)
		return ;
	i = -1;
	j = 0;
	while (++i < b->len)
	{
		k = 0;
		while (op_name(b->ops[i])[k])
			out[j++] = op_name(b->ops[i])[k++];
		out[j++] = '\n';
	}
	b->fail = (write(1, out, j) != j);
	free(out);
}