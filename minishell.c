/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 21:30:02 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/06/22 20:40:55 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* -------------------------------------------------------------------------- */

char	*get_env_vars_var_value(const char *var, char **env)
{
	int	i;
	int	j;

	i = -1;
	while (env[++i] != NULL)
	{
		if (ft_strncmp(env[i], var, ft_strlen(var)) == 0)
		{
			j = -1;
			while (env[i][++j])
				if (env[i][j] == '=')
					return (&(env[i][++j]));
		}
	}
	return (NULL);
}

/* -------------------------------------------------------------------------- */

// char	*get_dynamic_prompt(char **env)
// {
// 	char	*user;
// 	char	*current_dir;
// 	char	*home;
// 	char	*prompt;

// 	user = get_env_vars_var_value("USER", env);
// 	current_dir = get_env_vars_var_value("PWD", env);
// 	home = get_env_vars_var_value("HOME", env);
// 	if (ft_strncmp(home, current_dir, ft_strlen(home)) == 0)
// 		current_dir += ft_strlen(home);
	// "user@hostname [hh:mm:ss] [current_dir]"
	// ">% "
// }

/* -------------------------------------------------------------------------- */

static int	prompt(t_info *info, char **envp)
{
	char				*rdln_output;
	char				*str;
	t_env_vars			*env_head;
	//char	*prompt;
	env_head = conv_env(envp);
	while (1)
	{
		handle_signals();
		rdln_output = readline(GRN"Minishell > "NNN);
		if (rdln_output== NULL)
		{
			write(STDOUT_FILENO, "\b\bexit\n", 7);
			exit(g_glob.exit);
		}
		info->input = ft_strtrim(rdln_output, WHITESPACE);
		if (*(info->input) == '\0')
			continue ;
		add_history(rdln_output);
		str = ft_strdup(info->input);
		if (!lexer_start(info))
		{
			free(info->input);
			free(str);
			continue ;
		}
		parcer(str, info);
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

	if (ft_strcmp(av[0], "./minishell") == 0 && ac == 1)
		if (prompt(&info, envp) == 1)
			return (1);
	return (0);
}

/* -------------------------------------------------------------------------- */
