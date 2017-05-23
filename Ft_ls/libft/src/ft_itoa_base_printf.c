/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 23:48:55 by lalves            #+#    #+#             */
/*   Updated: 2017/03/25 16:51:49 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static int		get_size(uintmax_t nb, int base)
{
	int i;

	if (nb == 0)
		return (1);
	i = 0;
	while (nb > 0)
	{
		nb = nb / base;
		i++;
	}
	return (i);
}

static int		get_base(char c)
{
	if (c == 'x' || c == 'X')
		return (16);
	if (c == 'o' || c == 'O')
		return (8);
	if (c == 'u' || c == 'U')
		return (10);
	if (c == 'b' || c == 'B')
		return (2);
	return (10);
}

char			*ft_itoa_base_printf(uintmax_t nb, char c)
{
	char		*str;
	int			size;
	int			base;
	uintmax_t	tmp;

	base = get_base(c);
	size = get_size(nb, base);
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		exit(ft_error("malloc"));
	str[size] = '\0';
	size--;
	while (nb > 0)
	{
		tmp = nb % (uintmax_t)base;
		if (tmp > 9)
			str[size] = 'a' + tmp - 10;
		else
			str[size] = '0' + tmp;
		nb = nb / (uintmax_t)base;
		size--;
	}
	return (str);
}
