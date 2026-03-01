/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 15:01:19 by abetemps          #+#    #+#             */
/*   Updated: 2026/03/01 15:01:55 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memchr(const void *memoryBlock, int searchedChar, size_t size)
{
	while (size > 0)
	{
		if (*(unsigned char *)memoryBlock == (unsigned char)searchedChar)
			return ((void *)memoryBlock);
		memoryBlock++;
		size--;
	}
	return (0);
}
