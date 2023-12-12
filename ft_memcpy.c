/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguandr <miguandr@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:45:10 by miguandr          #+#    #+#             */
/*   Updated: 2023/12/05 18:15:07 by miguandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* memcpy -- copy memory area*/
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*olddest;
	unsigned char	*oldsrc;
	size_t			i;

	olddest = (unsigned char *)dest;
	oldsrc = (unsigned char *)src;
	if (!dest && !src)
		return (dest);
	i = 0;
	while (i < n)
	{
		olddest[i] = oldsrc[i];
		i++;
	}
	return (dest);
}
