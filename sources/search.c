/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 12:05:10 by abetemps          #+#    #+#             */
/*   Updated: 2026/02/28 14:23:16 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

#include <unistd.h>

char 	*search(t_hashmap *map, char *key)
{
	static int	i;
	(void) map;
	(void) key;
	
	if (i)
	{
		i = 0;
		return ("Found value\n");
	}
	else
	{
		i = 1;
		return (NULL);
	}

}
