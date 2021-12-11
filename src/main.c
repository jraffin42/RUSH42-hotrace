/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraffin <jraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 10:03:38 by mderome           #+#    #+#             */
/*   Updated: 2021/12/11 18:28:32 by jraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"
#include <stdlib.h>

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
