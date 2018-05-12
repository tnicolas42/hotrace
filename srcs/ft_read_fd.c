/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 09:43:42 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/08 17:41:26 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_read_fd.c                                             |
**   |     ft_read_fd(14 lines)                                 |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

# include <hotrace.h>

int			ft_read_fd(int fd, char **file_content)
{
	char	buf[BUFF_SIZE + 1];
	int		ret_read;
	int		sz_file;

	sz_file = 0;
	if (!(*file_content = malloc(sizeof(**file_content))))
		return (0);
	(*file_content)[0] = '\0';
	while ((ret_read = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret_read] = '\0';
		*file_content = ft_realloc(*file_content, sz_file + 1,
				sz_file + ret_read + 1);
		sz_file += ret_read;
		ft_strncat(*file_content, buf, ret_read);
	}
	if (ret_read < 0)
		return (0);
	return (sz_file);
}
