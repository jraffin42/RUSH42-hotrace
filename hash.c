/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraffin <jraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 20:00:35 by jraffin           #+#    #+#             */
/*   Updated: 2021/12/11 21:56:38 by jraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"

unsigned int	hash(const char *keyword)
{
	unsigned int	hash;

	hash = 4603;
	while (*keyword)
		hash = hash * 101 + *keyword++;
	return (hash % HASH_MODULUS);
}
