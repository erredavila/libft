/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 22:07:19 by rdavila           #+#    #+#             */
/*   Updated: 2017/04/10 11:54:54 by rdavila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

int			ft_printf_handle_hex(char c, va_list args, t_flags flags)
{
	uintmax_t num;

	num = parse_unsigned(args, flags);
	if (c == 'x')
		return (ft_printf_handle_uint(num, flags, "0123456789abcdef", "0x"));
	else
		return (ft_printf_handle_uint(num, flags, "0123456789ABCDEF", "0X"));
}
