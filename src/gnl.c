/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraffin <jraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 18:54:11 by jraffin           #+#    #+#             */
/*   Updated: 2021/12/12 16:58:49 by jraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <errno.h>
#include <string.h>
#include "hotrace.h"
#include "utils.h"

/*
**	returns :	-1	if first character is \n (and puts head on next character)
**				0	if there isn't 2 \n present
**				1	if there is 2 \n present (and sets *key_len and *val_len)
*/
int	is_node_complete(t_buffer *buf, int end, int *key_len, int *val_len)
{
	int	i;
	int	found_count;

	found_count = 0;
	i = buf->head;
	while (i < end && buf->data[i] != '\n')
		i++;
	if (i < end)
	{
		found_count++;
		*key_len = i - buf->head;
		if (!*key_len)
		{
			buf->head++;
			return (-1);
		}
		i++;
	}
	while (i < end && buf->data[i] != '\n')
		i++;
	if (i < end)
	{
		found_count++;
		*val_len = i - (buf->head + *key_len + 1);
	}
	return (found_count == 2);
}

int	read_in_buffer(t_buffer *buf)
{
	int	readsize;
	int	n;

	if (buf->eof != -1)
		return (1);
	ft_memmove(buf->data, buf->data + buf->head, BUFFER_SIZE - buf->head);
	readsize = buf->head;
	buf->head = 0;
	n = 0;
	while (buf->eof == -1 && readsize)
	{
		n = read(STDIN_FILENO, buf->data + BUFFER_SIZE - readsize, readsize);
		if (n == -1)
		{
			if (write(2, strerror(errno), ft_strlen(strerror(errno))))
				NULL;
			return (1);
		}
		else if (n)
			readsize -= n;
		else
			buf->eof = BUFFER_SIZE - readsize;
	}
	return (0);
}

t_node	*get_next_node(t_buffer *buf)
{
	t_node	*node;
	int		keylen;
	int		valuelen;
	int		end;
	int		complete;

	if (buf->eof == -1)
		end = BUFFER_SIZE;
	else
		end = buf->eof;
	complete = is_node_complete(buf, end, &keylen, &valuelen);
	if (complete == -1 || (complete == 0 && read_in_buffer(buf)))
		return (NULL);
	if (buf->eof != -1)
		end = buf->eof;
	node = NULL;
	if (complete || is_node_complete(buf, end, &keylen, &valuelen))
	{
		node = create_node(buf->data + buf->head, keylen, valuelen);
		buf->head += keylen + valuelen + 2;
	}
	return (node);
}

char	*get_next_keyword(t_buffer *buf, int *key_len)
{
	char	*nl;
	char	*keyword;
	int		end;

	if (buf->eof == -1)
		end = BUFFER_SIZE;
	else
		end = buf->eof;
	nl = ft_memchr(buf->data + buf->head, '\n', end - buf->head);
	if (!nl && read_in_buffer(buf))
		return (NULL);
	if (!nl)
		nl = ft_memchr(buf->data + buf->head, '\n', end - buf->head);
	keyword = NULL;
	if (nl)
	{
		keyword = buf->data + buf->head;
		*key_len = nl - keyword;
		*nl = '\0';
		buf->head += *key_len + 1;
	}
	return (keyword);
}
