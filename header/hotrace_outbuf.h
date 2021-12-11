/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace_outbuf.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 13:25:52 by agautier          #+#    #+#             */
/*   Updated: 2021/12/11 13:27:42 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_OUTBUF_H
# define HOTRACE_OUTBUF_H

# include <stddef.h>

# ifndef OUTBUF_SIZE
#  define OUTBUF_SIZE 1024
# endif

typedef struct s_outbuf
{
	char	str[OUTBUF_SIZE];
	size_t	head;
}	t_outbuf;

/*
**	Output buffer
*/
void	outbuf_add(t_outbuf *buf, char *str);
void	outbuf_print(t_outbuf *buf);

#endif
