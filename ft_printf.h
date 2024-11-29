/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-mjiy <wel-mjiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 11:04:07 by wel-mjiy          #+#    #+#             */
/*   Updated: 2024/11/29 01:25:05 by wel-mjiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <unistd.h>

int	ft_putnbr_l(unsigned int n);
int	ft_putnbr(int n);
int	ft_hexa(unsigned int x, int isuper);
int	ft_putstr(char *s);
int	ft_putchar(char c);
int	ft_ptr(void *p);
int	ft_printf(const char *format, ...);

#endif
