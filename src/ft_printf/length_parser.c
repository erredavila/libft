/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavila <rdavila@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 21:14:03 by rdavila           #+#    #+#             */
/*   Updated: 2017/04/10 11:54:04 by rdavila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

uintmax_t	parse_unsigned(va_list args, t_flags flags)
{
	uintmax_t	nbr;

	nbr = va_arg(args, uintmax_t);
	if (flags.length == hh)
		nbr = (unsigned char)nbr;
	else if (flags.length == h)
		nbr = (unsigned short)nbr;
	else if (flags.length == l)
		nbr = (unsigned long)nbr;
	else if (flags.length == ll)
		nbr = (unsigned long long)nbr;
	else if (flags.length == j)
		nbr = (uintmax_t)nbr;
	else if (flags.length == z)
		nbr = (size_t)nbr;
	else
		nbr = (unsigned int)nbr;
	return (nbr);
}

intmax_t	parse_signed(va_list args, t_flags flags)
{
	intmax_t	nbr;

	nbr = va_arg(args, intmax_t);
	if (flags.length == hh)
		nbr = (signed char)nbr;
	else if (flags.length == h)
		nbr = (short)nbr;
	else if (flags.length == l)
		nbr = (long)nbr;
	else if (flags.length == ll)
		nbr = (long long)nbr;
	else if (flags.length == j)
		nbr = (intmax_t)nbr;
	else if (flags.length == z)
		nbr = (size_t)nbr;
	else
		nbr = (int)nbr;
	return (nbr);
}
