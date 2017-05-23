/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 12:33:01 by lalves            #+#    #+#             */
/*   Updated: 2017/03/25 16:51:06 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int		ft_get_length(intmax_t n)
{
	int len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n > 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char			*ft_itoa(intmax_t n)
{
	int		len;
	char	*str;

	len = ft_get_length(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		exit(ft_error("malloc"));
	str[len] = '\0';
	len--;
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (len >= 0)
	{
		if (str[len] == '-')
			break ;
		str[len--] = (n % 10) + 48;
		n = n / 10;
	}
	return (str);
}
