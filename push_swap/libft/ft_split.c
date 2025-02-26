/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calmouht <calmouht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 01:09:34 by calmouht          #+#    #+#             */
/*   Updated: 2023/09/12 07:33:27 by calmouht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	schar(const char *s, char c, size_t b)
{
	while (s[b] && s[b] == c)
		b++;
	return (b);
}

static size_t	echar(const char *s, char c, size_t l)
{
	while (s[l] && s[l] != c)
		l++;
	return (l);
}

static size_t	count(char const *s, char c)
{
	int	i;
	int	b;
	int	cnt;

	i = 0;
	cnt = 0;
	while (i < ft_strlen(s))
	{
		i = schar(s, c, i);
		b = echar(s, c, i);
		if (i < b)
			cnt++;
		i = b;
	}
	return (cnt);
}

static void	split(char **r, char const *s, char c)
{
	int	cnt;
	int	i;
	int	b;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		i = schar(s, c, i);
		b = echar(s, c, i);
		if (i < b)
			r[cnt++] = ft_substr(s, i, (b - i));
		i = b;
	}
	r[cnt] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**rslt;

	if (!s)
		return (NULL);
	rslt = (char **)malloc(sizeof(char *) * (count(s, c) + 1));
	if (!rslt)
		return (NULL);
	split(rslt, s, c);
	return (rslt);
}
