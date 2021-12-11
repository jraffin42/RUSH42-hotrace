/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraffin <jraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 16:13:43 by jraffin           #+#    #+#             */
/*   Updated: 2021/12/11 18:12:56 by jraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "hashtable.h"
#include "utils.h"

static unsigned int	hash(const char *keyword)
{
	unsigned int	hash;

	hash = 4603;
	while (*keyword)
		hash = hash * 101 + *keyword++;

	return (hash % HASH_MODULUS);
}

t_node	**init_hashtable()
{
	t_node	**table;
	int		i;

	table = malloc(sizeof(t_node *) * HASH_MODULUS);
	if (!table)
		return (NULL);
	i = 0;
	while (i < HASH_MODULUS)
		table[i++] = NULL;
	return (table);
}

char *seek_value(t_node **hashtable, char *keyword)
{
	t_node *node;

	node = hashtable[hash(keyword)];
	while (node && ft_strcmp(node->keyword, keyword))
		node = node->next;
	if (node)
		return (node->value);
	return (NULL);
}

void	add_node(t_node **hashtable, t_node* node)
{
	t_node	**slot;
	t_node	*parent_node;
	int		key_hash;

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
