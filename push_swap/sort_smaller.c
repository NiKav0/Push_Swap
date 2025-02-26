/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_smaller.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calmouht <calmouht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 22:29:20 by calmouht          #+#    #+#             */
/*   Updated: 2023/09/17 02:10:06 by calmouht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_stacks *stacks)
{
	if (stacks->a[0] > stacks->a[1])
		sa(stacks);
}

void	sort_3(t_stacks *stacks, int *c)
{
	if (stacks->len_a == 1)
		exit(0);
	if (c[0] == stacks->a[1] && stacks->a[2] == c[2])
		sa(stacks);
	else if (c[0] == stacks->a[2] && c[2] == stacks->a[1])
		rra(stacks);
	else if (c[2] == stacks->a[0] && c[0] == stacks->a[1])
		ra(stacks);
	else if (c[2] == stacks->a[0] && c[0] == stacks->a[2])
	{
		sa(stacks);
		rra(stacks);
	}
	else if (c[1] == stacks->a[2] && c[2] == stacks->a[1])
	{
		rra(stacks);
		sa(stacks);
	}
}

void	sort_4(t_stacks *stacks, int *c)
{
	int	i;

	i = 0;
	while (stacks->a[i] != c[0])
		i++;
	if (i <= 3)
	{
		while (c[0] != stacks->a[0])
			ra(stacks);
	}
	else
		while (c[0] != stacks->a[0])
			rra(stacks);
	pb(stacks);
	sort_3(stacks, c + 1);
	pa(stacks);
	if (c[1] == stacks->a[0])
		sa(stacks);
	else if (c[3] == stacks->a[0])
		ra(stacks);
}

void	sort_5(t_stacks *stacks, int *c)
{
	int	i;

	i = 0;
	while (stacks->a[i] != stacks->kali[0])
		i++;
	if (i <= 3)
	{
		while (c[0] != stacks->a[0])
			ra(stacks);
	}
	else
		while (c[0] != stacks->a[0])
			rra(stacks);
	pb(stacks);
	sort_4(stacks, &c[1]);
	pa(stacks);
	if (c[1] == stacks->a[0])
		sa(stacks);
	else if (c[4] == stacks->a[0])
		ra(stacks);
}
