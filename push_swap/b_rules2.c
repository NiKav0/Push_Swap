/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_rules2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calmouht <calmouht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 06:49:14 by calmouht          #+#    #+#             */
/*   Updated: 2023/09/16 12:06:40 by calmouht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

void	b_ra(t_stacks *stacka)
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
}

void	b_rb(t_stacks *stackb)
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
}

void	b_rr(t_stacks *stackab)
{
	b_ra(stackab);
	b_rb(stackab);
}

void	b_rra(t_stacks *stacka)
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
}

void	b_rrb(t_stacks *stackb)
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
}
