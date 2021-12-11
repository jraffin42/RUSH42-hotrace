/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderome <mderome@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 11:02:40 by mderome           #+#    #+#             */
/*   Updated: 2021/12/11 10:25:34 by mderome          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

static char	**error(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static unsigned int	count_strs(char const *s, char c)
{
	unsigned int	i;
	unsigned int	count;

	if (!s[0])
		return (0);
	i = 0;
	count = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			count++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		count++;
	return (count);
}

static void	get_next_str(char **str, unsigned int *str_len, char c)
{
	unsigned int	i;

	*str += *str_len;
	*str_len = 0;
	i = 0;
	while (**str && **str == c)
		(*str)++;
	while ((*str)[i])
	{
		if ((*str)[i] == c)
			return ;
		(*str_len)++;
		i++;
	}
}

char	**ft_split2(char const *s, char c, char **tab, unsigned int nbr_strs)
{
	char			*str;
	unsigned int	str_len;
	unsigned int	i;

	i = 0;
	str = (char *)s;
	str_len = 0;
	while (i < nbr_strs)
	{
		get_next_str(&str, &str_len, c);
		tab[i] = (char *)malloc(sizeof(char) * (str_len + 1));
		if (!tab[i])
			return (error(tab));
		ft_strlcpy(tab[i], str, str_len + 1);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char			**tab;
	unsigned int	nbr_strs;

	if (!s)
		return (NULL);
	nbr_strs = count_strs(s, c);
	tab = (char **)malloc(sizeof(char *) * (nbr_strs + 1));
	if (!tab)
		return (error(tab));
	tab = ft_split2(s, c, tab, nbr_strs);
	return (tab);
}
