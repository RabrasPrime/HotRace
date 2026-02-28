/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 12:04:06 by tjooris           #+#    #+#             */
/*   Updated: 2026/02/28 12:17:01 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

#include <string.h>

void	set_node(t_node *node, char *key, char *value)
{
	node->key = strdup(key);
	node->value = strdup(value);
	node->next = NULL;
}

void clear_node(t_node *n)
{
	free(n->key);
	free(n->value);
}

void clear_bucket(t_vector *vmap)
{
	size_t	i;
	t_node	**bucket;
	t_node	*map;

	i = 0;
	bucket = (t_node **) vmap->array;
	while(i < vmap->capacity)
	{
		map = bucket[i];
		while (map)
		{
			clear_node(map);
			map = map->next;
		}
	}
}
