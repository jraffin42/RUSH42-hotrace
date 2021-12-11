/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 10:03:38 by mderome           #+#    #+#             */
/*   Updated: 2021/12/11 13:46:15 by mamaquig         ###   ########.fr       */
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
    int     ret_read;
    //char    *buffer;
    char    *tmp;
	int data;
    //char    **tab;
	data = 1;
	char *line = gnl(data);

    ret_read = 1;
    tmp = NULL;
	while (line)
	{
		printf("line = %s\n", line);
		free(line);
		line = gnl(data);
		// sleep(1);
	}
	printf("fin de data\n\n");
	data = 0;
	printf("debut de recherche\n");
	line = gnl(data);
	while (line)
	{
		printf("line = %s\n", line);
		free(line);
		line = gnl(data);
		// sleep(1);
	}
	free(line);
    //tab = stock_file();
    //tab = ft_split(tmp, '\n');
    //print_tab(tab);
    //free_tab(tab);
    return (0);
}
