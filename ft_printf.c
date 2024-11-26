/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-mjiy <wel-mjiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 10:57:04 by wel-mjiy          #+#    #+#             */
/*   Updated: 2024/11/26 18:29:21 by wel-mjiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"



int ft_printf(const char *format, ...)
{
    int i;
    void *p;
    unsigned long num_adresse;
    int count;
    va_list args;

    i = 0;
    va_start(args , format);
    while (format[i] != '\0')
    {
    if (format[i] == '%')
    {
        i++;
        if (format[i] == 'c')
            ft_putchar(va_arg(args , int));
        else if (format[i] == 's')
            ft_putstr(va_arg(args , char*));
        else if(format[i] == 'd' || format[i] == 'i')
            ft_putnbr(va_arg(args , int)); 
        else if ( format[i] == 'x')
            ft_hexa_l(va_arg(args , int));
        else if ( format[i] == 'X')
            ft_hexa_u(va_arg(args , int));
        else if (format[i] == 'p')
        {
            p = va_arg(args , void*);
            if (!p)
            {
              return(write(1, "(nil)", 5));       
            }
            num_adresse = (unsigned long)(p);
            ft_putstr("0x");
            ft_hexa_l(num_adresse);
        }
        else if ( format[i] == 'u')
            ft_putnbr_l(va_arg(args , unsigned int));
        else if ( format[i] == '%')
            ft_putchar('%');
        }
        else
            ft_putchar(format[i]);
        i++ ;
    }
    return count;
}

int main()
{
    char *a = "alid" ;
    int s = -567890  ;
    //printf("%d  %c hhhh %s %x %s %p %s %X %%\n " , 67890 , 'x', " jcka ", 4567890 , " hhcudjj " , a , " fghj " , 456789);
    //ft_printf("%%");
    //printf("%s hhhh %c %s %c %s %x %u %p %s %% %i %s %X  %s %u \n" , "walid" , 'a' , "jj" , 'x' , "jj" , 3456789, 56789 , a , "fghj" , 45678 , "ert" , 7654321 , "cv" , 234567 );
    ft_printf("%s hhhh %c %s %c %s %x %u %p %s %% %i %s %X  %s %u" , "walid" , 'a' , "jj" , 'x' , "jj" , 3456789, 56789 , a , "fghj" , 45678 , "ert" , 7654321 , "cv" , 234567 );
    //ft_hexa(9874578);
     
    //ft_printf("%p\n", NULL);
    //printf("%p\n", NULL);
    //int a = 202020;
    //int b = 202020;
    //int x  = printf("%");
    // void *a = "walid";
    // unsigned long address_of_a = (unsigned long)a;

    // // Print the address of `a`
    // printf("Address of 'a': %p\n", a);                // Using %p
    // printf("Address of 'a' in hex: %ld\n", address_of_a); // Custom conversion
    
}
 