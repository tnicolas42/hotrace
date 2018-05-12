/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarin <emarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 11:39:25 by emarin            #+#    #+#             */
/*   Updated: 2018/05/12 12:11:24 by emarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

uint32_t	get16bits(const char *d)
{
	return ((((uint32_t)(((const uint8_t *)(d))[1])) << 8) +
	(uint32_t)(((const uint8_t *)(d))[0]));
}

void		end_cases(uint32_t *hash, int rem, const char *data)
{
	if (rem == 3)
	{
		*hash += get16bits(data);
		*hash ^= *hash << 16;
		*hash ^= ((signed char)(data)[sizeof(uint16_t)]) << 18;
		*hash += *hash >> 11;
	}
	else if (rem == 2)
	{
		*hash += get16bits(data);
		*hash ^= *hash << 11;
		*hash += *hash >> 17;
	}
	else if (rem == 1)
	{
		*hash += (signed char)*data;
		*hash ^= *hash << 10;
		*hash += *hash >> 1;
	}
}

uint32_t	super_fast_hash(const char *data, int len)
{
	uint32_t	hash;
	uint32_t	tmp;
	int			rem;

	hash = len;
	if (len <= 0 || data == NULL)
		return (0);
	rem = len & 3;
	len >>= 2;
	while (len-- > 0)
	{
		hash += get16bits(data);
		tmp = (get16bits(data + 2) << 11) ^ hash;
		hash = (hash << 16) ^ tmp;
		data += 2 * sizeof(uint16_t);
		hash += hash >> 11;
	}
	end_cases(&hash, rem, data);
	hash ^= hash << 3;
	hash += hash >> 5;
	hash ^= hash << 4;
	hash += hash >> 17;
	hash ^= hash << 25;
	hash += hash >> 6;
	return (hash);
}

int			ugo_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '\n')
		++i;
	return (i);
}
