/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:11:47 by mnaimi            #+#    #+#             */
/*   Updated: 2022/06/03 17:13:05 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../executor.h"

// * ---------------------------------------------------------------------- * ///

static int	echo_flag_is_valid(char *flag)
{
	int	i;

	i = 1;
	if (flag[0] != '-')
		return (1);
	while (flag[i])
		if (flag[i++] != 'n')
			return (0);
	return (1);
}

// * ---------------------------------------------------------------------- * ///

int	echo_cmd(char **input, t_env_vars **env_head)
{
	int	n_flag;
	int	i;

	(void)env_head;
	n_flag = 0;
	i = 1;
	while (input[i] && ft_strstr(input[i], "-n") && \
		ft_strchr(input[i], '-') == ft_strrchr(input[i], '-') && \
		echo_flag_is_valid(input[i]))
	{
		n_flag = 1;
		i++;
	}
	while (input[i])
	{
		if (ft_strcmp(input[i], "$?") == 0)
			printf("%d", (int)g_glob.exit);
		else
			printf("%s", input[i]);
		i++;
		if (input[i])
			printf(" ");
	}
	if (n_flag == 0)
		printf("\n");
	return (0);
}

// * ---------------------------------------------------------------------- * ///
