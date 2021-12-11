/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 16:44:37 by agautier          #+#    #+#             */
/*   Updated: 2021/12/11 16:45:21 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

typedef struct s_node t_node;

struct s_node
{
	char	*key;
	char	*value;
	t_node	*next;
};

/*
**	Copy at most len char of src in dest.
*/
char	*ft_strncpy(char *dest, char *src, int len)
{
	int i;

	i = 0;
	while (src[i] != '\0' && i < len)
	{
		dest[i] = src[i];
		i += 1;
	}
	dest[i] = '\0';
	return (dest);
}

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
