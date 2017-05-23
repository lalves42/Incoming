/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 18:05:15 by lalves            #+#    #+#             */
/*   Updated: 2017/03/25 21:51:54 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * R -> Recursive
 * a -> Affiche les .
 * l -> Long Format
 * t -> Sort by time
 * r -> Reverse sort
 */

#ifndef FT_LS_H

# define FT_LS_H

# include <libft.h>
# include <dirent.h>

# define FLAG_CHARS "Ralrt"
# define ERR_FLAG "ft_ls: illegal option -- "
# define USAGE "usage: ft_ls [-Ralrt] [file ...]\n"

typedef struct dirent	t_dirent;

typedef struct			s_files
{
	char			*name;
	int				type;
	struct s_files	*next;
}						t_files;

typedef struct			s_env
{
	struct s_files	*args;
	char			flags[6];
	int				nb_flags;
}						t_env;

void		basic_ls(void);

void		advanced_ls(t_env *env);

void		get_args(int ac, char **av, t_env *env);
void		get_args_type(t_env *env);
void		sort_args_type(t_env *env);
void		sort_args_ascii(t_env *env);
int			illegal_option(char c);

#endif
