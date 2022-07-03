/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init_2nd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:11:47 by mnaimi            #+#    #+#             */
/*   Updated: 2022/06/03 17:13:05 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executor.h"

/* -------------------------------------------------------------------------- *\
TODO-[X]
\* -------------------------------------------------------------------------- */

int	set_default_pwd(t_env_vars **head)
{
	char	*env_var;
	char	cwd[PATH_MAX];

	if (get_env_var("PWD", *head))
		return (0);
	if (getcwd(cwd, sizeof(cwd)) == NULL)
		return (print_err("getcwd", "failed to get CWD", NULL), -1);
	env_var = ft_strjoin("PWD=", cwd);
	if (env_var == NULL)
		return (-1);
	if (process_env_var(head, env_var) != 0 || process_env_var(head, "OLDPWD"))
		return (free(env_var), -1);
	return (free(env_var), 0);
}

/* -------------------------------------------------------------------------- *\
TODO-[X]
\* -------------------------------------------------------------------------- */

int	set_shell_lvl(t_env_vars **head)
{
	t_env_vars	*node;
	int			shlvl_int;
	char		*shlvl_str;

	node = get_env_var("SHLVL", *head);
	if (node == NULL)
		return (process_env_var(head, "SHLVL=1"));
	shlvl_int = ft_atoi(node->value);
	shlvl_str = ft_itoa(++shlvl_int);
	free(node->value);
	node->value = shlvl_str;
	return (0);
}

/* -------------------------------------------------------------------------- *\
TODO-[X]
\* -------------------------------------------------------------------------- */

void	free_env_linked_list(t_env_vars *head)
{
	t_env_vars	*node;
	t_env_vars	*tracer;

	node = head;
	while (node)
	{
		tracer = node->next;
		free(node->key);
		free(node->value);
		free(node);
		node = tracer;
	}
}
