/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_ls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 20:23:22 by lalves            #+#    #+#             */
/*   Updated: 2017/03/21 21:48:01 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static void		free_list(t_files **files)
{
	if ((*files)->next)
		free_list(&(*files)->next);
	free((*files)->name);
	free(*files);
}

static void		print_list(t_files *files)
{
	while (files)
	{
		ft_putendl(files->name);
		files = files->next;
	}
}

static void		sort_list(t_files **files)
{
	t_files *lst;
	char	*tmp;

	lst = *files;
	while (lst && lst->next)
	{
		if (ft_strcmp(lst->name, lst->next->name) > 0)
		{
			tmp = lst->name;
			lst->name = lst->next->name;
			lst->next->name = tmp;
			lst = *files;
		}
		else
			lst = lst->next;
	}
}

static void		save_file(t_files **files, char *name)
{
	t_files *new;

	new = ft_memalloc(sizeof(t_files));
	new->name = ft_strdup(name);
	if (*files)
		new->next = *files;
	*files = new;
}

void			basic_ls(void)
{
	DIR			*open_dir;
	t_dirent	*cur;
	t_files		*files;

	files = NULL;
	if ((open_dir = opendir(".")) == NULL)
	{
		perror("ft_ls");
		exit(1);
	}
	while ((cur = readdir(open_dir)))
	{
		if (cur->d_name[0] != '.')
			save_file(&files, cur->d_name);
	}
	if (closedir(open_dir) == -1)
		perror("ft_ls");
	sort_list(&files);
	print_list(files);
	free_list(&files);
}
