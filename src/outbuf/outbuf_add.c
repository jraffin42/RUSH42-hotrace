/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outbuf_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 12:02:35 by agautier          #+#    #+#             */
/*   Updated: 2021/12/11 13:18:53 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

/*
**	Add str in output buffer.
*/
void	outbuf_add(t_outbuf *buf, char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (buf->head >= OUTBUF_SIZE)
			outbuf_print(buf);
		buf->str[buf->head] = str[i];
		i += 1;
		buf->head += 1;
	}
}
