/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavila <rdavila@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 19:28:52 by rdavila           #+#    #+#             */
/*   Updated: 2017/04/10 11:55:14 by rdavila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

int		ft_printf_handle_int(char c, va_list args, t_flags flags)
{
	intmax_t	num;
	char		*prefix;

	if (c == 'D')
		flags.length = l;
	num = parse_signed(args, flags);
	prefix = "";
	if (num < 0 || flags.force_sign || flags.blank)
	{
		if (num < 0)
		{
			num *= -1;
			prefix = "-";
		}
		else if (flags.force_sign)
			prefix = "+";
		else if (flags.blank)
			prefix = " ";
		return (force_prefix(num, "0123456789", flags, prefix));
	}
	return (ft_printf_handle_uint(num, flags, "0123456789", NULL));
}
