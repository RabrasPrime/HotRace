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

