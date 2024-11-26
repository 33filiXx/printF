/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-mjiy <wel-mjiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:52:49 by wel-mjiy          #+#    #+#             */
/*   Updated: 2024/11/26 18:28:09 by wel-mjiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"


void ft_hexa_l(unsigned long x)
{
    if (x >= 16)
    {
        ft_hexa_l(x / 16);  
    }

    int digit = x % 16;  

    if (digit <= 9)
    {
        ft_putchar(digit + 48);  
    }
    else
    {
             ft_putchar('a' + (digit - 10));  
     }
 }
 
 void ft_hexa_u(unsigned int x)
{
    if (x >= 16)
    {
        ft_hexa_u(x / 16);  
    }

    int digit = x % 16;  

    if (digit <= 9)
    {
        ft_putchar(digit + 48);  
    }
    else
    {
             ft_putchar('A' + (digit - 10));  
    }
}