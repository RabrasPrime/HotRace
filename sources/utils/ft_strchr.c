/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 20:01:33 by abetemps          #+#    #+#             */
/*   Updated: 2026/02/28 20:13:28 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

char	*ft_strchr(const char *s, int c)
{
	int	len;
	int	i;

	len = ft_strlen(s);
	if (!s || len == 0)
		return (NULL);
	i = 0;
	while (i <= len)
	{
		if (s[i] == (unsigned char)c)
			return ((char *)s + i);
		else
			i++;
	}
	return (NULL);
}
