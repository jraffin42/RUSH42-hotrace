/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraffin <jraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 11:52:46 by agautier          #+#    #+#             */
/*   Updated: 2021/12/12 21:36:01 by jraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

# include "hashtable.h"
# include "buffer.h"

t_node	*get_next_node(t_readbuf *buf);
char	*get_next_keyword(t_readbuf *buf, int *key_len);
#endif
