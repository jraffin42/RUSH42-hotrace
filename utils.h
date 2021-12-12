/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraffin <jraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 17:00:42 by jraffin           #+#    #+#             */
/*   Updated: 2021/12/12 23:44:28 by jraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strncpy(char *dest, char *src, int len);
void	*ft_memmove(void *dest, const void *src, int n);
void	*ft_memchr(const void *s, int c, int n);

#endif
