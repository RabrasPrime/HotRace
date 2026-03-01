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

void *ft_memmove(void *dest, const void *src, size_t n)
{
	if (n == 0 || dest == src)
		return dest;

	__asm__ volatile (
		"xorq    %%rax, %%rax           \n\t"
		"1:                             \n\t"
		"cmpq    %%rax, %[n]            \n\t"
		"je      2f                     \n\t"
		"movb    (%[src],%%rax), %%cl   \n\t"
		"movb    %%cl, (%[dest],%%rax)  \n\t"
		"incq    %%rax                  \n\t"
		"jmp     1b                     \n\t"
		"2:                             \n\t"
		:
		: [dest] "r" (dest), [src] "r" (src), [n] "r" (n)
		: "cc", "memory", "rax", "cl"
	);

	return dest;
}
