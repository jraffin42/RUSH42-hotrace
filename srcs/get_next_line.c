/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 11:50:04 by mamaquig          #+#    #+#             */
/*   Updated: 2021/12/11 13:47:37 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

int		check_nl(char *str, int data)
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
	int i;
	int j;
	char tmp;

	//printf("buffer avant swap = %s", buffer);
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
	int i;
	int j;
	char tmp;

	//printf("buffer avant swap = %s", buffer);
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

char	*get_line(char *line, int data)
{
	int 	i;
	int		len;
	char	*tmp;

	len = check_nl(line, data);
	if (line[0] == 0)
	{
		free(line);
		return (NULL);
	}
	if (line[len] == 0)
		return (line);
	tmp = malloc(sizeof(char) * (len + 1));
	if (!tmp)
	{
		free(line);
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		tmp[i] = line[i];
		i++;
	}
	tmp[i] = '\0';
	free(line);
	return (tmp);
}

char	*gnl(int data)
{
	int			ret;
	static char	buffer[4097];
	char		*line;

	line = NULL;
	if (buffer[0] == '\n')
	{
		new_buffer2(buffer);
		return (NULL);
	}
	line = ft_strjoin(line, buffer);
	ret = 1;
	while (check_nl(line, data) == 0 && ret != 0)
	{
		//printf("check = %d\n", check_nl(buffer));
		ret = read(STDIN_FILENO, buffer, 4096);
		if (ret < 0)
		{
			free(line);
			return (NULL);
		}
		buffer[ret] = '\0';
		line = ft_strjoin(line, buffer);
	}
	//printf("buffer = %s", buffer);
	line = get_line(line, data);
	new_buffer(buffer, data);
	return (line);
}
