/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calmouht <calmouht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 08:03:37 by calmouht          #+#    #+#             */
/*   Updated: 2023/09/15 12:58:40 by calmouht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stacks *stackab)
{
	sa(stackab);
	sb(stackab);
	write(1, "ss\n", 3);
}

void	sa(t_stacks *stacka)
{
	int	tmp;

	tmp = 0;
	if (stacka->len_a > 1)
	{
		tmp = stacka->a[0];
		stacka->a[0] = stacka->a[1];
		stacka->a[1] = tmp;
	}
	write(1, "sa\n", 3);
}

void	sb(t_stacks *stackb)
{
	int	tmp;

	tmp = 0;
	if (stackb->len_b > 1)
	{
		tmp = stackb->b[0];
		stackb->b[0] = stackb->b[1];
		stackb->b[1] = tmp;
	}
	write(1, "sb\n", 3);
}
