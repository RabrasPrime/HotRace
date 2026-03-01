/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 17:01:50 by abetemps          #+#    #+#             */
/*   Updated: 2026/02/28 17:05:43 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <unistd.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	uint8_t			*ptr;

	i = 0;
	ptr = (uint8_t *) dest;
	while (i < n)
	{
		ptr[i] = (*(uint8_t *) src);
		++i;
		++src;
	}
	return (dest);
}
