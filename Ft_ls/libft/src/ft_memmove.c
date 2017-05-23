/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 15:26:34 by lalves            #+#    #+#             */
/*   Updated: 2017/03/25 16:26:08 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*temp;

	temp = malloc(len);
	if (!temp)
		exit(ft_error("malloc"));
	ft_memcpy(temp, src, len);
	ft_memcpy(dst, (const void*)temp, len);
	free(temp);
	return (dst);
}
