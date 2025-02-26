/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calmouht <calmouht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:45:47 by calmouht          #+#    #+#             */
/*   Updated: 2023/09/17 02:08:54 by calmouht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

# define FALSE 0
# define TRUE 1

typedef struct s_stacks
{
	int		*a;
	int		*b;
	int		*kali;
	int		len_a;
	int		len_b;
	int		len_kali;
	int		range;
	int		tmp;
}			t_stacks;

void		sa(t_stacks *stacka);
void		sb(t_stacks *stackb);
void		ss(t_stacks *stackab);
void		pa(t_stacks *stackpa);
void		pb(t_stacks *stackpb);
void		ra(t_stacks *stacka);
void		rb(t_stacks *stackb);
void		rr(t_stacks *stackab);
void		rra(t_stacks *stacka);
void		rrb(t_stacks *stackb);
void		rrr(t_stacks *stackab);
void		sort(t_stacks *stacks);
void		bubble_sort(t_stacks *stacks);
void		swap(t_stacks *stacks, int j);
int			get_range(int size);
char		*ft_strchr(const char *s, int c);
char		**ft_split(char const *s, char c);
int			ft_atoi(const char *str);
int			ft_arlen(char **str);
long		ft_long_atoi(const char *str);
t_stacks	*parse(int argc, char **argv);
void		a_filler(t_stacks *stacks);
int			ft_strcmp(char *a, char *b);
int			has_duplicates(int *arr, int len);
bool		if_sorted(t_stacks *stacks);
int			check_instructions(t_stacks *stacks, char *instr);
void		filler(t_stacks *stacks, int start, int end, int x);
void		b_pa(t_stacks *stackpa);
void		b_pb(t_stacks *stackpb);
void		b_rrr(t_stacks *stackab);
void		b_ra(t_stacks *stacka);
void		b_rb(t_stacks *stackb);
void		b_rr(t_stacks *stackab);
void		b_rra(t_stacks *stacka);
void		b_rrb(t_stacks *stackb);
void		b_ss(t_stacks *stackab);
void		b_sa(t_stacks *stacka);
void		b_sb(t_stacks *stackb);
void		free_stacks(t_stacks *stacks);
int			sorteddescending(t_stacks *stacks);
void		sort_2(t_stacks *stacks);
void		sort_4(t_stacks *stacks, int *c);
void		sort_5(t_stacks *stacks, int *c);
void		sort_3(t_stacks *stacks, int *c);
void		decide(t_stacks *stacks);

#endif
