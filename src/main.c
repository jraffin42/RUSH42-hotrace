/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 11:09:19 by agautier          #+#    #+#             */
/*   Updated: 2021/12/11 13:29:05 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "hotrace.h"

int	main(void)
{
	t_outbuf	outbuf;

	outbuf.head = 0;
	outbuf_add(&outbuf, "Hello World!\n");
	outbuf_add(&outbuf, "My name is agautier\n");
	outbuf_print(&outbuf);
	return (EXIT_SUCCESS);
}
