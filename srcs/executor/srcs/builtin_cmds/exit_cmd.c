/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:11:47 by mnaimi            #+#    #+#             */
/*   Updated: 2022/06/03 17:13:05 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../executor.h"

/* -------------------------------------------------------------------------- *\
TODO-[X]
\* -------------------------------------------------------------------------- */

void	exit_error(char *varname, char *message)
{
	write(2, varname, ft_strlen(varname));
	write(2, ":\t", 2);
	write(2, message, ft_strlen(message));
	write(2, "\n", 1);
}

/* -------------------------------------------------------------------------- *\
TODO-[X]
\* -------------------------------------------------------------------------- */

u_int8_t	ascii_to_8bit_int(const char *str)
{
	int8_t		sign;
	u_int8_t	sum;
	int			i;

	i = 0;
	sum = 0;
	sign = 0;
	while (ft_isspace(str[i]))
		++i;
	if (str[i] == '-' || str[i] == '+')
		sign = str[i] - '+';
	while (ft_isdigit(str[i]))
		sum = (sum * 10) + (str[i++] - '0');
	if (sign)
		sum *= -1;
	return (sum);
}

/* -------------------------------------------------------------------------- *\
TODO-[X]
\* -------------------------------------------------------------------------- */

void	exit_cmd(char **input, t_env_vars **env_head)
{
	u_int8_t	exit_status;
	int			i;

	(void)env_head;
	i = 0;
	exit_status = g_glob.exit;
	restore_ctrl();
	if (input[1])
	{
		while (input[1][i])
		{
			if (!ft_isdigit(input[1][i++]))
			{
				print_err("exit", input[1], "numeric argument required");
				exit(-1);
			}
		}
		exit_status = ascii_to_8bit_int(input[1]);
	}
	exit((int)exit_status);
}
