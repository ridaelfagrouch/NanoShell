/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 21:30:02 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/06/24 16:14:37 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* -------------------------------------------------------------------------- */

t_env_vars	*get_env(const char *var, t_env_vars *env_head)
{
	t_env_vars	*node;

	node = env_head;
	while (node)
	{
		if (ft_strcmp(node->key, var) == 0)
			break ;
		node = node->next;
	}
	return (node);
}

/* -------------------------------------------------------------------------- */

static int	prompt(t_info *info, char **envp)
{
	char				*rdln_output;
	char				*str;
	t_env_vars			*env_head;

	env_head = conv_env(envp);
	g_glob.heredoc_pid = -1;
	while (1)
	{
		handle_signals();
		rdln_output = readline("\001\e[1;4;34m\002minishell-6.9$\001\e[0m\002 ");
		if (rdln_output == NULL)
		{
			printf("exit\n");;
			restore_ctrl();
			return (g_glob.exit);
		}
		info->input = ft_strtrim(rdln_output, WHITESPACE);
		if (*(info->input) == '\0')
			continue ;
		add_history(rdln_output);
		str = ft_strdup(info->input);
		if (!lexer_start(info) || parcer(str, info))
		{
			free(info->input);
			free(str);
			continue ;
		}
		free(info->input);
		free(str);
		handle_execution(info, &env_head);
	}
	return (0);
}

/* -------------------------------------------------------------------------- */

int	main(int ac, char **av, char **envp)
{
	t_info	info;

	hide_ctrl();
	if (ft_strcmp(av[0], "./minishell") == 0 && ac == 1)
		if (prompt(&info, envp) == 1)
			return (1);
	return (0);
}

/* -------------------------------------------------------------------------- */
