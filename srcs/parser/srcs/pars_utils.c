/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 13:16:01 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/06/14 10:08:50 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

void	while_operator(t_info *info, char *str)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	if (info->input[info->i] == '\"' || info->input[info->i] == '\'')
	{
		while (info->input[info->i] == '\"' || info->input[info->i] == '\'')
			info->i++;
		while (info->input[info->i] != '\"' && info->input[info->i] != '\'')
		{
			str[j] = info->input[info->i];
			info->i++;
			j++;
		}
		while (info->input[info->i] == '\"' || info->input[info->i] == '\'')
			info->i++;
	}
	else
	{
		while (info->input[info->i] && check_operator(info, 1) \
			&& info->input[info->i] != ' ')
		{
			while (info->input[info->i] == '\"' || \
				info->input[info->i] == '\'')
				info->i++;
			str[j] = info->input[info->i];
			info->i++;
			j++;
		}
	}
}

/* -------------------------------------------------------------------------- */

void	scape_space(t_info *info)
{
	while (info->input[info->i] && info->input[info->i] == ' ')
		info->i++;
}

/* -------------------------------------------------------------------------- */
