/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 18:19:28 by rdavila           #+#    #+#             */
/*   Updated: 2017/04/06 19:59:56 by rdavila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

int		ft_printf_handle_char(char c, va_list args, t_flags flags)
{
	char	ch;

	if (flags.length == l)
		return (ft_printf_handle_wchar(c, args, flags));
	else
	{
		ch = va_arg(args, int);
		if (flags.got_width && !flags.left_align)
			add_padding(1, flags.width, flags.pad_zero ? '0' : ' ');
		ft_putchar(ch);
		if (flags.got_width && flags.left_align)
			add_padding(1, flags.width, flags.pad_zero ? '0' : ' ');
		if (flags.got_width)
			return (ft_max(1, flags.width));
		return (1);
	}
}
