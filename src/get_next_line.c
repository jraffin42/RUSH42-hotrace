/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 11:50:04 by mamaquig          #+#    #+#             */
/*   Updated: 2021/12/11 17:55:18 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

int	check_nl(char *str, int data)
{
	int	i;

	i = 0;
	if (!str || str[0] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
		{
			if (data == 0)
				return (i + 1);
			data--;
		}
		i++;
	}
	return (0);
}

void	new_buffer2(char *buffer)
{
	int		i;
	int		j;
	char	tmp;

	j = 1;
	if (j == 0)
	{
		buffer[0] = 0;
		return ;
	}
	i = 0;
	while (buffer[j])
	{
		tmp = buffer[i];
		buffer[i] = buffer[j];
		buffer[j] = tmp;
		i++;
		j++;
	}
	buffer[i] = '\0';
}

void	new_buffer(char *buffer, int data)
{
	int		i;
	int		j;
	char	tmp;

	j = check_nl(buffer, data);
	if (j == 0)
	{
		buffer[0] = 0;
		return ;
	}
	i = 0;
	while (buffer[j])
	{
		tmp = buffer[i];
		buffer[i] = buffer[j];
		buffer[j] = tmp;
		i++;
		j++;
	}
	buffer[i] = '\0';
}

t_node	*gnl(t_buffer	*buf)
{
	int			ret;
	t_node		*line;

	line = NULL;
	if (buf->data[0] == '\n')
	{
		new_buffer2(buf->data);
		return (NULL);
	}
	ret = 1;
	while (check_nl(buf->data, 1) == 0 && ret != 0)
	{
		ret = read(STDIN_FILENO, buf->data, BUFFER_SIZE);
		if (ret < 0)
			return (NULL);
	}
	line = create_node(buf->data, check_nl(buf->data, 0) - 1,
			(check_nl(buf->data, 1) - 1) - check_nl(buf->data, 0));
	printf("key = %s\n", line->key);
	printf("value = %s\n", line->value);
	new_buffer(buf->data, 1);
	return (line);
}
