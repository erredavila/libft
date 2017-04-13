/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 12:34:01 by rdavila           #+#    #+#             */
/*   Updated: 2017/04/03 21:30:02 by rdavila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdio.h>

static int	handle_big_base(const char *str, int base, char *buff)
{
	int ret;

	ret = 0;
	while ((*str >= '0' && *str <= '9') ||
			(ft_toupper(*str) >= 'A' && ft_toupper(*str) <= buff[base - 1]))
	{
		if (ft_toupper(*str) >= 'A' && ft_toupper(*str) <= 'F')
		{
			ret *= base;
			ret += 10 + ft_toupper(*str) - 'A';
		}
		else
		{
			ret *= base;
			ret += *str - '0';
		}
		str++;
	}
	return (ret);
}

int			ft_atoi_base(const char *str, int base)
{
	int		sign;
	int		ret;

	sign = 1;
	ret = 0;
	while (*str == '\n' || *str == ' ' || *str == '\t')
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	if (base > 10)
		ret = handle_big_base(str, base, "0123456789ABCDEF");
	else
	{
		while (*str >= '0' && *str <= ((base - 1) + '0'))
		{
			ret *= base;
			ret += *str - '0';
			str++;
		}
	}
	return (ret * sign);
}
