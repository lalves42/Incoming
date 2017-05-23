/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 19:48:14 by lalves            #+#    #+#             */
/*   Updated: 2017/03/25 19:48:16 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static void		get_file(char *str, t_env *env)
{
	t_files *new;

	new = ft_memalloc(sizeof(t_files));
	new->name = ft_strdup(str);
	if (env->args)
		new->next = env->args;
	env->args = new;
}

static void		save_flags(char *str, t_env *env)
{
	int i;

	i = 1;
	while (str[i])
	{
		if (!ft_strchr(env->flags, str[i]))
		{
			env->flags[env->nb_flags] = str[i];
			(env->nb_flags)++;
		}
		i++;
	}
}

static void		check_flags(char *str, t_env *env)
{
	int i;

	i = 1;
	while (str[i])
	{
		if (!ft_strchr(FLAG_CHARS, str[i]))
			exit(illegal_option(str[i]));
		i++;
	}
	save_flags(str, env);
}

void			get_args(int ac, char **av, t_env *env)
{
	int i;

	i = 1;
	while (i < ac && av[i][0] == '-' && ft_strlen(av[i]) > 1)
	{
		if (av[i][1] == '-')
		{
			if (ft_strlen(av[i]) > 2)
				exit(illegal_option('-'));
			i++;
			break ;
		}
		check_flags(av[i], env);
		i++;
	}
	while (i < ac)
	{
		get_file(av[i], env);
		i++;
	}
}
