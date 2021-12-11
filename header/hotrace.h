/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 11:52:46 by agautier          #+#    #+#             */
/*   Updated: 2021/12/11 16:58:38 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

# include "hotrace_buffer.h"

typedef struct s_node t_node;

struct s_node
{
	char	*key;
	char	*value;
	t_node	*next;
};

char	*ft_strncpy(char *dest, char *src, int len);

#endif
