/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavila <rdavila@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 15:22:34 by rdavila           #+#    #+#             */
/*   Updated: 2017/04/10 11:56:02 by rdavila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

int		ft_printf_handle_unsigned(char c, va_list args, t_flags flags)
{
	uintmax_t	num;

	if (c == 'U')
		flags.length = l;
	num = parse_unsigned(args, flags);
	return (ft_printf_handle_uint(num, flags, "0123456789", NULL));
}
