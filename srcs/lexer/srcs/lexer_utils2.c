/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:47:20 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/06/24 15:48:29 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lexer.h"

/* -------------------------------------------------------------------------- */

void	removechar2(char *str, char chartoremmove, int k)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = strlen(str);
	while (i < len)
	{
		if (str[i] == chartoremmove && i == k)
		{
			j = i;
			while (j < len)
			{
				str[j] = str[j + 1];
				j++;
			}
			len--;
			i--;
		}
		i++;
	}
}

/* -------------------------------------------------------------------------- */

char	*remove_red_in(char *str, int flag)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (flag == 0)
		{
			if (str[i] == IN && str[i + 1] == OUT)
			{
				removechar2(str, str[i + 1], i + 1);
				remove_red_in(str, flag);
			}
		}
		if (flag == 1)
		{
			if (str[i] == '<' && str[i + 1] == '>')
			{
				removechar2(str, str[i + 1], i + 1);
				remove_red_in(str, flag);
			}
		}
		i++;
	}
	return (str);
}

/* -------------------------------------------------------------------------- */