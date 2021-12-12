/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   utils.c											:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: jraffin <jraffin@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2021/12/11 17:02:00 by jraffin		   #+#	#+#			 */
/*   Updated: 2021/12/11 21:46:45 by jraffin		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

char	*ft_strncpy(char *dest, char *src, int len)
{
	int	i;

	i = 0;
	while (src[i] != '\0' && i < len)
	{
		dest[i] = src[i];
		i += 1;
	}
	dest[i] = '\0';
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, int n)
{
	int	i;

	if (src == dest)
		return (dest);
	i = 0;
	if (src < dest)
	{
		while (n)
		{
			n--;
			((char *)dest)[n] = ((char *)src)[n];
		}
	}
	else
	{
		while (i < n)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i++;
		}
	}
	return (dest);
}

void	*ft_memchr(const void *s, int c, int n)
{
	while (n > 0 && *(unsigned char *)s != (unsigned char)c)
	{
		s++;
		n--;
	}
	if (n > 0)
		return ((void *)s);
	return (0);
}
