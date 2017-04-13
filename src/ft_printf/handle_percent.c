/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_percent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 20:38:28 by rdavila           #+#    #+#             */
/*   Updated: 2017/03/23 13:06:15 by rdavila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

int		ft_printf_handle_percent(char c, va_list args, t_flags flags)
{
	(void)c;
	(void)args;
	if (flags.got_width && !flags.left_align)
		add_padding(1, flags.width, flags.pad_zero ? '0' : ' ');
	ft_putchar('%');
	if (flags.got_width && flags.left_align)
		add_padding(1, flags.width, ' ');
	if (flags.got_width)
		return (ft_max(1, flags.width));
	return (1);
}
