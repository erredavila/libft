/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 18:16:49 by rdavila           #+#    #+#             */
/*   Updated: 2017/04/12 14:03:04 by rdavila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	get_len(int value, int base)
{
	int	len;

	len = 0;
	if (!value)
		return (1);
	if (value < 0 && base == 10)
		len++;
	while (value)
	{
		value /= base;
		len++;
	}
	return (len);
}

static int	check_negative(long value, int base, int *neg)
{
	if (value < 0)
	{
		if (base == 10)
			*neg = 1;
		return (1);
	}
	return (0);
}

char		*ft_itoa_base(int value, int base)
{
	char	*ret;
	int		neg;
	int		len;
	long	value_cpy;
	char	*buff;

	neg = 0;
	buff = (char *)malloc(sizeof(*buff) * 17);
	ft_strcpy(buff, "0123456789ABCDEF");
	len = get_len(value, base);
	ret = (char *)malloc(sizeof(*ret) * (len + 1));
	ret[len] = '\0';
	value_cpy = value;
	if (check_negative(value, base, &neg))
		value_cpy *= -1;
	while (--len)
	{
		ret[len] = buff[value_cpy % base];
		value_cpy /= base;
	}
	ret[len] = '-';
	if (!neg)
		ret[len] = buff[value_cpy % base];
	free(buff);
	return (ret);
}
