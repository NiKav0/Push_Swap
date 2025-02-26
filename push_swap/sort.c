/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calmouht <calmouht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 01:36:55 by calmouht          #+#    #+#             */
/*   Updated: 2023/09/17 02:07:51 by calmouht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_range(int size)
{
	return (size * 0.0375 + 11.25);
}

int	range_check(t_stacks *stack, int start, int end, int num)
{
	int	i;

	i = 0;
	while (stack->kali[i] != num)
		i++;
	if (i < start)
		return (0);
	if (i > end)
		return (1);
	if (i <= end && i >= start)
		return (2);
	return (3);
}

void	sort(t_stacks *stacks)
{
	int	i;
	int	start;
	int	end;

	stacks->range = get_range(stacks->len_a);
	if (stacks->range > stacks->len_kali)
		stacks->range = stacks->len_kali;
	start = 0;
	end = stacks->range - 1;
	i = 0;
	while (i < stacks->len_a)
	{
		stacks->kali[i] = stacks->a[i];
		i++;
	}
	filler(stacks, start, end, i);
	a_filler(stacks);
}

void	filler(t_stacks *stacks, int start, int end, int x)
{
	while (stacks->len_a != 0)
	{
		x = range_check(stacks, start, end, stacks->a[0]);
		if (x == 0)
		{
			pb(stacks);
			rb(stacks);
			if (stacks->len_kali > end - 1)
			{
				end++;
				start++;
			}
		}
		else if (x == 1)
			ra(stacks);
		else
		{
			pb(stacks);
			if (stacks->len_kali > end - 1)
			{
				end++;
				start++;
			}
		}
	}
}
