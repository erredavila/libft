/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavila <rdavila@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 10:34:53 by rdavila           #+#    #+#             */
/*   Updated: 2017/04/06 21:13:00 by rdavila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

static void	ft_putnwstr(wchar_t *s, int len)
{
	int i;

	i = 0;
	while (*s && i < len)
	{
		if (*s <= 0x7F)
			i++;
		else if (*s <= 0x7FF)
			i += 2;
		else if (*s <= 0xFFFF)
			i += 3;
		else if (*s <= 0x10FFFF)
			i += 4;
		if (i <= len)
			ft_putwchar(*s);
		s++;
	}
}

static int	ft_wstrnlen(wchar_t *s, int precision, int i)
{
	int	bytes;

	if (!*s || precision <= 0)
		return (i);
	bytes = 0;
	if (*s <= 0x7F)
		bytes = 1;
	else if (*s <= 0x7FF && precision >= 2)
		bytes = 2;
	else if (*s <= 0xFFFF && precision >= 3)
		bytes = 3;
	else if (*s <= 0x10FFFF && precision >= 4)
		bytes = 4;
	s++;
	precision -= bytes;
	i += bytes;
	return (ft_wstrnlen(s, precision, i));
}

static int	ft_wstrlen(wchar_t *s)
{
	int		i;

	i = 0;
	while (*s)
	{
		if (*s <= 0x7F)
			i++;
		else if (*s <= 0x7FF)
			i += 2;
		else if (*s <= 0xFFFF)
			i += 3;
		else if (*s <= 0x10FFFF)
			i += 4;
		s++;
	}
	return (i);
}

int			ft_printf_handle_wstr(char c, va_list args, t_flags flags)
{
	wchar_t	*s;
	int		len;

	(void)c;
	(void)flags;
	s = va_arg(args, wchar_t *);
	if (!s)
		s = L"(null)";
	len = ft_wstrlen(s);
	if (flags.got_precision)
		len = ft_wstrnlen(s, flags.precision, 0);
	if (flags.got_width && !flags.left_align)
		add_padding(len, flags.width, flags.pad_zero ? '0' : ' ');
	ft_putnwstr(s, len);
	if (flags.got_width && flags.left_align)
		add_padding(len, flags.width, flags.pad_zero ? '0' : ' ');
	if (flags.got_width)
		return (ft_max(flags.width, len));
	return (len);
}
