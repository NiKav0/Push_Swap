/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calmouht <calmouht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:53:53 by calmouht          #+#    #+#             */
/*   Updated: 2023/09/16 10:48:44 by calmouht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa_extender(int i, t_stacks *stacks, int **arr, int flag)
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

void	pa(t_stacks *stackpa)
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
		pa_extender(i, stackpa, &new_a, 1);
		pa_extender(i, stackpa, &new_b, 0);
		stackpa->len_a++;
		stackpa->len_b--;
	}
	write(1, "pa\n", 3);
}

void	pb_extender(int i, t_stacks *stacks, int **arr, int flag)
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

void	pb(t_stacks *stackpb)
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
		pb_extender(i, stackpb, &new_b, 1);
		pb_extender(i, stackpb, &new_a, 0);
		stackpb->len_a--;
		stackpb->len_b++;
	}
	write(1, "pb\n", 3);
}

void	rrr(t_stacks *stackab)
{
	rra(stackab);
	rrb(stackab);
	write(1, "rrr\n", 4);
}
