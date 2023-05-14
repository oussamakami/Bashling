/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-oul <yait-oul@student.1337.ma >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 00:49:33 by yait-oul          #+#    #+#             */
/*   Updated: 2022/11/24 01:27:11 by yait-oul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...);

int	to_hex_add(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb == 0)
	{
		count += write(1, "0", 1);
	}
	else
	{
		to_hex_maj(nb);
		count += ft_print_ptr(nb);
	}
	return (count);
}

void	to_hex_maj(unsigned int nb)
{
	char	*hex;

	hex = "0123456789ABCDEF";
	if (nb >= 16)
	{
		to_hex_maj(nb / 16);
		to_hex_maj(nb % 16);
	}
	else
	{
		ft_putchar(hex[nb]);
	}
}

int	check_cases(va_list ap, const char format)
{
	int	count;

	count = 0;
	if (format == 'd' || format == 'i')
		count += afficher_num(va_arg(ap, int));
	else if (format == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (format == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (format == 'x')
		count += to_hex_address(va_arg(ap, unsigned long));
	else if (format == 'u')
		count += afficher_num(va_arg(ap, unsigned int));
	else if (format == 'X')
		count += to_hex_add(va_arg(ap, unsigned int));
	else if (format == 'p')
		count += to_hex_address_ptr(va_arg(ap, unsigned long));
	else if (format == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	int		i;
	va_list	ap;

	va_start(ap, format);
	count = 0;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			count += check_cases(ap, format[i]);
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (count);
}

// int	main(void)
// {
// 	int	n3;
// 	int	n4;
// 	int	i1;
// 	int	i2;

// 	//	int n1 =	ft_printf("%pdis%%cip%xline%d%dsimplicity%c%cGod%s%s",&a,
// 	//				4586, 5,5,'a', 'a',"purity", "purity");
// 	//	int n2 = 	printf("%pdis%%cip%xline%d%dsimplicity%c%cGod%s%s",&a,
// 	//				4586,5, 5, 'a','a', "purity", "purity");
// 	//	printf("n1 = %d and n2 = %d", n1 , n2);
// 	/*

// 	n3 = ft_printf("%s", format);
// 	n4 = printf("\n%s", format);
// 		printf("n3 = %d and n4 = %d", n3 , n4);
// */
// 	i1 = ft_printf(" %p %p ", 0, 0);
// 	printf("\n");
// 	i2 = printf(" %p %p ", 0, 0);
// 	printf("\ni1 =%d and i2 =%d", i1, i2);
// 	return (0);
// }
