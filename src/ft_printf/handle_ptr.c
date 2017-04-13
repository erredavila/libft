/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavila <rdavila@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 16:04:09 by rdavila           #+#    #+#             */
/*   Updated: 2017/04/05 16:25:23 by rdavila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

int		ft_printf_handle_ptr(char c, va_list args, t_flags flags)
{
	uintmax_t num;

	(void)c;
	num = va_arg(args, uintmax_t);
	return (force_prefix(num, "0123456789abcdef", flags, "0x"));
}
