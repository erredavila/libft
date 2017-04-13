/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 13:41:24 by rdavila           #+#    #+#             */
/*   Updated: 2017/04/10 14:22:37 by rdavila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

int		ft_printf_numstrlen(uintmax_t num, char *base, char *prefix,
		t_flags flags)
{
	int	len;
	int	numstrlen;

	len = ft_num_length_base(num, base);
	numstrlen = len;
	if (!num && flags.got_precision && !flags.precision)
		numstrlen = 0;
	else if (flags.got_precision)
		numstrlen = ft_max(len, flags.precision);
	if (flags.prefix && prefix && num)
		numstrlen += ft_strlen(prefix);
	return (numstrlen);
}

int		force_prefix(uintmax_t num, char *base, t_flags flags, char *prefix)
{
	int		len;
	int		cut;

	cut = ft_strlen(prefix);
	len = ft_printf_numstrlen(num, base, prefix, flags) + cut;
	if (flags.got_width && !flags.left_align && !flags.pad_zero)
	{
		add_padding(len, flags.width, ' ');
		cut += ft_max(flags.width - len, 0);
		flags.got_width = 0;
	}
	else if (flags.got_width)
		flags.width -= cut;
	ft_putstr(prefix);
	return (ft_printf_handle_uint(num, flags, base, NULL) + cut);
}

void	ft_printf_putnbr(uintmax_t num, char *base, t_flags flags,
		int *numstrlen)
{
	int len;

	len = ft_num_length_base(num, base);
	if (flags.got_precision)
		add_padding(len, flags.precision, '0');
	if (flags.prefix && !num && flags.got_precision &&
			!ft_strcmp(base, "01234567"))
	{
		ft_putchar('0');
		*numstrlen += 1;
	}
	if (!num && flags.got_precision && !flags.precision)
		return ;
	ft_putnbrbase(num, base);
}

int		ft_printf_handle_uint(uintmax_t num, t_flags flags, char *base,
		char *prefix)
{
	int	len;
	int	numstrlen;

	if (flags.got_precision)
		flags.pad_zero = 0;
	len = ft_num_length_base(num, base);
	numstrlen = ft_printf_numstrlen(num, base, prefix, flags);
	if (flags.got_width && !flags.left_align && flags.pad_zero)
	{
		if (flags.prefix)
			flags.precision = ft_max(flags.width - ft_strlen(prefix), len);
		else
			flags.precision = ft_max(flags.width, len);
		flags.got_precision = 1;
	}
	if (flags.got_width && !flags.left_align && !flags.pad_zero)
		add_padding(numstrlen, flags.width, ' ');
	if (flags.prefix && num)
		ft_putstr(prefix);
	ft_printf_putnbr(num, base, flags, &numstrlen);
	if (flags.got_width && flags.left_align)
		add_padding(numstrlen, flags.width, ' ');
	return (flags.got_width ? ft_max(numstrlen, flags.width) : numstrlen);
}
