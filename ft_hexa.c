/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-mjiy <wel-mjiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:52:49 by wel-mjiy          #+#    #+#             */
/*   Updated: 2024/11/29 02:52:26 by wel-mjiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexa(unsigned int x, int isuper)
{
	int		count;
	char	*hex;

	count = 0;
	if (isuper)
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	if (x >= 16)
	{
		count += ft_hexa(x / 16, isuper);
	}
	count += ft_putchar(hex[x % 16]);
	return (count);
}
