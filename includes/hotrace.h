/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 11:00:21 by tjooris           #+#    #+#             */
/*   Updated: 2026/02/28 14:19:20 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
#define HOTRACE_H

#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>

#define BUFFER_SIZE	10

#define TRUE	1
#define FALSE	0

enum	e_modes
{
	DATA,
	SEARCH,
	MODE_QTY
};

typedef struct s_node
{
	char			*key;
	char			*value;
	struct s_node	*next;
}	t_node;

typedef struct s_hashmap
{
	t_node	**bucket;
	int		size;
	int		capacity;
}	t_hashmap;

void	set_node(t_node *node, char *key, char *value);

void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);

void	read_input(char *buf);
char 	*search(t_hashmap *map, char *key);
int   	insert(t_hashmap *map, char *key, char *value);

#endif
