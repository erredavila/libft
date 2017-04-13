/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavila <rdavila@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 11:39:39 by rdavila           #+#    #+#             */
/*   Updated: 2017/04/12 15:20:14 by rdavila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static char	**handle_mask(char *bin, char *m)
{
	char	*mask;
	char	**bytes;
	int		bin_len;
	int		mask_len;
	int		i;

	mask = ft_strdup(m);
	bin_len = ft_strlen(bin) - 1;
	mask_len = ft_strlen(mask) - 1;
	i = 0;
	while (bin_len >= 0 && mask_len >= 0)
	{
		if (mask[mask_len] == 'x' && bin_len >= 0)
		{
			mask[mask_len] = bin[bin_len];
			bin_len--;
		}
		mask_len--;
	}
	i = -1;
	while (mask[++i])
		(mask[i] == 'x') ? mask[i] = '0' : 0;
	bytes = ft_strsplit(mask, ' ');
	free(mask);
	return (bytes);
}

void		ft_putwchar(wchar_t c)
{
	char	*bin;
	char	**bytes;
	int		i;

	(void)c;
	bin = ft_itoa_base(c, 2);
	if (c <= 0x7F)
		bytes = handle_mask(bin, "0xxxxxxx");
	else if (c <= 0x7FF)
		bytes = handle_mask(bin, "110xxxxx 10xxxxxx");
	else if (c <= 0xFFFF)
		bytes = handle_mask(bin, "1110xxxx 10xxxxxx 10xxxxxx");
	else if (c <= 0x10FFFF)
		bytes = handle_mask(bin, "11110xxx 10xxxxxx 10xxxxxx 10xxxxxx");
	else
		bytes = NULL;
	i = 0;
	while (bytes[i])
	{
		ft_putchar(ft_atoi_base(bytes[i], 2));
		free(bytes[i]);
		i++;
	}
	free(bin);
	free(bytes);
}
