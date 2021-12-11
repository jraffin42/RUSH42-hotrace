/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace_buffer.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 13:25:52 by agautier          #+#    #+#             */
/*   Updated: 2021/12/11 15:51:49 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_BUFFER_H
# define HOTRACE_BUFFER_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

typedef struct s_buffer
{
	char	data[BUFFER_SIZE];
	int		head;
	int		eof;
}	t_buffer;

/*
**	Output buffer
*/
void	buffer_add(t_buffer *buf, char *str);
void	buffer_print(t_buffer *buf);

#endif
