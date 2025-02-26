/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calmouht <calmouht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 06:46:59 by calmouht          #+#    #+#             */
/*   Updated: 2023/09/17 02:10:38 by calmouht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"

bool	int_health_check(char *numb)
{
	int	i;

	i = 0;
	if ((numb[i] == '-' || numb[i] == '+') && numb[i + 1] != '\0')
		i++;
	while (numb[i] != 0)
	{
		if (numb[i] < '0' || numb[i] > '9')
			return (false);
		i++;
	}
	if ((ft_long_atoi(numb) > INT_MAX || ft_long_atoi(numb) < INT_MIN)
		|| ft_strlen(numb) > 11) 
		return (false);
	return (true);
}

t_stacks	*stacks_spawner(int argc, char **argv)
{
	t_stacks	*stacks;
	int			i;

	i = 0;
	stacks = malloc(sizeof(t_stacks));
	stacks->a = malloc(sizeof(int) * argc);
	stacks->b = malloc(sizeof(int) * argc);
	stacks->kali = malloc(sizeof(int) * argc);
	stacks->len_a = argc;
	stacks->len_b = 0;
	stacks->len_kali = argc;
	stacks->range = get_range(argc);
	while (i < argc)
	{
		if (int_health_check(argv[i]) == false)
		{
			free_stacks(stacks);
			return (NULL);
		}
		stacks->a[i] = ft_atoi(argv[i]);
		stacks->kali[i] = stacks->a[i];
		i++;
	}
	free(stacks->kali);
	return (stacks);
}

t_stacks	*parse(int argc, char **argv)
{
	char		**holder;
	t_stacks	*stacks;
	int			i;

	i = 0;
	if (ft_strchr(argv[0], ' ') != NULL)
	{
		holder = ft_split(argv[0], ' ');
		stacks = stacks_spawner(ft_arlen(holder), holder);
		while (holder[i] != NULL)
		{
			free(holder[i]);
			i++;
		}
		free(holder);
		holder = NULL;
	}
	else
		stacks = stacks_spawner(argc, argv);
	return (stacks);
}

void	free_stacks(t_stacks *stacks)
{
	free(stacks->a);
	free(stacks->b);
	free(stacks->kali);
	free(stacks);
}
