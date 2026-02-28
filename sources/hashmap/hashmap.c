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

int	hash_function(const size_t capacity, char *key)
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
		sum = ((sum % capacity) + key[i]) % capacity;
		factor = ((factor % __INT16_MAX__) * (31 % __INT16_MAX__)) % __INT16_MAX__;
		++i;
	}
	bucket_index = sum;
	// printf("index: %d\n", sum);
	return (bucket_index);
}

int    insert(t_vector *vmap, char *key, char *value)
{
	int		bucket_index;
	t_node	*new_node;
	t_node	**map;

	map = (t_node **) vmap->array;
	new_node = ft_calloc(1, sizeof(t_node));
	if (!new_node)
    {
		write(STDERR_FILENO, "Error: Memory allocation failed.\n", 32);
        return (-1);
    }
	set_node(new_node, key, value);
	bucket_index = hash_function(vmap->capacity, key);
	if (map[bucket_index] == NULL)
	{
		if (!grow_vector(vmap, 1))
		{
			write(STDERR_FILENO, "Error: Memory allocation failed.\n", 32);
			return (-1);
		}
		map[bucket_index] = new_node;
		vmap->occupied_bytes += vmap->datatype_size;
		++vmap->nb_elements;
	}
	else
	{
		new_node->next = map[bucket_index];
		map[bucket_index] = new_node;
	}
	return (0);
}

char    *search(t_vector *map, char *key)
{
	const int	index = hash_function(map->capacity, key);
	t_node		*n = ((t_node **)map->array)[index];

	if (n)
		return (n->value);
	else
		return (NULL);
		
}

