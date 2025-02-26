/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calmouht <calmouht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 22:40:36 by calmouht          #+#    #+#             */
/*   Updated: 2023/09/17 02:09:28 by calmouht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorteddescending(t_stacks *stacks)
{
	int	i;

	i = 0;
	while (i < stacks->len_a - 1)
	{
		if (stacks->a[i] > stacks->a[i + 1])
		{
			return (1);
		}
		i++;
	}
	return (0);
}

#ifndef BONUS

void	bubble_sort(t_stacks *stacks)
{
	int	i;
	int	swapped;
	int	j;

	i = 0;
	swapped = false;
	while (i < stacks->len_kali)
	{
		swapped = false;
		j = 0;
		while (j < stacks->len_kali - i - 1)
		{
			if (stacks->kali[j] > stacks->kali[j + 1])
			{
				swap(stacks, j);
				swapped = true;
			}
			j++;
		}
		if (!swapped)
			break ;
		i++;
	}
}

void	decide(t_stacks *stacks)
{
	stacks->kali = (int *)malloc(sizeof(int) * stacks->len_a);
	stacks->len_kali = stacks->len_a;
	bubble_sort(stacks);
	if (stacks->len_a > 5)
		sort(stacks);
	else
	{
		if (stacks->len_a == 2)
			sort_2(stacks);
		else if (stacks->len_a == 3)
			sort_3(stacks, stacks->kali);
		else if (stacks->len_a == 4)
			sort_4(stacks, stacks->kali);
		else
			sort_5(stacks, stacks->kali);
	}
}

#endif