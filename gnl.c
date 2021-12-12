/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraffin <jraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 18:54:11 by jraffin           #+#    #+#             */
/*   Updated: 2021/12/12 22:23:19 by jraffin          ###   ########.fr       */
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
static inline int	is_node_complete(t_readbuf *buf, int *key_len, int *val_len)
{
	int	i;
	int	found_count;

	found_count = 0;
	i = buf->head;
	while (i < buf->end && buf->data[i] != '\n')
		i++;
	if (i < buf->end)
	{
		found_count++;
		*key_len = i++ - buf->head;
		if (!*key_len)
		{
			buf->head++;
			return (-1);
		}
	}
	while (i < buf->end && buf->data[i] != '\n')
		i++;
	if (i < buf->end)
	{
		found_count++;
		*val_len = i - (buf->head + *key_len + 1);
	}
	return (found_count == 2);
}

int	read_in_buffer(t_readbuf *buf)
{
	int	read_n;

	if (buf->eof_reached)
		return (1);
	ft_memmove(buf->data, buf->data + buf->head, buf->end - buf->head);
	buf->end -= buf->head;
	buf->head = 0;
	read_n = read(STDIN_FILENO, buf->data + buf->end, READBUF_SIZE - buf->end);
	if (read_n > 0)
	{
		buf->end += read_n;
		return (0);
	}
	buf->eof_reached = 1;
	return (1);
}

t_node	*get_next_node(t_readbuf *buf)
{
	t_node	*node;
	int		key_len;
	int		val_len;
	int		complete;

	key_len = 0;
	val_len = 0;
	complete = is_node_complete(buf, &key_len, &val_len);
	while (!complete && !read_in_buffer(buf))
		complete = is_node_complete(buf, &key_len, &val_len);
	if (complete != 1)
		return (NULL);
	node = create_node(buf->data + buf->head, key_len, val_len);
	buf->head += key_len + val_len + 2;
	return (node);
}

char	*get_next_keyword(t_readbuf *buf, int *key_len)
{
	char	*nl;
	char	*keyword;

	nl = ft_memchr(buf->data + buf->head, '\n', buf->end - buf->head);
	while (!nl && !read_in_buffer(buf))
		nl = ft_memchr(buf->data + buf->head, '\n', buf->end - buf->head);
	if (!nl)
		return (NULL);
	keyword = buf->data + buf->head;
	*key_len = nl - keyword;
	buf->head += *key_len + 1;
	*nl = '\0';
	return (keyword);
}
