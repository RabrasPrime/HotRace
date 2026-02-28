/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 11:59:32 by tjooris           #+#    #+#             */
/*   Updated: 2026/02/28 19:06:52 by abetemps         ###   ########.fr       */
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
	while (i < key_length)
	{
		sum = ((sum % capacity) + key[i]) % capacity;
		factor = ((factor % __INT16_MAX__) * (31 % __INT16_MAX__)) % __INT16_MAX__;
		++i;
	}
	bucket_index = sum;
	return (bucket_index);
}

int    insert(t_vector *vmap, char *key, char *value)
{
	int			bucket_index;
	t_node		new_node;
	t_vector	**map;

	map = (t_vector **) vmap->array;
	set_node(&new_node, key, value);
	bucket_index = hash_function(vmap->capacity, key);
	if (map[bucket_index] == NULL)
	{
		if (!grow_vector(vmap, 1))
		{
			write(STDERR_FILENO, "Error: Memory allocation failed.\n", 32);
			return (-1);
		}
		map[bucket_index] = create_vector(BUFFER_SIZE, sizeof(t_node), &clear_node);
		if (!map[bucket_index])
		{
			write(STDERR_FILENO, "Error: Memory allocation failed.\n", 32);
			return (-1);
		}
		vmap->occupied_bytes += vmap->datatype_size;
		++vmap->nb_elements;
	}
	if (!add_element(map[bucket_index], &new_node))
	{
		write(STDERR_FILENO, "Error: Memory allocation failed.\n", 32);
		return (-1);
	}
	return (0);
}

char    *search(t_vector *map, char *key)
{
	const int	index = hash_function(map->capacity, key);
	t_vector	*entry;
	t_node		*n;
	size_t		i;

	i = 0;
	entry = ((t_vector **)map->array)[index];
	n = (t_node *) entry->array;
	while (i < entry->capacity)
	{
		if (!ft_strcmp(key, n[i].key))
			return (n[i].value);
		++i;
	}
	return (NULL);
}
