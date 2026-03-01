/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 15:00:23 by abetemps          #+#    #+#             */
/*   Updated: 2026/03/01 15:00:37 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	uint8_t			*ptr;

	i = 0;
	ptr = (uint8_t *) dest;
	if (src >= dest)
		while (i < n)
			ptr[i++] = (*(uint8_t *) src++);
	else
		while (n-- > 0)
			ptr[n] = (*(uint8_t *)(src + n));
	return (dest);
}
