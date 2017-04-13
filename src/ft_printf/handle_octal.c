/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_octal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 15:38:58 by rdavila           #+#    #+#             */
/*   Updated: 2017/04/10 11:55:32 by rdavila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

int		ft_printf_handle_octal(char c, va_list args, t_flags flags)
{
	uintmax_t	num;
	int			len;

	if (c == 'O')
		flags.length = l;
	num = parse_unsigned(args, flags);
	len = ft_num_length_base(num, "01234567");
	if (flags.precision > len)
		flags.prefix = 0;
	return (ft_printf_handle_uint(num, flags, "01234567", "0"));
}
