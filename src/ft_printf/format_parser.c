/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 16:25:08 by rdavila           #+#    #+#             */
/*   Updated: 2017/04/11 20:29:24 by rdavila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

char	*ft_parse_flags(char **format, t_flags *flags)
{
	if (**format == '-' || **format == '+' || **format == ' ' ||
			**format == '0' || **format == '#')
	{
		if (**format == '-')
			flags->left_align = 1;
		else if (**format == '+')
			flags->force_sign = 1;
		else if (**format == ' ')
			flags->blank = 1;
		else if (**format == '0')
			flags->pad_zero = 1;
		else if (**format == '#')
			flags->prefix = 1;
		(*format)++;
		return (ft_parse_flags(format, flags));
	}
	return (*format);
}

char	*ft_parse_width(char **format, va_list args, t_flags *flags)
{
	if (**format == '*' || ft_isdigit(**format))
	{
		if (**format == '*')
		{
			flags->width = va_arg(args, int);
			flags->got_width = 1;
			if (flags->width < 0)
			{
				flags->left_align = 1;
				flags->width = ft_abs(flags->width);
			}
			(*format)++;
		}
		else if (ft_isdigit(**format))
		{
			flags->width = ft_atoi(*format);
			flags->got_width = 1;
			while (ft_isdigit(**format))
				(*format)++;
		}
		return (ft_parse_width(format, args, flags));
	}
	return (*format);
}

char	*ft_parse_precision(char **format, va_list args, t_flags *flags)
{
	if (**format == '.')
	{
		(*format)++;
		if (**format == '*')
		{
			flags->precision = va_arg(args, int);
			if (flags->precision >= 0)
				flags->got_precision = 1;
			(*format)++;
		}
		else
		{
			flags->precision = ft_atoi(*format);
			if (flags->precision >= 0)
				flags->got_precision = 1;
			while (ft_isdigit(**format))
				(*format)++;
		}
	}
	return (*format);
}

char	*ft_clean_length(char **format)
{
	while (**format == 'h' || **format == 'l' || **format == 'j' ||
			**format == 'z')
		(*format)++;
	return (*format);
}

char	*ft_parse_length(char **format, t_flags *flags)
{
	if (**format == 'h' || **format == 'l' || **format == 'j' ||
			**format == 'z')
	{
		if (**format == 'h' && *(*format + 1) == 'h')
		{
			flags->length = hh;
			(*format)++;
		}
		else if (**format == 'l' && *(*format + 1) == 'l')
		{
			flags->length = ll;
			(*format)++;
		}
		else if (**format == 'h')
			flags->length = h;
		else if (**format == 'l')
			flags->length = l;
		else if (**format == 'j')
			flags->length = j;
		else if (**format == 'z')
			flags->length = z;
		(*format)++;
		return (ft_clean_length(format));
	}
	return (*format);
}
