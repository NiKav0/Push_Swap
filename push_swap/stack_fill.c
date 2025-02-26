/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calmouht <calmouht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 08:11:16 by calmouht          #+#    #+#             */
/*   Updated: 2023/09/12 08:11:36 by calmouht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	index_find(t_stacks *stacks, int index)
{
	int	i;

	i = 0;
	while (stacks->b[i] != index)
		i++;
	stacks->tmp = stacks->b[i];
	return (i);
}

void	a_filler(t_stacks *stacks)
{
	int	lindex;

	while (stacks->len_b != 0)
	{
		lindex = index_find(stacks, stacks->kali[stacks->len_b - 1]);
		if (lindex < stacks->len_b / 2)
		{
			while (stacks->tmp != stacks->b[0])
			{
				rb(stacks);
			}
		}
		else
		{
			while (stacks->tmp != stacks->b[0])
			{
				rrb(stacks);
			}
		}
		pa(stacks);
	}
}
