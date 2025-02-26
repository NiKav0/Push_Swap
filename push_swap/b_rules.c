/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_rules.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calmouht <calmouht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 06:48:43 by calmouht          #+#    #+#             */
/*   Updated: 2023/09/16 12:06:19 by calmouht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

void	b_pa_extender(int i, t_stacks *stacks, int **arr, int flag)
{
	if (flag)
	{
		i = 0;
		while (i != stacks->len_a)
		{
			(*arr)[i + 1] = stacks->a[i];
			i++;
		}
		free(stacks->a);
		stacks->a = (*arr);
	}
	else
	{
		i = 1;
		while (i < stacks->len_b)
		{
			(*arr)[i - 1] = stacks->b[i];
			i++;
		}
		if (stacks->b)
		{
			free(stacks->b);
			stacks->b = (*arr);
		}
	}
}

void	b_pa(t_stacks *stackpa)
{
	int	*new_a;
	int	*new_b;
	int	i;

	new_b = NULL;
	new_a = NULL;
	if (stackpa->len_b > 0)
	{
		new_a = (int *)malloc(sizeof(int) * (stackpa->len_a + 1));
		if (stackpa->len_b != 1)
			new_b = (int *)malloc(sizeof(int) * (stackpa->len_b - 1));
		i = 0;
		new_a[0] = stackpa->b[0];
		b_pa_extender(i, stackpa, &new_a, 1);
		b_pa_extender(i, stackpa, &new_b, 0);
		stackpa->len_a++;
		stackpa->len_b--;
	}
}

void	b_pb_extender(int i, t_stacks *stacks, int **arr, int flag)
{
	if (flag)
	{
		i = 0;
		while (i != stacks->len_b)
		{
			(*arr)[i + 1] = stacks->b[i];
			i++;
		}
		free(stacks->b);
		stacks->b = (*arr);
	}
	else
	{
		i = 1;
		while (i < stacks->len_a)
		{
			(*arr)[i - 1] = stacks->a[i];
			i++;
		}
		if (stacks->a)
		{
			free(stacks->a);
			stacks->a = (*arr);
		}
	}
}

void	b_pb(t_stacks *stackpb)
{
	int	*new_a;
	int	*new_b;
	int	i;

	new_b = NULL;
	new_a = NULL;
	if (stackpb->len_a > 0)
	{
		new_b = (int *)malloc(sizeof(int) * (stackpb->len_b + 1));
		if (stackpb->len_a != 1)
			new_a = (int *)malloc(sizeof(int) * (stackpb->len_a - 1));
		new_b[0] = stackpb->a[0];
		i = 0;
		b_pb_extender(i, stackpb, &new_b, 1);
		b_pb_extender(i, stackpb, &new_a, 0);
		stackpb->len_a--;
		stackpb->len_b++;
	}
}

void	b_rrr(t_stacks *stackab)
{
	b_rra(stackab);
	b_rrb(stackab);
}
