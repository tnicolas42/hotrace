/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 21:59:43 by tnicolas          #+#    #+#             */
/*   Updated: 2018/05/12 19:14:17 by pmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

# include <stdlib.h>
# include <unistd.h>

# define SIZE_ARR (1 << 17)

# define SUCCESS 0
# define ERROR 1

# define LEFT 0
# define RIGHT 1
# define SAME 2

# define BUFF_SIZE (1 << 27)

typedef struct		s_tree
{
	char			*key;
	char			*value;

	int				len_key;
	int				len_value;

	struct s_tree	*left;
	struct s_tree	*right;
}					t_tree;

typedef struct		s_a
{
	t_tree			**arr;
	char			*str;
}					t_a;

void				ft_bzero(void *s, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_read_fd(int fd, char **file_content);
void				*ft_realloc(void *ptr, size_t original_size,
															size_t new_size);
char				*ft_strncat(char *dest, const char *src, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_len(char *s, char c);

int					ft_parse(t_a *a);
int					ft_init(t_a *a);
int					ft_hash(t_a *a, int start);
int					ft_add_key(t_a *a, t_tree *new, int index);
int					ft_tree_new(t_tree **arri, t_tree *new);
int					ft_cmp(char *s1, char *s2, int size1, int size2);
int					ft_tree_add(t_tree *arri, t_tree *new);
t_tree				*ft_tree_get(t_tree *arri, char *key, int len_key);
uint32_t			super_fast_hash(const char *data, int len);
int					ft_free(t_a *a);

#endif
