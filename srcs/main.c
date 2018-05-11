/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 22:02:34 by tnicolas          #+#    #+#             */
/*   Updated: 2018/05/11 22:02:34 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <hotrace.h>

int			ft_tree_new(t_tree **arri, char *key, char *value)
{
	if (!(*arri = malloc(sizeof(t_tree))))
		return ERROR;
	(*arri)->key = strdup(key);////////////////////
	(*arri)->value = strdup(value);////////////////////
	(*arri)->left = NULL;
	(*arri)->right = NULL;
	return SUCCESS;
}

int			ft_cmp(char *s1, char *s2)
{
	int		cmp;

	cmp = strcmp(s1, s2);/////////////
	if (cmp < 0)
		return RIGHT;
	if (cmp > 0)
		return LEFT;
	return SAME;
}

int			ft_tree_add(t_tree *arri, char *key, char *value)
{
	int		cmp;

	cmp = ft_cmp(arri->key, key);
	if (cmp == LEFT)
	{
		if (arri->left == NULL)
		{
			if (ft_tree_new(&(arri->left), key, value) == ERROR)
				return ERROR;
		}
		else
			return ft_tree_add(arri->left, key, value);
	}
	else if (cmp == RIGHT)
	{
		if (arri->right == NULL)
		{
			if (ft_tree_new(&(arri->right), key, value) == ERROR)
				return ERROR;
		}
		else
			return ft_tree_add(arri->right, key, value);
	}
	else if (cmp == SAME)
	{
		printf("same\n");/////////////////
	}
	return SUCCESS;
}

char		*ft_tree_get(t_tree *arri, char *key)
{
	int		cmp;

	if (arri == NULL)
		return NULL;
	cmp = ft_cmp(arri->key, key);
	if (cmp == SAME)
		return arri->key;////////////////
	else if (cmp == LEFT)
		return ft_tree_get(arri->left, key);
	else if (cmp == RIGHT)
		return ft_tree_get(arri->right, key);
	return NULL;
}

int 		ft_ft()
{
	char	*str[] = {"seksek", "serge", "goinfre", "ugo", "man", "billy", "emarin", "sous merde", "negro", "(terpri)", "gilles", "jhubert", "zouave", "dechet", "ohemecoin", "barachet", "gamouche", "arr", 0};
	t_tree	*(arr[SIZE_ARR]);
	int		i;
	int		index = 0;

	arr[0] = NULL;
	i = -1;
	while (str[++i])
	{
		if (arr[index] == NULL)
		{
			if (ft_tree_new(&(arr[index]), str[i], "value") == ERROR)
				return ERROR;
		}
		else
		{
			if (ft_tree_add(arr[index], str[i], "value") == ERROR)
				return ERROR;
		}
	}
	printf("%s\n", ft_tree_get(arr[0], str[9]));
	return SUCCESS;
}

int			main(int ac, char **av)
{
	(void)ac;
	(void)av;
	if (ft_ft() == ERROR)
	{
		printf("ERROR\n");
		return ERROR;
	}
	return (0);
}
