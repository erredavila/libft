/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_length_base.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 22:39:04 by rdavila           #+#    #+#             */
/*   Updated: 2017/04/10 14:24:19 by rdavila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_num_length_base(size_t value, char *base)
{
	int		i;
	size_t	base_len;

	i = 0;
	base_len = ft_strlen(base);
	if (value == 0)
		return (1);
	while (value)
	{
		value /= base_len;
		i++;
	}
	return (i);
}
