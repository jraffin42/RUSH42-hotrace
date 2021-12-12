/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 16:13:43 by jraffin           #+#    #+#             */
/*   Updated: 2021/12/12 15:40:10 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include "hashtable.h"
#include "utils.h"
#include <stdio.h>

t_node	*create_node(char *str, int key_len, int val_len)
{
	t_node	*node;

	node = malloc(sizeof(t_node) + (key_len + 1) + (val_len + 2) + 1);
	if (!node)
	{
		if (write(2, strerror(errno), ft_strlen(strerror(errno))))
			NULL;
		return (NULL);
	}
	node->key_len = key_len;
	node->val_len = val_len;
	node->keyword = ((char *)node) + sizeof(t_node);
	node->value = node->keyword + key_len + 1;
	node->keyword = ft_strncpy(node->keyword, str, key_len);
	node->value = ft_strncpy(node->value, str + key_len + 1, val_len + 2);
	node->next = NULL;
	return (node);
}

t_node	**init_hashtable(void)
{
	t_node	**table;
	int		i;

	table = malloc(sizeof(t_node *) * HASH_MODULUS);
	if (!table)
	{
		if (write(2, strerror(errno), ft_strlen(strerror(errno))))
			NULL;
		return (NULL);
	}
	i = 0;
	while (i < HASH_MODULUS)
		table[i++] = NULL;
	return (table);
}

void	free_hashtable(t_node **hashtable)
{
	t_node	*node;
	t_node	*tmp;
	int		i;

	i = 0;
	while (i < HASH_MODULUS)
	{
		node = hashtable[i];
		while (node)
		{
			tmp = node;
			node = node->next;
			free(tmp);
		}
		i++;
	}
	free(hashtable);
}

char	*seek_value(t_node **hashtable, char *keyword, int *val_len)
{
	t_node	*node;

	node = hashtable[hash(keyword)];
	while (node && ft_strcmp(node->keyword, keyword))
		node = node->next;
	if (node)
	{
		*val_len = node->val_len;
		return (node->value);
	}
	return (NULL);
}

void	add_node(t_node **hashtable, t_node *node)
{
	t_node	**slot;

	slot = hashtable + hash(node->keyword);
	while (*slot && ft_strcmp((*slot)->keyword, node->keyword))
		slot = &(*slot)->next;
	if (*slot)
	{
		node->next = (*slot)->next;
		free(*slot);
	}
	*slot = node;
}
