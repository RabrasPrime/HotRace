/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 12:04:06 by tjooris           #+#    #+#             */
/*   Updated: 2026/02/28 19:09:13 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

#include <string.h>

void clear_node(t_vector *vnodes)
{
	t_node	*nodes;
	size_t	i;

	nodes = (t_node *) vnodes->array;
	i = 0;
	while (i < vnodes->capacity)
	{
		free(nodes[i].key);
		free(nodes[i].value);
		++i;
	}

}

void clear_bucket(t_vector *vmap)
{
	size_t		i;
	t_vector	**bucket;

	i = 0;
	bucket = (t_vector **) vmap->array;
	while(i < vmap->capacity)
	{
		if (bucket[i])
			clear_vector(&bucket[i]);
		++i;
	}
}
