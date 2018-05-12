/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmilan <pmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 19:35:43 by pmilan            #+#    #+#             */
/*   Updated: 2018/05/12 19:51:38 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | init.c                                                   |
**   |     ft_init(5 lines)                                     |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <hotrace.h>

int			ft_init(t_a *a)
{
	a->str = NULL;
	if (!(a->arr = malloc(sizeof(t_tree*) * SIZE_ARR)))
		return (ERROR);
	ft_bzero(a->arr, SIZE_ARR * sizeof(t_tree*));
	return (SUCCESS);
}
