/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calmouht <calmouht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 01:06:46 by calmouht          #+#    #+#             */
/*   Updated: 2023/09/12 07:33:00 by calmouht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int	s;
	int	e;
	int	i;

	if (!s1)
		return (0);
	i = 0;
	s = 0;
	e = ft_strlen(s1) - 1;
	while (s1[i] && ft_strchr(set, s1[i]))
		s = (i++) + 1;
	if (s >= ft_strlen(s1))
		return ((char *)ft_calloc(sizeof(char), 1));
	i = ft_strlen(s1) - 1;
	while (i && s1[i] && ft_strchr(set, s1[i]))
		e = (i--) - 1;
	return (ft_substr(s1, s, (e - s + 1)));
}
