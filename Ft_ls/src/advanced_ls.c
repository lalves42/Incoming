/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advanced_ls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 19:47:47 by lalves            #+#    #+#             */
/*   Updated: 2017/03/25 21:52:36 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void			advanced_ls(t_env *env)
{
	get_args_type(env);
	sort_args_type(env);
/*	check_files(env);
//	if (ft_strchr(FLAG_CHARS, 't'))
//		sort_args_time;
//	else
//		sort_args_ascii(env);
//	if (ft_strchr(FLAG_CHARS, 'r'))
//		sort_args_reverse;
//	check_lst(env);
*/
}
