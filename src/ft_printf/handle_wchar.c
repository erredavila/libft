/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 18:19:28 by rdavila           #+#    #+#             */
/*   Updated: 2017/04/06 15:52:30 by rdavila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

int		ft_printf_handle_wchar(char c, va_list args, t_flags flags)
{
	wchar_t	ch;
	int		chr_len;

	(void)c;
	ch = va_arg(args, int);
	if (ch <= 0x7F)
		chr_len = 1;
	else if (ch <= 0x7FF)
		chr_len = 2;
	else if (ch <= 0xFFFF)
		chr_len = 3;
	else if (ch <= 0x10FFFF)
		chr_len = 4;
	else
		chr_len = 0;
	if (flags.got_width && !flags.left_align)
		add_padding(1, flags.width, ' ');
	ft_putwchar(ch);
	if (flags.got_width && flags.left_align)
		add_padding(1, flags.width, ' ');
	if (flags.got_width)
		return (ft_max(chr_len, flags.width));
	return (chr_len);
}
