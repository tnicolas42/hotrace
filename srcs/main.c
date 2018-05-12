/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 22:02:34 by tnicolas          #+#    #+#             */
/*   Updated: 2018/05/12 15:14:57 by pmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | main.c                                                   |
**   |     ft_add_key(11 lines)                                 |
**   |     ft_len(6 lines)                                      |
**   |     ft_algo(4 lines)                                     |
**   |     ft_parse_get(17 lines)                               |
**   |     ft_hash(11 lines)                                    |
**   |     ft_parse(28 lines)                                   |
**   |         MEUUUU too many lines                            |
**   |     ft_init(2 lines)                                     |
**   |     main(11 lines)                                       |
**   | MEUUUU too many functions                                |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <hotrace.h>

int			ft_add_key(t_a *a, t_tree *new, int index)
{
	if (a->arr[index] == NULL)
	{
		if (ft_tree_new(&(a->arr[index]), new) == ERROR)
			return (ERROR);
	}
	else
	{
//		puts("start_add");
		if (ft_tree_add(a->arr[index], new) == ERROR)
			return (ERROR);
//		puts("end_add");
	}
	return (SUCCESS);
}

int			ft_len(char *s, char c)
{
	int		i;

	i = -1;
	while (s[++i] != c && s[i])
		;
	return (i);
}

int			ft_algo(char *key, int len)
{
	int		ret;

//	if (key[1] == 'A')
//		return 60001;
//	return 31115;
	ret = super_fast_hash(key, len) >> 15;
//	printf("ret algo\t%d\n", ret);
	return (ret);
}

int			ft_parse_get(t_a *a, int start)
{
	int		index;
	t_tree	*result;
	int		i;
	char	error[] = ": Not found.\n";
	int		len;

	i = start - 1;
	while (a->str[++i])
	{
		if (a->str[i] == '\n')
		{
			len = ft_len(&(a->str[start]), '\n');
			index = ft_algo(&(a->str[start]), len);
			result = ft_tree_get(a->arr[index], &(a->str[start]), len);
			if (result == NULL)
			{
				write(STDOUT_FILENO, &(a->str[start]), ft_len(&(a->str[start]), '\n'));
				write(STDOUT_FILENO, error, ft_strlen(error));
			}
			else
			{
				write(STDOUT_FILENO, result->value, result->len_value);
				write(STDOUT_FILENO, "\n", 1);
			}
			start = i + 1;
		}
	}
	return (SUCCESS);
}

int			ft_hash(t_a *a, int start)
{
	t_tree	new;
	int		index;

	new.len_key = ft_len(&(a->str[start]), '\n');
	new.key = &(a->str[start]);
	new.value = &(a->str[start + new.len_key + 1]);
	new.len_value = ft_len(&(a->str[start + new.len_key + 1]), '\n');
	index = ft_algo(new.key, new.len_key);
	if (ft_add_key(a, &new, index) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

int			ft_parse(t_a *a)
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
			{
				start = ++i;
				return (ft_parse_get(a, start));
			}
		}
	}
	return (SUCCESS);
}

int			ft_init(t_a *a)
{
	ft_bzero(a, sizeof(a));
	return (SUCCESS);
}

int			main(int ac, char **av)
{
	t_a		a;

	(void)ac;
	(void)av;
	if (ft_init(&a) == ERROR)
		return (EXIT_FAILURE);
	if (ft_read_fd(STDIN_FILENO, &(a.str)) == 0)
		return (EXIT_FAILURE);
	if (ft_parse(&a) == ERROR)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
