/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 10:03:38 by mderome           #+#    #+#             */
/*   Updated: 2021/12/11 17:08:33 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"
#include <stdlib.h>

void	print_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		write(1, &tab[i], ft_strlen(tab[i]));
		i++;
	}
}

int	main(void)
{
	static t_buffer	buf;
	int				data;
	char			*line;

	data = 1;
	line = gnl(&buf, data);
	while (line)
	{
		printf("line = %s\n", line);
		free(line);
		line = gnl(&buf, 1);
	}
	printf("fin de &buf\n\n");
	printf("debut de recherche\n");
	line = gnl(&buf, 0);
	while (line)
	{
		printf("line = %s\n", line);
		free(line);
		line = gnl(&buf, 0);
	}
	free(line);
	return (EXIT_SUCCESS);
}
