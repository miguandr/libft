/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguandr <miguandr@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:45:29 by miguandr          #+#    #+#             */
/*   Updated: 2026/05/20 18:53:55 by miguandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*strlcat -- size-bounded string concatenation*/
size_t	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	slen;
	unsigned int	dlen;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	dlen = i;
	slen = ft_strlen(src);
	if (size == 0 || size <= dlen)
		return (slen + size);

	while (src[j] != '\0' && j < size - dlen - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dlen + slen);
}
