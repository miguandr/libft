/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguandr <miguandr@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:45:16 by miguandr          #+#    #+#             */
/*   Updated: 2023/12/05 18:14:14 by miguandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*memset -- fill a byte string with a byte value*/
void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*result;

	result = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		result[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
