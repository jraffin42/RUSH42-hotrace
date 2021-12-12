/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderome <mderome@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 11:52:46 by agautier          #+#    #+#             */
/*   Updated: 2021/12/12 10:16:06 by mderome          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

# include "hashtable.h"
# include "buffer.h"
# include <stdio.h>

t_node	*get_next_node(t_buffer *buf);
char	*get_next_keyword(t_buffer *buf, int *key_len);
#endif
