/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 10:03:38 by mderome           #+#    #+#             */
/*   Updated: 2021/12/11 17:55:59 by mamaquig         ###   ########.fr       */
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
	t_node			*line;

	line = gnl(&buf);
	while (line)
	{
		free(line);
		line = gnl(&buf);
	}
	free(line);
	return (EXIT_SUCCESS);
}
