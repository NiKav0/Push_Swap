/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calmouht <calmouht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 08:03:00 by calmouht          #+#    #+#             */
/*   Updated: 2023/09/17 00:06:31 by calmouht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stacks *stacka)
{
	int	tmp;
	int	i;

	if (stacka->len_a > 1)
	{
		tmp = stacka->a[0];
		i = 0;
		while (i < stacka->len_a - 1)
		{
			stacka->a[i] = stacka->a[i + 1];
			i++;
		}
		stacka->a[i] = tmp;
	}
	write(1, "ra\n", 3);
}

void	rb(t_stacks *stackb)
{
	int	tmp;
	int	i;

	if (stackb->len_b > 1)
	{
		tmp = stackb->b[0];
		i = 0;
		while (i < stackb->len_b - 1)
		{
			stackb->b[i] = stackb->b[i + 1];
			i++;
		}
		stackb->b[i] = tmp;
	}
	write(1, "rb\n", 3);
}

void	rr(t_stacks *stackab)
{
	ra(stackab);
	rb(stackab);
	write(1, "rr\n", 3);
}

void	rra(t_stacks *stacka)
{
	int	tmp;
	int	i;

	if (stacka->len_a > 1)
	{
		tmp = stacka->a[stacka->len_a - 1];
		i = stacka->len_a - 1;
		while (i > 0)
		{
			stacka->a[i] = stacka->a[i - 1];
			i--;
		}
		stacka->a[i] = tmp;
	}
	write(1, "rra\n", 4);
}

void	rrb(t_stacks *stackb)
{
	int	tmp;
	int	i;

	if (stackb->len_b > 1)
	{
		tmp = stackb->b[stackb->len_b - 1];
		i = stackb->len_b - 1;
		while (i > 0)
		{
			stackb->b[i] = stackb->b[i - 1];
			i--;
		}
		stackb->b[i] = tmp;
	}
	write(1, "rrb\n", 4);
}
