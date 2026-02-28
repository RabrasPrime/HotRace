/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 11:00:21 by tjooris           #+#    #+#             */
/*   Updated: 2026/02/28 14:30:13 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
#define HOTRACE_H

#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>
#define TRUE 1
#define FALSE 0
#define BUFFER_SIZE 10

typedef struct s_node
{
	char			*key;
	char			*value;
	struct s_node	*next;
}	t_node;

typedef struct s_hashmap
{
	t_node	**bucket;
	int size;
	int	capacity;
}	t_hashmap;

void	set_node(t_node *node, char *key, char *value);

void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);

void	read_input(char *buf);
char 	*search(char *key);
void	insert(t_node *node);

#endif
