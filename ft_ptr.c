/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-mjiy <wel-mjiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:51:05 by wel-mjiy          #+#    #+#             */
/*   Updated: 2024/11/29 02:52:02 by wel-mjiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexa_l(unsigned long x)
{
	int		count;
	char	*hex;

	count = 0;
	hex = "0123456789abcdef";
	if (x >= 16)
	{
		count += ft_hexa_l(x / 16);
	}
	count += ft_putchar(hex[x % 16]);
	return (count);
}

int	ft_ptr(void *p)
{
	unsigned long	num_adresse;
	unsigned int	count;

	count = 0;
	num_adresse = (unsigned long)(p);
	if (!p)
	{
		return (write(1, "(nil)", 5));
	}
	count += ft_putstr("0x");
	count += ft_hexa_l(num_adresse);
	return (count);
}
