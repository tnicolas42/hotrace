/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <tnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 22:02:34 by tnicolas          #+#    #+#             */
/*   Updated: 2018/05/12 19:15:00 by pmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | main.c                                                   |
**   |     ft_add_key(11 lines)                                 |
**   |     ft_len(6 lines)                                      |
**   |     ft_init(5 lines)                                     |
**   |     main(11 lines)                                       |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <hotrace.h>

int			main(void)
{
	t_a		a;

	if (ft_init(&a) == ERROR)
		return (EXIT_FAILURE);
	if (ft_read_fd(STDIN_FILENO, &(a.str)) == 0)
		return (EXIT_FAILURE);
	if (ft_parse(&a) == ERROR)
		return (EXIT_FAILURE);
	if (ft_free(&a) == ERROR)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
