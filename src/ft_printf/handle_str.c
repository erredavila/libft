/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 10:37:54 by rdavila           #+#    #+#             */
/*   Updated: 2017/04/11 20:06:41 by rdavila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

int		ft_printf_handle_str(char c, va_list args, t_flags flags)
{
	int		len;
	char	*s;

	if (flags.length == l)
		return (ft_printf_handle_wstr(c, args, flags));
	else
	{
		s = va_arg(args, char *);
		if (!s)
			s = "(null)";
		len = ft_strlen(s);
		if (flags.got_precision)
			len = ft_strnlen(s, flags.precision);
		if (flags.got_width && !flags.left_align)
			add_padding(len, flags.width, flags.pad_zero ? '0' : ' ');
		ft_putnstr(s, len);
		if (flags.got_width && flags.left_align)
			add_padding(len, flags.width, ' ');
		if (flags.got_width)
			return (ft_max(len, flags.width));
		return (len);
	}
}
