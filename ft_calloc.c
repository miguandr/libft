/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguandr <miguandr@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 00:37:00 by miguandr          #+#    #+#             */
/*   Updated: 2023/12/05 21:10:05 by miguandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*calloc -- memory allocation*/
void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;
	size_t			i;
	size_t			len;

	ptr = malloc(size * count);
	if (ptr == NULL)
		return (NULL);
	len = size * count;
	i = 0;
	while (len > i)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}
