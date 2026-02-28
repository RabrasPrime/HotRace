/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 11:59:32 by tjooris           #+#    #+#             */
/*   Updated: 2026/02/28 12:30:48 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

void	init_hashmap(t_hashmap *hashmap)
{
    hashmap->size = 0;
    hashmap->capacity = 1024;
    hashmap->bucket = ft_calloc(hashmap->capacity, sizeof(t_node *));
}

int	hash_function(t_hashmap	*hashmap, char *key)
{
	int	bucket_index;
	int	i;
	int	key_length;
	int	sum;
	int	factor;

	i = 0;
	key_length = strlen(key);
	while (i < key_length)
	{
		sum = ((sum % hashmap->capacity) + key[i]) % hashmap->capacity;
		factor = ((factor % __INT16_MAX__) * (31 % __INT16_MAX__)) % __INT16_MAX__;
		i++;
	}
	bucket_index = sum;
	return (bucket_index);
}