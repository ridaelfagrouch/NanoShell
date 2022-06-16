/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:11:47 by mnaimi            #+#    #+#             */
/*   Updated: 2022/06/03 17:13:05 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../executor.h"

/* -------------------------------------------------------------------------- */

int	env_cmd(char **input, t_env_vars *env_head)
{
	t_env_vars	*node;

	input = NULL;
	node = env_head;
	while (node)
	{
		if (node->key && node->value)
			printf("%s=%s\n", node->key, node->value);
		node = node->next;
		return (0);
	}
	return (-1);
}

/* -------------------------------------------------------------------------- */

/*
	CMD RULES:

	Without any argument : print out a list of all environment variables.
*/

/* -------------------------------------------------------------------------- */