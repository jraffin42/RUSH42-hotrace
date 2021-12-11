/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 10:03:38 by mderome           #+#    #+#             */
/*   Updated: 2021/12/11 17:33:30 by mamaquig         ###   ########.fr       */
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
	t_node			*line;

	line = create_node("keyword-1\nvalue-1\n", 9, 7);
	data = 1;
	line = gnl(&buf, data);
	while (line)
	{
		free(line);
		line = gnl(&buf, 1);
	}
	free(line);
	return (EXIT_SUCCESS);
}
