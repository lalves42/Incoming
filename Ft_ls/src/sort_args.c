/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 19:53:03 by lalves            #+#    #+#             */
/*   Updated: 2017/03/25 21:53:13 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	sort_args_ascii(t_env *env)
{
	t_files *lst;
	char	*tmp;

	lst = env->args;
	while (lst && lst->next)
	{
		if (lst->type != lst->next->type)
			lst = lst->next;
		else if (ft_strcmp(lst->name, lst->next->name) > 0)
		{
			tmp = lst->name;
			lst->name = lst->next->name;
			lst->next->name = tmp;
			lst = env->args;
		}
		else
			lst = lst->next;
	}
}

void	sort_args_type(t_env *env)
{
	t_files *lst;
	char	*tmp;
	int		temp;

	lst = env->args;
	while (lst && lst->next)
	{
		if (lst->type > lst->next->type)
		{
			tmp = lst->name;
			temp = lst->type;
			lst->name = lst->next->name;
			lst->type = lst->next->type;
			lst->next->name = tmp;
			lst->next->type = temp;
			lst = env->args;
		}
		else
			lst = lst->next;
	}
}

void	get_args_type(t_env *env)
{
	t_files *lst;
	DIR		*open_dir;

	lst = env->args;
	while (lst)
	{
		if ((open_dir = opendir(lst->name)))
		{
			lst->type = DT_DIR;
			closedir(open_dir);
		}
		lst = lst->next;
	}
}
