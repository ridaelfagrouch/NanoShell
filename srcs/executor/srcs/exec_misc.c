/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:11:47 by mnaimi            #+#    #+#             */
/*   Updated: 2022/06/03 17:13:05 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executor.h"

/* -------------------------------------------------------------------------- */

t_env_vars	*get_env_var(char *varname, t_env_vars *env_head)
{
	t_env_vars	*node;

	node = env_head;
	while (node)
	{
		if (ft_strcmp(node->key, varname) == 0)
			return (node);
		node = node->next;
	}
	return (NULL);
}

/* -------------------------------------------------------------------------- */

char	**split_path_env_var(t_env_vars *env_head)
{
	t_env_vars	*paths;
	char		**splited_paths;

	paths = get_env_var("PATH", env_head);
	if (paths->value == NULL)
		return (NULL);
	splited_paths = ft_split(paths->value, ':');
	return (splited_paths);
}

/* -------------------------------------------------------------------------- */

void	print_filetype(char *input)
{
	struct stat	file_stat;

	if (stat(input, &file_stat))
		return ;
	if (S_ISREG(file_stat.st_mode))
		printf("Filetype:\tRegular File\n");
	else if (S_ISDIR(file_stat.st_mode))
		printf("Filetype:\tDirectory\n");
	else
		printf("Unknown Filetype\n");
}

/* -------------------------------------------------------------------------- */