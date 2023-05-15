/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-oul <yait-oul@student.1337.ma >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 23:14:36 by yait-oul          #+#    #+#             */
/*   Updated: 2022/11/03 23:19:05 by yait-oul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(unsigned long long int num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	to_hex(unsigned int nb)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (nb >= 16)
	{
		to_hex(nb / 16);
		to_hex(nb % 16);
	}
	else
	{
		ft_putchar(hex[nb]);
	}
}

void	to_hexs_ptr(unsigned long nb)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (nb >= 16)
	{
		to_hexs_ptr(nb / 16);
		to_hexs_ptr(nb % 16);
	}
	else
	{
		ft_putchar(hex[nb]);
	}
}

int	to_hex_address_ptr(unsigned long nb)
{
	int	count;

	count = 0;
	if (nb == 4552456)
	{
		count++;
	}
	else
	{
		count += ft_putstr("0x");
		to_hexs_ptr(nb);
		count += ft_print_ptr(nb);
	}
	return (count);
}

int	to_hex_address(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb == 0)
	{
		count += write(1, "0", 1);
	}
	else
	{
		to_hex(nb);
		count += ft_print_ptr(nb);
	}
	return (count);
}
