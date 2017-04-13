/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 15:01:52 by rdavila           #+#    #+#             */
/*   Updated: 2017/04/12 14:00:13 by rdavila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

t_handler	get_handler_function(char c)
{
	t_handler ret;

	ret = NULL;
	(c == '%') ? (ret = &ft_printf_handle_percent) : 0;
	(c == 's') ? (ret = &ft_printf_handle_str) : 0;
	(c == 'S') ? (ret = &ft_printf_handle_wstr) : 0;
	(c == 'c') ? (ret = &ft_printf_handle_char) : 0;
	(c == 'C') ? (ret = &ft_printf_handle_wchar) : 0;
	(c == 'd') ? (ret = &ft_printf_handle_int) : 0;
	(c == 'i') ? (ret = &ft_printf_handle_int) : 0;
	(c == 'D') ? (ret = &ft_printf_handle_int) : 0;
	(c == 'x') ? (ret = &ft_printf_handle_hex) : 0;
	(c == 'X') ? (ret = &ft_printf_handle_hex) : 0;
	(c == 'o') ? (ret = &ft_printf_handle_octal) : 0;
	(c == 'O') ? (ret = &ft_printf_handle_octal) : 0;
	(c == 'u') ? (ret = &ft_printf_handle_unsigned) : 0;
	(c == 'U') ? (ret = &ft_printf_handle_unsigned) : 0;
	(c == 'p') ? (ret = &ft_printf_handle_ptr) : 0;
	(ret == NULL) ? (ret = &ft_printf_handle_null) : 0;
	return (ret);
}

int			handler(char **format, va_list args)
{
	t_handler	handle;
	t_flags		flags;
	int			printed;

	(*format)++;
	if (!**format)
		return (0);
	ft_bzero(&flags, sizeof(flags));
	if (!ft_parse_flags(format, &flags))
		return (-1);
	if (!ft_parse_width(format, args, &flags))
		return (-1);
	if (!ft_parse_precision(format, args, &flags))
		return (-1);
	if (!ft_parse_length(format, &flags))
		return (-1);
	if (!**format)
		return (0);
	handle = get_handler_function(**format);
	printed = handle(**format, args, flags);
	(*format)++;
	return (printed);
}

int			ft_inner_printf(const char *format, va_list args, size_t chars)
{
	char	*next;
	int		printed;

	next = ft_strchr(format, '%');
	if (!format)
		return (chars);
	if (!next)
	{
		ft_putstr(format);
		return (chars + ft_strlen(format));
	}
	else if (format < next)
	{
		ft_putnstr(format, next - format);
		chars += next - format;
		return (ft_inner_printf(next, args, chars));
	}
	else
	{
		if ((printed = handler((char **)&format, args)) == -1)
			return (-1);
		else
			return (ft_inner_printf(format, args, chars + printed));
	}
	return (1);
}

int			ft_printf(const char *format, ...)
{
	va_list	args;
	int		ret;

	va_start(args, format);
	ret = ft_inner_printf(format, args, 0);
	va_end(args);
	return (ret);
}
