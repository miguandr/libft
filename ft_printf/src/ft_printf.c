/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguandr <miguandr@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 10:28:05 by miguandr          #+#    #+#             */
/*   Updated: 2026/05/20 18:43:09 by miguandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_specifiers(va_list *args, const char format)
{
	if (format == 'c')
		return (ft_putchar(va_arg(*args, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(*args, char *)));
	else if (format == 'p')
		return (ft_putptr(va_arg(*args, unsigned long long)));
	else if (format == 'd' || format == 'i')
		return (ft_putnumb(va_arg(*args, int)));
	else if (format == 'u')
		return (ft_putunsigned(va_arg(*args, unsigned int)));
	else if (format == 'x' || format == 'X')
		return (ft_puthexa(va_arg(*args, unsigned int), format));
	else if (format == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		length;

	if (!format)
		return (-1);
	i = 0;
	length = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			length += ft_specifiers(&args, format[i + 1]);
			i++;
		}
		else
			length += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (length);
}
