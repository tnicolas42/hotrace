/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 10:35:42 by tnicolas          #+#    #+#             */
/*   Updated: 2018/05/12 14:57:36 by pmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | tree.c                                                   |
**   |     ft_tree_new(9 lines)                                 |
**   |     ft_cmp(14 lines)                                     |
**   |     ft_tree_add(29 lines)                                |
**   |         MEUUUU too many lines                            |
**   |     ft_tree_get(12 lines)                                |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <hotrace.h>

int			ft_tree_new(t_tree **arri, t_tree *new)
{
	if (!(*arri = malloc(sizeof(t_tree))))
		return (ERROR);
	(*arri)->key = new->key;
	(*arri)->value = new->value;
	(*arri)->len_key = new->len_key;
	(*arri)->len_value = new->len_value;
	(*arri)->left = NULL;
	(*arri)->right = NULL;
	return (SUCCESS);
}

int			ft_cmp(char *s1, char *s2, int size1, int size2)
{
	int		cmp;

	cmp = ft_memcmp(s1, s2, size2 ^ ((size1 ^ size2) & -(size1 < size2)));
	if (cmp == 0 && size1 != size2)
	{
		if (size1 > size2)
			return (LEFT);
		return (RIGHT);
	}
	if (cmp < 0)
		return (RIGHT);
	if (cmp > 0)
		return (LEFT);
	return (SAME);
}

int			ft_tree_add(t_tree *arri, t_tree *new)
{
	int		cmp;

	cmp = ft_cmp(arri->key, new->key, arri->len_key, new->len_key);
	if (cmp == LEFT)
	{
		if (arri->left == NULL)
		{
			if (ft_tree_new(&(arri->left), new) == ERROR)
				return (ERROR);
		}
		else
			return (ft_tree_add(arri->left, new));
	}
	else if (cmp == RIGHT)
	{
		if (arri->right == NULL)
		{
			if (ft_tree_new(&(arri->right), new) == ERROR)
				return (ERROR);
		}
		else
			return (ft_tree_add(arri->right, new));
	}
	else if (cmp == SAME && (arri->value = new->value))
		arri->len_value = new->len_value;
	return (SUCCESS);
}

t_tree		*ft_tree_get(t_tree *arri, char *key, int len_key)
{
	int		cmp;

	if (arri == NULL)
		return (NULL);
	cmp = ft_cmp(arri->key, key, arri->len_key, len_key);
	if (cmp == SAME)
		return (arri);
	else if (cmp == LEFT)
		return (ft_tree_get(arri->left, key, len_key));
	else if (cmp == RIGHT)
		return (ft_tree_get(arri->right, key, len_key));
	return (NULL);
}
