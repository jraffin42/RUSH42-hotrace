/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 10:03:38 by mderome           #+#    #+#             */
/*   Updated: 2021/12/11 16:48:23 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

void    free_tab(char **tab)
{
    int i;

    i = 0;
    while (tab[i])
    {
        free(tab[i]);
        i++;
    }
    free(tab);
    tab = NULL;
}

void print_tab(char **tab)
{
    int i = 0;

    while (tab[i])
    {
        write(1, &tab[i], ft_strlen(tab[i]));
        i++;
    }
}

int main(void)
{
	static t_buffer	buf;
	int				data;
    //char    **tab;
	data = 1;
	char *line = gnl(&buf, data);

	while (line)
	{
		printf("line = %s\n", line);
		free(line);
		line = gnl(&buf);
		// sleep(1);
	}
	printf("fin de &buf\n\n");
	printf("debut de recherche\n");
	line = gnl(&buf);
	while (line)
	{
		printf("line = %s\n", line);
		free(line);
		line = gnl(&buf);
		// sleep(1);
	}
	free(line);
    // tab = stock_file();
    // tab = ft_split(tmp, '\n');
    // print_tab(tab);
    // free_tab(tab);
    return (0);
}
