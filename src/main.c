/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraffin <jraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 10:03:38 by mderome           #+#    #+#             */
/*   Updated: 2021/12/12 20:37:11 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"
#include <unistd.h>

#ifdef TEST_WRITEBUF
	#include <unistd.h>

	# ifndef WRITEBUF_SIZE
	#  define WRITEBUF_SIZE 4096
	# endif

	typedef struct s_writebuf
	{
		char	str[WRITEBUF_SIZE];
		size_t	head;
	}	t_writebuf;

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
	void	writebuffer_add(t_writebuf *writebuf, char *str)
	{
		unsigned int	i;

		i = 0;
		while (str[i] != '\0')
		{
			if (writebuf->head >= WRITEBUF_SIZE)
				writebuffer_print(writebuf);
			writebuf->str[writebuf->head] = str[i];
			i += 1;
			writebuf->head += 1;
		}
	}

	static void	not_found(t_writebuf *writebuf, char *keyword)
	{
		writebuffer_add(writebuf, keyword);
		writebuffer_add(writebuf, ": Not found.\n");
	}

	static void	print_line(t_writebuf *writebuf, char *str)
	{
		writebuffer_add(writebuf, str);
		writebuffer_add(writebuf, "\n");
	}

	static void	phase2(t_buffer *readbuf, t_writebuf *writebuf, t_node **hashtable)
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
				print_line(writebuf, value);
			else
				not_found(writebuf, keyword);
			keyword = get_next_keyword(readbuf, &key_len);
		}
	}
#else

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

	ignore = write(STDOUT_FILENO, str, len);
	if (write(STDOUT_FILENO, "\n", 1) || ignore)
		NULL;
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

#endif

static void	phase1(t_buffer *readbuf, t_node **hashtable)
{
	t_node			*node;

	node = get_next_node(readbuf);
	while (node)
	{
		add_node(hashtable, node);
		node = get_next_node(readbuf);
	}
}

int	main(void)
{
	static t_buffer	readbuf;
	t_node			**hashtable;
	#ifdef TEST_WRITEBUF
		t_writebuf writebuf;
	#endif

	readbuf.eof = -1;
	readbuf.head = BUFFER_SIZE;
	hashtable = init_hashtable();
	if (!hashtable)
		return (1);
	phase1(&readbuf, hashtable);
	#ifdef TEST_WRITEBUF
		phase2(&readbuf, &writebuf, hashtable);
		writebuffer_print(&writebuf);
	#else
		phase2(&readbuf, hashtable);
	#endif
	free_hashtable(hashtable);
	return (readbuf.eof == -1 || readbuf.head < readbuf.eof);
}
