/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraffin <jraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 17:13:45 by jraffin           #+#    #+#             */
/*   Updated: 2021/12/11 22:33:16 by jraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHTABLE_H
# define HASHTABLE_H

# define HASH_MODULUS 16784171

typedef struct s_node
{
	char			*keyword;
	char			*value;
	int				key_len;
	int				val_len;
	struct s_node	*next;
}	t_node;

unsigned int	hash(const char *keyword);
t_node			*create_node(char *str, int key_len, int val_len);
t_node			**init_hashtable(void);
void			free_hashtable(t_node **hashtable);
char			*seek_value(t_node **hashtable, char *keyword, int *val_len);
void			add_node(t_node **hashtable, t_node *node);

#endif
