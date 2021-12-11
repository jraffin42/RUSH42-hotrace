/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 16:57:54 by agautier          #+#    #+#             */
/*   Updated: 2021/12/11 16:58:01 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

/*
**	Copy at most len char of src in dest.
*/
char	*ft_strncpy(char *dest, char *src, int len)
{
	int i;

	i = 0;
	while (src[i] != '\0' && i < len)
	{
		dest[i] = src[i];
		i += 1;
	}
	dest[i] = '\0';
	return (dest);
}
