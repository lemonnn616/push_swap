/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iriadyns <iriadyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:30:22 by iriadyns          #+#    #+#             */
/*   Updated: 2024/11/10 16:20:12 by iriadyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	reset(t_fmt *fmt)
{
	fmt->hashtag = 0;
	fmt->space = 0;
	fmt->plus = 0;
}

void	ft_putunbr_base_fd(unsigned long long n, int base, int fd)
{
	const char	*digits = "0123456789abcdef";

	if (n / base)
		ft_putunbr_base_fd(n / base, base, fd);
	ft_putchar_fd(digits[n % base], fd);
}

void	ft_putfnbr_base_fd(long long n, int base, t_fmt *fmt, int fd)
{
	int			sign;
	const char	*digits = "0123456789abcdef";

	sign = 1;
	if (n < 0)
	{
		sign = -1;
		ft_putchar_fd('-', fd);
	}
	else if (n > 0 && fmt->hashtag && fmt->upper)
		ft_putstr_fd("0X", 1);
	else if (n > 0 && fmt->hashtag && !fmt->upper)
		ft_putstr_fd("0x", 1);
	else if (fmt->space)
		ft_putchar_fd(' ', fd);
	else if (fmt->plus)
		ft_putchar_fd('+', fd);
	if (fmt->upper)
		digits = "0123456789ABCDEF";
	while (fmt->pad-- > 0)
		ft_putchar_fd('0', fd);
	reset(fmt);
	if (n / base)
		ft_putfnbr_base_fd(n / base * sign, base, fmt, fd);
	ft_putchar_fd(digits[n % base * sign], fd);
}

int	ft_unumlen(unsigned long long n, int base)
{
	if (!(n / base))
		return (1);
	return (1 + ft_unumlen(n / base, base));
}

void	ft_putnstr_fd(char *s, int len, int fd)
{
	write(fd, s, len);
}
