/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 11:31:05 by rdavila           #+#    #+#             */
/*   Updated: 2017/04/12 13:48:40 by rdavila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdint.h>

typedef	struct	s_flags
{
	int			left_align;
	int			force_sign;
	int			blank;
	int			pad_zero;
	int			prefix;
	int			got_width;
	int			got_precision;
	int			width;
	int			precision;
	enum {
		empty,
		hh,
		h,
		l,
		ll,
		j,
		z
	}			length;
}				t_flags;

int				ft_printf_handle_percent(char c, va_list args, t_flags flags);
int				ft_printf_handle_str(char c, va_list args, t_flags flags);
int				ft_printf_handle_wstr(char c, va_list args, t_flags flags);
int				ft_printf_handle_char(char c, va_list args, t_flags flags);
int				ft_printf_handle_wchar(char c, va_list args, t_flags flags);
int				ft_printf_handle_int(char c, va_list args, t_flags flags);
int				ft_printf_handle_hex(char c, va_list args, t_flags flags);
int				ft_printf_handle_octal(char c, va_list args, t_flags flags);
int				ft_printf_handle_unsigned(char c, va_list args, t_flags flags);
int				ft_printf_handle_ptr(char c, va_list args, t_flags flags);
int				ft_printf_handle_null(char c, va_list args, t_flags flags);

int				ft_printf_handle_uint(size_t num, t_flags flags, char *base,
				char *prefix);

void			add_padding(int min, int max, char c);
int				force_prefix(size_t num, char *base, t_flags flags,
				char *prefix);

uintmax_t		parse_unsigned(va_list args, t_flags flags);
intmax_t		parse_signed(va_list args, t_flags flags);

char			*ft_parse_length(char **format, t_flags *flags);
char			*ft_parse_flags(char **format, t_flags *flags);
char			*ft_parse_width(char **format, va_list args, t_flags *flags);
char			*ft_parse_precision(char **format, va_list args,
				t_flags *flags);

typedef	int		(*t_handler)(char, va_list, t_flags);
t_handler		get_handler(char c);
#endif
