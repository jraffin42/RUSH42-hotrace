/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderome <mderome@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 10:03:38 by mderome           #+#    #+#             */
/*   Updated: 2021/12/12 13:47:54 by mderome          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"
#include <unistd.h>
#include <stdio.h>

static void	not_found(char *keyword, int len)
{
	int	ignore;

	ignore = write(STDOUT_FILENO, keyword, len);
	if (write(STDOUT_FILENO, ": Not found.\n", 13) || ignore)
		NULL;
}

static void	print_line(char *str, int len)
{
	int	ignore;

	ignore = write(STDOUT_FILENO, str, len + 2);
	if (write(STDOUT_FILENO, "\n", 1) || ignore)
		NULL;
}

static void	phase1(t_buffer *readbuf, t_node **hashtable)
{
	t_node			*node;

	node = get_next_node(readbuf);
	while (node)
	{
		add_node(hashtable, node);
		node = get_next_node(readbuf);
	}
	readbuf->head++;
}

static void	phase2(t_buffer *readbuf, t_node **hashtable)
{
	char	*keyword;
	char	*value;
	int		key_len;
	int		val_len;

	keyword = get_next_keyword(readbuf, &key_len);
	while (keyword)
	{
		value = seek_value(hashtable, keyword, &val_len);
		if (value)
			print_line(value, val_len);
		else
			not_found(keyword, key_len);
		keyword = get_next_keyword(readbuf, &key_len);
	}
}

int	main(void)
{
	static t_buffer	readbuf;
	t_node			**hashtable;

	readbuf.eof = -1;
	readbuf.head = BUFFER_SIZE;
	hashtable = init_hashtable();
	if (!hashtable)
		return (1);
	phase1(&readbuf, hashtable);
	phase2(&readbuf, hashtable);
	free_hashtable(hashtable);
	return (readbuf.eof == -1 || readbuf.head < readbuf.eof);
}
