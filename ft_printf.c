/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-mjiy <wel-mjiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 10:57:04 by wel-mjiy          #+#    #+#             */
/*   Updated: 2024/11/24 20:04:57 by wel-mjiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


// void caracter(const char *format)
// {
    
// }

// int counter(const char *format)
// {
//     int i;
//     int count;

//     i = 0;
//     count = 0;
//     while (format[i])
//     {
//         if (format[i] == '%')
//             count += 1;
//         i++;
//     }
//     return count;
// }
void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}
void	ft_putchar(char c)
{
	write(1, &c, 1);
}
void	ft_putnbr(int n)
{
	if (n == -2147483648)
		write(1, "-2147483648", 11);
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

void ft_hexa(unsigned int x , char formater)
{
    if (x >= 0 && x <= 15) 
    {
        if (x >= 0 && x <= 9)
            ft_putchar(x + 48);
        else
        {
            if ( formater == 'X')
                ft_putchar('A' + (x - 10));
            else if (formater == 'x')
                ft_putchar('a' + (x - 10));
        }
    }
    else if(x >= 16)
    {
        ft_hexa(x / 16 ,formater);
        ft_hexa(x % 16 ,formater);
    }
}











// void ft_hexa(unsigned int x, char formater)
// {
//     if (x >= 16)
//     {
//         ft_hexa(x / 16, formater);  // Recurse for higher order digits
//     }

//     int digit = x % 16;  // Get the current digit (least significant)

//     if (digit <= 9)
//     {
//         ft_putchar(digit + 48);  // Print digits '0' to '9'
//     }
//     else
//     {
//         if (formater == 'X')
//             ft_putchar('A' + (digit - 10));  // Print 'A' to 'F' for uppercase
//         else if (formater == 'x')
//             ft_putchar('a' + (digit - 10));  // Print 'a' to 'f' for lowercase
//     }
// }











int ft_printf(const char *format, ...)
{
    int i;
    char *x;
    int d;
    unsigned int f;
    int count;
    va_list args;

    i = 0;
    va_start(args , format);
    while (format[i])
    {
    if (format[i] == '%')
    {
    if (format[i + 1] == 'c')
        x = va_arg(args , char*);
        write(1,&x,1);
    if (format[i + 1] == 's')
    {
        x = va_arg(args , char*);
        ft_putstr(x);
    }
    if(format[i + 1] == 'd' || format[i + 1] == 'i')
    {
        d = va_arg(args , int);
        ft_putnbr(d); 
    }
    if ( format[i + 1] == 'x')
    {
        f = va_arg(args , int);
        ft_hexa(f , 'X'); 
    }
    if ( format[i + 1] == 'x')
    {
        f = va_arg(args , int);
        ft_hexa(f , 'x'); 
    }
    }
    i++;
    }
    return count;
}

int main()
{
    ft_printf(" %d %s %c %x %s %x %c %c" , 125353 ," aaa " , 'a' , 543 , "gefew " ,  54321 , 'x' , 'e');
    //ft_hexa(9874578);
    //int a = 202020;
    //int b = 202020;
    //int x  = printf("%");
    //printf("%d" , x);
    
    
 
}
