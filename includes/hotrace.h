/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 11:00:21 by tjooris           #+#    #+#             */
/*   Updated: 2026/02/28 17:02:05 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
#define HOTRACE_H

#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>
#include <stdint.h>
#include <stdbool.h>

#include <stdio.h> // owjhlkfhklshhgshghdgh

#define BUFFER_SIZE	4096

#define TRUE	1
#define FALSE	0

enum	e_modes
{
	DATA,
	SEARCH,
	MODE_QTY
};

typedef struct s_vector t_vector;
typedef struct s_node t_node;

struct					s_vector
{
	void				*array;
	size_t				datatype_size;
	size_t				capacity;
	size_t				nb_elements;
	size_t				occupied_bytes;
	void				(*clear_array)(t_vector *vec);
};

struct s_node
{
	char			*key;
	char			*value;
	t_node			*next;
};

void		set_node(t_node *node, char *key, char *value);
void		clear_bucket(t_vector *map);
int			init_vector(t_vector *hashmap);

void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);
void		*ft_memcpy(void *dest, const void *src, size_t n);

size_t		read_input(char *buf);
char 		*search(t_vector *map, char *key);
int   		insert(t_vector *map, char *key, char *value);

t_vector	*create_vector(size_t capacity, size_t datatype_size,
							void (*clear_array)(t_vector *));
bool		grow_vector(t_vector *vec, size_t new_elements);
bool		add_element(t_vector *vec, void *element, ssize_t index);
void		clear_vector(t_vector **vec);

#endif
