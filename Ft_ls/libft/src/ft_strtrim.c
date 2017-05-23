/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 17:51:56 by lalves            #+#    #+#             */
/*   Updated: 2017/03/25 17:18:13 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strtrim(char const *s)
{
	unsigned int	start;
	size_t			len;
	char			*str;

	len = ft_strlen(s) - 1;
	start = 0;
	str = NULL;
	while (ft_isspace(s[start]))
		start++;
	if (s[start] == '\0')
	{
		str = malloc(sizeof(char));
		if (!str)
			exit(ft_error("malloc"));
		str[0] = '\0';
		return (str);
	}
	while (ft_isspace(s[len]))
		len--;
	len = len - start + 1;
	return (ft_strsub(s, start, len));
}
