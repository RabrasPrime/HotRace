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

size_t ft_strlen(const char *s)
{
    if (!s)
        return 0;

    size_t len;
    const char *start = s;

    __asm__ volatile (
        "cld                   \n\t"
        "repne scasb           \n\t"
        "not %%rcx             \n\t"
        "dec %%rcx             \n\t"
        : "=c" (len), "+D" (s)
        : "a" (0), "c" (-1)
        : "cc", "memory"
    );

    return (size_t)(s - start);
}
