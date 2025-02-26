/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calmouht <calmouht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 07:07:04 by calmouht          #+#    #+#             */
/*   Updated: 2023/09/16 23:56:54 by calmouht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

char	*ft_strchr(const char *s, int c)
{
	char	str;
	char	*alt;
	int		i;

	i = 0;
	alt = (char *)s;
	str = c;
	while (alt[i] != str)
	{
		if (alt[i] == '\0')
			return (NULL);
		i++;
	}
	return ((char *)alt + i);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str && str[i] != '\0')
		i++;
	return (i);
}

int	has_duplicates(int *arr, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*tm;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	j = ft_strlen(s);
	if (start > j)
	{
		start = j;
		len = 0;
	}
	else if (j < start + len)
		len = j - start;
	tm = malloc(len + 1);
	if (!tm)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		tm[i] = s[start + i];
		i++;
	}
	tm[i] = '\0';
	return (tm);
}
