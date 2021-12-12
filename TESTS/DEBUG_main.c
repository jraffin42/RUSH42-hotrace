/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DEBUG_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraffin <jraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 10:03:38 by mderome           #+#    #+#             */
/*   Updated: 2021/12/12 23:07:19 by jraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"
#include <unistd.h>
#include <fcntl.h>

int	plug_stdin(int argc, char **argv)
{
	int	fd;

	if (argc < 2)
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		if (write(STDERR_FILENO, "Can't open file.\n", 17))
			NULL;
		return (1);
	}
	if (dup2(fd, STDIN_FILENO) == -1)
	{
		if (write(STDERR_FILENO, "dup2() Error.\n", 14))
			NULL;
		return (1);
	}
	if (close(fd) == -1)
	{
		if (write(STDERR_FILENO, "Close() Error.\n", 15))
			NULL;
		return (1);
	}
	return (0);
}

static void	phase1(t_readbuf *readbuf, t_node **hashtable)
{
	t_node			*node;

	node = get_next_node(readbuf);
	while (node)
	{
		add_node(hashtable, node);
		node = get_next_node(readbuf);
	}
}

static void	phase2(t_readbuf *readbuf, t_writebuf *writebuf, t_node **hashtable)
{
	char	*keyword;
	char	*value;
	int		key_len;
	int		val_len;

	keyword = get_next_keyword(readbuf, &key_len);
	while (keyword)
	{
		if (key_len)
		{
			value = seek_value(hashtable, keyword, &val_len);
			if (value)
				writebuffer_add(writebuf, value, "\n", val_len + 1);
			else
				writebuffer_add(writebuf, keyword,
					": Not found.\n", key_len + 13);
		}
		keyword = get_next_keyword(readbuf, &key_len);
	}
}

int	main(void)
{
	static t_readbuf	readbuf;
	t_writebuf			writebuf;
	t_node				**hashtable;

	readbuf.head = 0;
	readbuf.end = 0;
	writebuf.head = 0;
	hashtable = init_hashtable();
	if (!hashtable)
		return (1);
	phase1(&readbuf, hashtable);
	phase2(&readbuf, &writebuf, hashtable);
	writebuffer_print(&writebuf);
	free_hashtable(hashtable);
	return (!readbuf.eof_reached || readbuf.head < readbuf.end);
}
