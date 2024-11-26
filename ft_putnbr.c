/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-mjiy <wel-mjiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:51:08 by wel-mjiy          #+#    #+#             */
/*   Updated: 2024/11/26 18:27:13 by wel-mjiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void	ft_putnbr_l(unsigned int n)
{
	if (n >= 0 && n <= 9)
	{
		ft_putchar(n + 48);
	}
	else if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putchar((n % 10) + 48);
	}
}

void	ft_putnbr(int n)
{
    if (n == -2147483648)
    {
        write(1,"-2147483648",11);
    }
	else if (n >= 0 && n <= 9)
	{
		ft_putchar(n + 48);
	}
	else if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putchar((n % 10) + 48);
	}
	else
	{
		ft_putchar('-');
		ft_putnbr(-n);
	}
}