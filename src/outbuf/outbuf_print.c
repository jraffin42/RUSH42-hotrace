/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outbuf_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 12:05:22 by agautier          #+#    #+#             */
/*   Updated: 2021/12/11 13:16:53 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"
#include <unistd.h>

/*
**	Print output buffer in STDOUT.
*/
void	outbuf_print(t_outbuf *buf)
{
	write(STDOUT_FILENO, buf->str, buf->head);
	buf->head = 0;
}
