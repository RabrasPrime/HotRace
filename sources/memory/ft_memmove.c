/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 15:00:23 by abetemps          #+#    #+#             */
/*   Updated: 2026/03/01 18:52:38 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const uint8_t	*s = (const uint8_t *)src;
	uint8_t			*d;
	size_t			i;

	d = (uint8_t *)dest;
	if (n == 0 || dest == src)
		return (dest);
	if (n < 8)
	{
		if (s >= (uint8_t *)dest)
		{
			i = 0;
			while (i < n)
			{
				d[i] = s[i];
				i++;
			}
		}
		else
			while (n--)
				d[n] = s[n];
		return (dest);
	}
	__asm__ volatile (
		"rep movsb"
		: "+D" (d), "+S" (s), "+c" (n)
		:
		: "memory"
	);
	return (dest);
}
