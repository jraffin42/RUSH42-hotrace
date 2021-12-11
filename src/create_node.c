/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 16:44:37 by agautier          #+#    #+#             */
/*   Updated: 2021/12/11 16:57:47 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "hotrace.h"

t_node	*create_node(char *str, int key_len, int value_len)
{
	t_node	*node;

	node = malloc(sizeof(t_node) + key_len + value_len + 2);
	if (node == NULL)
		return (NULL);	// TODO: malloc error
	node->key = ((char *)node) + sizeof(t_node);
	node->value = node->key + key_len + 1;
	node->key = ft_strncpy(node->key, str, key_len);
	node->value = ft_strncpy(node->value, str + key_len + 1, value_len);
	node->next = NULL;
	return (node);
}
