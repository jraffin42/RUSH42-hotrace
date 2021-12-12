/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraffin <jraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 22:26:26 by jraffin           #+#    #+#             */
/*   Updated: 2021/12/12 23:07:38 by jraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "buffer.h"
#include "utils.h"

/*
**	Print output buffer in STDOUT.
*/
void	writebuffer_print(t_writebuf *writebuf)
{
	if (write(STDOUT_FILENO, writebuf->str, writebuf->head))
		NULL;
	writebuf->head = 0;
}

/*
**	Add str to output buffer.
*/
void	writebuffer_add(t_writebuf *writebuf, char *str, char *str2, int len)
{
	int	i;

	if (writebuf->head + len > WRITEBUF_SIZE)
		writebuffer_print(writebuf);
	i = 0;
	while (str[i] != '\0')
		writebuf->str[writebuf->head++] = str[i++];
	i = 0;
	while (str2[i] != '\0')
		writebuf->str[writebuf->head++] = str2[i++];
}
