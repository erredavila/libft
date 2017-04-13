/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrbase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 11:52:14 by rdavila           #+#    #+#             */
/*   Updated: 2017/03/23 19:43:37 by rdavila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void		ft_putnbrbase(size_t nbr, char *base)
{
	size_t base_len;

	base_len = ft_strlen(base);
	if (nbr >= base_len)
	{
		ft_putnbrbase(nbr / base_len, base);
		ft_putnbrbase(nbr % base_len, base);
	}
	else
		ft_putchar(base[nbr]);
}
