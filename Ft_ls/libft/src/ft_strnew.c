/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 16:23:20 by lalves            #+#    #+#             */
/*   Updated: 2017/03/25 17:15:28 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strnew(size_t size)
{
	char	*str;

	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		exit(ft_error("malloc"));
	ft_bzero((void*)str, size);
	return (str);
}
