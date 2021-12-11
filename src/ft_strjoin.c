/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderome <mderome@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 11:03:27 by mderome           #+#    #+#             */
/*   Updated: 2021/12/11 10:25:48 by mderome          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

char	*ft_cat(char *str, char *src1, char *src2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (src1)
	{
		while (src1[i])
		{
			str[i] = src1[i];
			i++;
		}
	}
	while (src2[j])
	{
		str[i + j] = src2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;

	if (!s1 && !s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	str = ft_cat(str, ((char *)s1), ((char *)s2));
	return (str);
}
