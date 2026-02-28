/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 20:03:02 by abetemps          #+#    #+#             */
/*   Updated: 2026/02/28 20:14:10 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

static uint64_t	result(const char *start, const uint64_t *word_pointer)
{
	const char	*byte = (char *)(word_pointer - 1);
	int8_t		i;

	i = -1;
	while (++i < 8)
	{
		if (byte[i] ^ '\0')
			;
		else
			return (byte + i - start);
	}
	return (0);
}

uint64_t	ft_strlen(const char *s)
{
	const char		*start = s;
	const char		*p = s;
	uint64_t		*word_pointer;
	uint64_t		word;

	if (!s)
		return (0);
	while ((uintptr_t)p & 0b00000111)
	{
		if (*p ^ '\0')
			;
		else
			return (p - start);
		++p;
	}
	word_pointer = (uint64_t *)p;
	while (true)
	{
		word = *(word_pointer++);
		if ((word - LOMAGIC) & HIMAGIC)
			return (result(start, word_pointer));
	}
}
