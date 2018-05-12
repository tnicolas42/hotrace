/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmilan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 19:05:07 by pmilan            #+#    #+#             */
/*   Updated: 2018/05/12 19:25:20 by pmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | parsing.c                                                |
**   |     ft_parse_get(24 lines)                               |
**   |     ft_parse(25 lines)                                   |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <hotrace.h>

static int		ft_parse_get(t_a *a, int start)
{
	int		index;
	t_tree	*result;
	int		i;
	int		len;

	i = start - 1;
	while (a->str[++i])
	{
		if (a->str[i] == '\n')
		{
			len = ft_len(&(a->str[start]), '\n');
			index = super_fast_hash(&(a->str[start]), len) >> (32 - SIZE);
			result = ft_tree_get(a->arr[index], &(a->str[start]), len);
			if (result == NULL)
			{
				write(STDOUT_FILENO, &(a->str[start]), len);
				write(STDOUT_FILENO, ": Not found.\n", 13);
			}
			else
				write(STDOUT_FILENO, result->value, result->len_value + 1);
			start = i + 1;
		}
	}
	return (SUCCESS);
}

int				ft_parse(t_a *a)
{
	int		start;
	int		i;
	int		nb_nl;

	nb_nl = 0;
	start = 0;
	i = -1;
	while (a->str[++i])
	{
		if (a->str[i] == '\n')
		{
			nb_nl++;
			i++;
			if (nb_nl == 2)
			{
				if (ft_hash(a, start) == ERROR)
					return (ERROR);
				start = i;
				nb_nl = 0;
			}
			if (a->str[i] == '\n')
				return (ft_parse_get(a, ++i));
		}
	}
	return (SUCCESS);
}
