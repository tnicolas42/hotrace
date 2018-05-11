/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 21:59:43 by tnicolas          #+#    #+#             */
/*   Updated: 2018/05/11 21:59:43 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

# include <stdio.h>///////////
# include <stdlib.h>
# include <string.h>/////////////

# define SIZE_ARR 1

# define SUCCESS 0
# define ERROR 1

# define LEFT 0
# define RIGHT 1
# define SAME 2

typedef struct		s_tree
{
	char			*key;
	char			*value;

	struct s_tree	*left;
	struct s_tree	*right;
}					t_tree;

#endif
