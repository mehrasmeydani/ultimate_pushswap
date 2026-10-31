/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 15:58:21 by codespace         #+#    #+#             */
/*   Updated: 2025/05/01 13:14:52 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	init(t_ps *in)
{
	in->in = NULL;
	in->out = NULL;
	in->lis = NULL;
	in->num = NULL;
	in->sorted = NULL;
	in->lis_util = NULL;
	in->lis_util2 = NULL;
	in->idx = NULL;
	in->size = 0;
}
