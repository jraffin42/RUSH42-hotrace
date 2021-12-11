/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 12:05:22 by agautier          #+#    #+#             */
/*   Updated: 2021/12/11 14:59:23 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"
#include <unistd.h>

/*
**	Print output buffer in STDOUT.
*/
void	buffer_print(t_buffer *buf)
{
	write(STDOUT_FILENO, buf->data, buf->head);
	buf->head = 0;
}
