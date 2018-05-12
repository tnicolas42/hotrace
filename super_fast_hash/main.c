/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarin <emarin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 11:39:22 by emarin            #+#    #+#             */
/*   Updated: 2018/05/12 12:11:34 by emarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int					main(void)
{
	printf("%x\n", super_fast_hash("fuck les rajeux", ugo_strlen("fuck les rajeux")) >> 16);
	printf("%x\n", super_fast_hash("fuck les rajeuy", ugo_strlen("fuck les rajeuy")) >> 16);
	printf("%x\n", super_fast_hash("fuCk les rajeux", ugo_strlen("fuCk les rajeux")) >> 16);
	printf("%x\n", super_fast_hash("fuCk les rajeux  ", ugo_strlen("fuCk les rajeux  ")) >> 16);
	printf("%x\n", super_fast_hash("a", ugo_strlen("a")) >> 16);
	printf("%x\n", super_fast_hash("f", ugo_strlen("f")) >> 16);
	printf("%x\n", super_fast_hash("aA", ugo_strlen("aA")) >> 16);
	printf("%x\n", super_fast_hash("tr", ugo_strlen("tr")) >> 16);
	printf("%x\n", super_fast_hash(" & $", ugo_strlen(" & $")) >> 16);
	printf("%x\n", super_fast_hash(" sac sa s", ugo_strlen(" sac sa s")) >> 16);
	printf("%x\n", super_fast_hash("0", ugo_strlen("0")) >> 16);
	printf("%x\n", super_fast_hash("1234567a", ugo_strlen("1234567a")) >> 16);
	printf("%x\n", super_fast_hash("1234567ac", ugo_strlen("1234567ac")) >> 16);

	return (0);
}
