/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calmouht <calmouht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 19:46:05 by calmouht          #+#    #+#             */
/*   Updated: 2023/09/17 02:10:25 by calmouht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	if_sorted(t_stacks *stacks)
{
	int	i;

	i = 0;
	while (i < stacks->len_a - 1)
	{
		if (stacks->a[i] > stacks->a[i + 1])
			return (false);
		i++;
	}
	return (true);
}

int	main(int ac, char **av)
{
	t_stacks	*stacks;

	if (ac < 3)
		return (0);
	stacks = parse(ac - 1, av + 1);
	if (stacks == NULL)
		return (write(2, "Error\n", 6));
	if (ac != 2 && ft_strchr(av[1], ' ') != NULL)
		return (write(2, "Error\n", 6));
	if (has_duplicates(stacks->a, stacks->len_a) != 0)
		return (write(2, "Error\n", 6));
	if (if_sorted(stacks) == true)
		return (0);
	decide(stacks);
	return (0);
}
