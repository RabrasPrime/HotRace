/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 11:59:32 by tjooris           #+#    #+#             */
/*   Updated: 2026/02/28 20:40:08 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

int	hash_function(const size_t capacity, const char *key)
{
	const unsigned char *s = (const unsigned char *)key;
	unsigned int sum = 0;
	size_t i = 0;

	__asm__ volatile (
		"1:                             \n\t"
		"movb    (%[str],%[i]), %%cl    \n\t"
		"testb   %%cl, %%cl             \n\t"
		"jz      2f                     \n\t"
		"shll    $5, %[sum]             \n\t"
		"shrl    $2, %%edx              \n\t"
		"addl    %%ecx, %%edx           \n\t"
		"xorl    %%edx, %[sum]          \n\t"
		"incq    %[i]                   \n\t"
		"jmp     1b                     \n\t"
		"2:                             \n\t"
		: [sum] "+r" (sum), [i] "+r" (i)
		: [str] "r" (s)
		: "cc", "memory", "ecx", "edx"
	);

	return (int)(sum & (capacity - 1));
}

int rev_hash_function(const size_t capacity, const char *key)
{
	const unsigned char *s = (const unsigned char *)key;
	unsigned int sum = 0U;
	size_t i = ft_strlen(key);

	if (i == 0)
		return (0);
	i--;

	__asm__ volatile (
		"1:                             \n\t"
		"movb    (%[str],%[i]), %%cl    \n\t"
		"shll    $3, %[sum]             \n\t"
		"shrl    $4, %%edx              \n\t"
		"xorl    %%ecx, %%edx           \n\t"
		"xorl    %%edx, %[sum]          \n\t"
		"testq   %[i], %[i]             \n\t"
		"je      2f                     \n\t"
		"decq    %[i]                   \n\t"
		"jmp     1b                     \n\t"
		"2:                             \n\t"
		: [sum] "+r" (sum), [i] "+r" (i)
		: [str] "r" (s)
		: "cc", "memory", "ecx", "edx"
	);

	return (int)(sum & (capacity - 1));
}

// int	rev_hash_function(const size_t capacity, const char *key)
// {
// 	int				bucket_index;
// 	size_t			i;
// 	int				sum;
// 	int				factor;
//
// 	sum = 0;
// 	i = ft_strlen(key) - 1;
// 	while (i > 0)
// 	{
// 		sum = ((sum % capacity) + key[i]) % capacity;
// 		factor = ((factor % __INT16_MAX__) * (31 % __INT16_MAX__)) % __INT16_MAX__;
// 		--i;
// 	}
// 	bucket_index = sum;
// 	return (bucket_index);
// }
//
// int	hash_function(const size_t capacity, const char *key)
// {
// 	const size_t	key_length = ft_strlen(key);
// 	int	bucket_index;
// 	size_t	i;
// 	int	sum;
// 	int	factor;
//
// 	i = 0;
// 	sum = 0;
// 	while (i < key_length)
// 	{
// 		sum = ((sum % capacity) + key[i]) % capacity;
// 		factor = ((factor % __INT16_MAX__) * (31 % __INT16_MAX__)) % __INT16_MAX__;
// 		++i;
// 	}
// 	bucket_index = sum;
// 	return (bucket_index);
// }

int    insert(t_vector *vmap, char *key, char *value)
{
	int			bucket_index;
	int			node_index;
	t_node		*nodemap;
	t_vector	**map;

	if (!grow_vector(vmap))
	{
		write(STDERR_FILENO, "Error: Memory allocation failed.\n", 32);
		return (-1);
	}

	map = (t_vector **) vmap->array;
	bucket_index = hash_function(vmap->capacity, key);

	if (!map[bucket_index])
	{
		map[bucket_index] = create_vector(DEFAULT_VEC_CAP, sizeof(t_node), &clear_node);
		if (!map[bucket_index])
		{
			write(STDERR_FILENO, "Error: Memory allocation failed.\n", 32);
			return (-1);
		}
		vmap->occupied_bytes += vmap->datatype_size;
		++vmap->nb_elements;
	}

	if (!grow_vector(map[bucket_index]))
	{
		write(STDERR_FILENO, "Error: Memory allocation failed.\n", 32);
		return (-1);
	}

	nodemap = (t_node *) map[bucket_index]->array;
	node_index = rev_hash_function(map[bucket_index]->capacity, key);

	nodemap[node_index].key = key;
	nodemap[node_index].value = value;

	map[bucket_index]->occupied_bytes += map[bucket_index]->datatype_size;
	++map[bucket_index]->nb_elements;
	
	return (0);
}

char    *search(t_vector *map, char *key)
{
	const int	entry_index = hash_function(map->capacity, key);
	const int	sub_index = rev_hash_function(map->capacity, key);
	t_vector	*entry;
	size_t		i;

	i = 0;
	entry = ((t_vector **)map->array)[entry_index];
	if (!entry)
		return (NULL);
	return (((t_node *) entry->array)[sub_index].value);
}
