/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-mjiy <wel-mjiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 10:57:04 by wel-mjiy          #+#    #+#             */
/*   Updated: 2024/11/29 02:53:44 by wel-mjiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_formater(const char *format, va_list *args, int *count, int i)
{
	if (format[i] == 'c')
		*count += ft_putchar(va_arg(*args, int));
	else if (format[i] == 's')
		*count += ft_putstr(va_arg(*args, char *));
	else if (format[i] == 'd' || format[i] == 'i')
		*count += ft_putnbr(va_arg(*args, int));
	else if (format[i] == 'x')
		*count += ft_hexa(va_arg(*args, unsigned int), 0);
	else if (format[i] == 'X')
		*count += ft_hexa(va_arg(*args, unsigned int), 1);
	else if (format[i] == 'p')
		*count += ft_ptr(va_arg(*args, void *));
	else if (format[i] == 'u')
		*count += ft_putnbr_l(va_arg(*args, unsigned int));
	else if (format[i] == '%')
		*count += ft_putchar('%');
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	args;

	if (!format)
		return (-1);
	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			ft_formater(format, &args, &count, i);
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}

// int	main(void)
// {
// 	char *a = "walid";
// 	//    int s = -567890  ;
// 	//     printf("%d  %c hhhh %s %x %s %p %s %X %%\n " , 67890 , 'x', " jcka ",
// 		4567890 , " hhcudjj " , a , " fghj " , 456789);
// 	//     ft_printf("%%");
// 	//     //printf("%s hhhh %c %s %c %s %x %u %p %s %% %i %s %X  %s %u \n" ,
// 		"walid" , 'a' , "jj" , 'x' , "jj" , 3456789, 56789 , a , "fghj" ,
// 		45678 , "ert" , 7654321 , "cv" , 234567 );
// 	//     printf("\n %d \n",ft_printf("%s hhhh %c %s %c %s %x %u %p %s hhhh %%
// 			%i %s %X  %s %u \n" , "walid" , 'a' , "jj" , 'x' , "jj" , 3456789,
// 			56789 , a , "fghj" , 45678 , "ert" , 7654321 , "cv" , 234567));
// 	printf("%d", ft_printf("\n%s hhhh %c %s %c  %s %x %u %p %s hh % hh %% %i %s
// 			%X  %s %u \n", "walid", 'a', "jj", 'x', "jj", 3456789, 56789, a,
// 			"fghj", 45678, "ert", 7654321, "cv", 234567));
// 	printf("%d", printf("\n%s hhhh %c %s %c  %s %x %u %p %s hh % hh %% %i %s %X 
// 			%s %u \n", "walid", 'a', "jj", 'x', "jj", 3456789, 56789, a, "fghj",
// 			45678, "ert", 7654321, "cv", 234567));
// 	//     printf("\n%d", ft_printf("%d%d" , 545454 , 545454));
// 	//     printf("\n%d", ft_putnbr_l(4567890));
// 	//     printf("%d", );
// 	//     printf("%d",printf("%s hhhh %c %s %c %s %x %u %p %s %% %i %s %X  %s
// 			%u \n" , "walid" , 'a' , "jj" , 'x' , "jj" , 3456789, 56789 , a ,
// 			"fghj" , 45678 , "ert" , 7654321 , "cv" , 234567 ));
// 	//     printf("%s hhhh %c %s %c %s %x %u %p %s %% %i %s %X  %s %u" ,
// 		"walid" , 'a' , "jj" , 'x' , "jj" , 3456789, 56789 , a , "fghj" ,
// 		45678 , "ert" , 7654321 , "cv" , 234567 );
// 	//     ft_hexa(9874578);
//
// 	//     printf("%d\n",ft_printf(NULL, 43, 5656, "hello"));
// 	//     printf("%d",printf("", a));
// 	//     printf("%p\n", NULL);
// 	//     int a = 202020;
// 	//     int b = 202020;
// 	//     int x  = printf("%");
// 	//     void *a = "walid";
// 	//     unsigned long address_of_a = (unsigned long)a;
//
// 	//     Print the address of `a`
// 	//     printf("Address of 'a': %p\n", a);                // Using %p
// 	//     printf("Address of 'a' in hex: %ld\n", address_of_a);
// 		// Custom conversion
// 	// int len1, len2;
// 	//        len1 =  ft_printf(" %x %x %x %x %x %x %x\n", INT_MAX, INT_MIN,
// 			LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
// 	//        len2 =  printf(" %x %x %x %x %x %x %x\n", INT_MAX, INT_MIN,
// 			LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
// 	//        printf("len1 : %d\n", len1);
// 	//        printf("len2 : %d\n", len2);
// 	//}
//
// 	// int main(int ac, char ** av)
// 	// {
// 	// 	char *s2 = "Mussum Ipsum,
// 
// 			per gatis num morreus.";
//
// 	// 	printf("%d\n" , printf("% k\n", NULL));
// 	// 	printf("%d" , ft_printf("% k\n", NULL));
//
// 	// 	//ft_printf(" %k", NULL);
//
// 	return (0);
// }