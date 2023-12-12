/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguandr <miguandr@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 22:57:56 by miguandr          #+#    #+#             */
/*   Updated: 2023/12/04 23:05:14 by miguandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*ft_lstiter -- apply a function to each element's content*/
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*temp;

	temp = lst;
	while (temp)
	{
		f(temp->content);
		temp = temp->next;
	}
}
