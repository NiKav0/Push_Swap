/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_rules3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calmouht <calmouht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 06:50:06 by calmouht          #+#    #+#             */
/*   Updated: 2023/09/16 12:05:58 by calmouht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

void	b_ss(t_stacks *stackab)
{
	b_sa(stackab);
	b_sb(stackab);
}

void	b_sa(t_stacks *stacka)
{
	int	tmp;

	tmp = 0;
	if (stacka->len_a > 1)
	{
		tmp = stacka->a[0];
		stacka->a[0] = stacka->a[1];
		stacka->a[1] = tmp;
	}
}

void	b_sb(t_stacks *stackb)
{
	int	tmp;

	tmp = 0;
	if (stackb->len_b > 1)
	{
		tmp = stackb->b[0];
		stackb->b[0] = stackb->b[1];
		stackb->b[1] = tmp;
	}
}
