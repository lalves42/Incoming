/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 13:51:57 by lalves            #+#    #+#             */
/*   Updated: 2017/03/25 16:46:37 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_atoi(const char *str)
{
	int	convert;
	int	nb;
	int i;

	convert = 1;
	nb = 0;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (!ft_isdigit(str[i]) && !ft_isdigit(str[i + 1]))
		return (0);
	if (str[i] == '-')
	{
		convert = -1;
		i++;
	}
	if (str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	return (nb * convert);
}
