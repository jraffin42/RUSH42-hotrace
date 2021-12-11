/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraffin <jraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 17:13:45 by jraffin           #+#    #+#             */
/*   Updated: 2021/12/11 18:00:40 by jraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHTABLE_H
# define HASHTABLE_H

# define HASH_MODULUS 16784171

typedef struct	s_node
{
	char			*keyword;
	char			*value;
	struct s_node	*next;
}	t_node;

t_node	**init_hashtable();
char 	*seek_value(t_node **hashtable, char *keyword);
void	add_node(t_node **hashtable, t_node* node);

#endif
