/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 11:59:32 by tjooris           #+#    #+#             */
/*   Updated: 2026/03/01 19:27:20 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

int	hash1(const size_t capacity, const char *key)
{
	const unsigned char	*s = (const unsigned char *)key;
	unsigned int		sum;
	size_t				i;

	sum = 0;
	i = 0;
	__asm__ volatile (
		"movl $0, %%edx		\n\t"
		"1:					\n\t"
		"movb (%[str],%[i]), %%cl \n\t"
		"testb %%cl, %%cl	  \n\t"
		"jz 2f				 \n\t"
		"shll $5, %[sum]	   \n\t"
		"shrl $2, %%edx		\n\t"
		"addl %%ecx, %%edx	 \n\t"
		"xorl %%edx, %[sum]	\n\t"
		"incq %[i]			 \n\t"
		"jmp 1b				\n\t"
		"2:					\n\t"
		: [sum] "+r"(sum), [i] "+r"(i)
		: [str] "r"(s)
		: "cc", "memory", "ecx", "edx");
	return ((int)(sum & (capacity - 1)));
}

int	hash2(const size_t capacity, const char *key, int hash1)
{
	const unsigned char	*s = (const unsigned char *)key;
	unsigned int		sum;
	size_t				i;

	sum = (unsigned int) hash1;
	i = 0;
	__asm__ volatile (
		"movl $5381, %%edx	\n\t"
		"1:	\n\t"
		"movb (%[str],%[i]), %%cl \n\t"
		"testb %%cl, %%cl      \n\t"
		"jz 2f                 \n\t"
		"imull $33, %%edx, %%edx \n\t"
		"addl %%ecx, %%edx     \n\t"
		"xorl %[seed], %%edx   \n\t"
		"movl %%edx, %%eax     \n\t"
		"incq %[i]             \n\t"
		"jmp 1b                \n\t"
		"2:                    \n\t"
		"movl %%eax, %[sum]    \n\t"
		: [sum] "+r"(sum), [i] "+r"(i)
		: [str] "r"(s), [seed] "r"(hash1)
		: "cc", "memory", "ecx", "edx", "eax");
	return ((int)(sum & (capacity - 1)));
}

int	insert(t_vector *vmap, char *key, char *value)
{
	t_vector	**map;
	t_node		*nodemap;
	int			bucket_index;
	int			node_index;

	map = (t_vector **)vmap->array;
	bucket_index = hash1(vmap->capacity, key);
	if (!map[bucket_index])
	{
		map[bucket_index] = create_vector(DEFAULT_VEC_CAP, sizeof(t_node),
				&clear_node);
		if (!map[bucket_index])
		{
			write(STDERR_FILENO, "Error: Memory allocation failed.\n", 32);
			return (-1);
		}
		vmap->occupied_bytes += vmap->datatype_size;
		++vmap->nb_elements;
	}
	nodemap = (t_node *)map[bucket_index]->array;
	node_index = hash2(map[bucket_index]->capacity, key, bucket_index);
	if (nodemap[node_index].key)
	{
		free(nodemap[node_index].key);
		free(nodemap[node_index].value);
	}
	else
	{
		map[bucket_index]->occupied_bytes += map[bucket_index]->datatype_size;
		++map[bucket_index]->nb_elements;
	}
	nodemap[node_index].key = key;
	nodemap[node_index].value = value;
	return (0);
}

char	*search(t_vector *map, char *key)
{
	const int	entry_index = hash1(map->capacity, key);
	t_vector	*entry;
	int			sub_index;

	entry = ((t_vector **)map->array)[entry_index];
	if (!entry)
		return (NULL);
	sub_index = hash2(entry->capacity, key, entry_index);
	return (((t_node *)entry->array)[sub_index].value);
}
