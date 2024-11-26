/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-mjiy <wel-mjiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 11:04:07 by wel-mjiy          #+#    #+#             */
/*   Updated: 2024/11/26 18:25:21 by wel-mjiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FT_PRINTF_H
# define FT_PRINTF_H


#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdint.h>
#include <limits.h>


void	ft_putnbr_l(unsigned int n);
void	ft_putnbr(int n);
void    ft_hexa_l(unsigned long x);
void    ft_hexa_u(unsigned int x);
void	ft_putstr(char *s);
void	ft_putchar(char c);

#endif
