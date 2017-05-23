/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 20:14:41 by lalves            #+#    #+#             */
/*   Updated: 2017/03/25 18:24:58 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static void		free_env(t_env **env)
{
	t_files *tmp;

	tmp = (*env)->args;
	while ((*env)->args)
	{
		(*env)->args = (*env)->args->next;
		free(tmp->name);
		free(tmp);
		tmp = (*env)->args;
	}
}

int				main(int ac, char **av)
{
	t_env *env;

	if (ac > 1)
	{
		env = ft_memalloc(sizeof(t_env));
		get_args(ac, av, env);
		advanced_ls(env);
		free_env(&env);
	}
	else
		basic_ls();
	return (0);
}
