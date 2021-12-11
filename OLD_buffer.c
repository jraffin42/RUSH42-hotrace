/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OLD_buffer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraffin <jraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 12:02:35 by agautier          #+#    #+#             */
/*   Updated: 2021/12/11 22:11:33 by jraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "buffer.h"

/*
**	Add str to output buffer.
*/
void	buffer_add(t_buffer *buf, char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (buf->head >= BUFFER_SIZE)
			buffer_print(buf);
		buf->data[buf->head] = str[i];
		i += 1;
		buf->head += 1;
	}
}

/*
**	Print output buffer in STDOUT.
*/
void	buffer_print(t_buffer *buf)
{
	write(STDOUT_FILENO, buf->data, buf->head);
	buf->head = 0;
}
