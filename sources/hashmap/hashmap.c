/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 11:59:32 by tjooris           #+#    #+#             */
/*   Updated: 2026/02/28 14:34:55 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

int	init_hashmap(t_hashmap *hashmap)
{
    hashmap->size = 0;
    hashmap->capacity = 4096;
    hashmap->bucket = ft_calloc(hashmap->capacity, sizeof(t_node *));
	if (!hashmap->bucket)
	{
		write(STDERR_FILENO, "Error: Memory allocation failed for hashmap buckets.\n", 53);
        return (-1);
	}
    return (0);
}

# include <stdio.h>
int	hash_function(t_hashmap	*map, char *key)
{
	int	bucket_index;
	int	i;
	int	key_length;
	int	sum;
	int	factor;

	i = 0;
	sum = 0;
	key_length = strlen(key);
	// printf("key_length: %d\n", key_length);
	while (i < key_length)
	{
		sum = ((sum % map->capacity) + key[i]) % map->capacity;
		factor = ((factor % __INT16_MAX__) * (31 % __INT16_MAX__)) % __INT16_MAX__;
		++i;
	}
	bucket_index = sum;
	// printf("index: %d\n", sum);
	return (bucket_index);
}

int    insert(t_hashmap *map, char *key, char *value)
{
	int		bucket_index;
	t_node	*new_node;

	new_node = ft_calloc(1, sizeof(t_node));
	if (!new_node)
    {
		write(STDERR_FILENO, "Error: Memory allocation failed for new node.\n", 45);
        return (-1);
    }
	set_node(new_node, key, value);
	bucket_index = hash_function(map, key);
	if (map->bucket[bucket_index] == NULL)
    {
        map->bucket[bucket_index] = new_node;
    }
    else
    {
    	new_node->next = map->bucket[bucket_index];
        map->bucket[bucket_index] = new_node;
    }
	++map->size;
	return (0);
}

char    *search(t_hashmap *map, char *key)
{
	const int	index = hash_function(map, key);
	t_node		*n = map->bucket[index];

	if (n)
		return (n->value);
	else
		return (NULL);
		
}

