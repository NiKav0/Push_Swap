/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calmouht <calmouht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 06:52:03 by calmouht          #+#    #+#             */
/*   Updated: 2023/09/17 00:26:26 by calmouht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "get_next_line.h"
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

int	check_instructions(t_stacks *stacks, char *instr)
{
	if (ft_strcmp(instr, "sa\n") == 0)
		b_sa(stacks);
	else if (ft_strcmp(instr, "sb\n") == 0)
		b_sb(stacks);
	else if (ft_strcmp(instr, "ss\n") == 0)
		b_ss(stacks);
	else if (ft_strcmp(instr, "pa\n") == 0)
		b_pa(stacks);
	else if (ft_strcmp(instr, "pb\n") == 0)
		b_pb(stacks);
	else if (ft_strcmp(instr, "ra\n") == 0)
		b_ra(stacks);
	else if (ft_strcmp(instr, "rb\n") == 0)
		b_rb(stacks);
	else if (ft_strcmp(instr, "rr\n") == 0)
		b_rr(stacks);
	else if (ft_strcmp(instr, "rra\n") == 0)
		b_rra(stacks);
	else if (ft_strcmp(instr, "rrb\n") == 0)
		b_rrb(stacks);
	else
		return (0);
	return (1);
}

void	ko_ok(t_stacks *stacks, bool true_or_false)
{
	(void)true_or_false;
	if (sorteddescending(stacks) == 0 && stacks->len_b == 0)
	{
		write(1, "OK\n", 3);
	}
	else
		write(1, "KO\n", 3);
}

int	main(int ac, char **av)
{
	t_stacks	*stacks;
	char		*buf;
	bool		sorted_flag;

	sorted_flag = false;
	if (ac < 2)
		return (0);
	stacks = parse(ac - 1, av + 1);
	if (stacks == NULL)
		return (write(2, "Error\n", 6));
	if (ac != 2 && ft_strchr(av[1], ' ') != NULL)
		return (write(2, "Error\n", 6));
	if (has_duplicates(stacks->a, stacks->len_a) != 0)
		return (write(2, "Error\n", 6));
	buf = get_next_line(0);
	while (buf)
	{
		check_instructions(stacks, buf);
		free(buf);
		buf = get_next_line(0);
		if (buf == NULL)
			break ;
	}
	ko_ok(stacks, sorted_flag);
}
