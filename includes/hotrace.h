/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 11:00:21 by tjooris           #+#    #+#             */
/*   Updated: 2026/03/01 15:03:18 by abetemps         ###   ########.fr       */
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

#define BUFFER_SIZE		4096
#define DEFAULT_VEC_CAP	1024

#define LOMAGIC 0x0101010101010101ULL 
#define HIMAGIC 0x8080808080808080ULL 

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
typedef struct s_buff t_buff;

struct s_buff
{
	char	*data;
	size_t	length;
	size_t	capacity;
};

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
};

void		set_node(t_node *node, char *key, char *value);
void 		clear_node(t_vector *vnodes);
void		clear_bucket(t_vector *map);
int			init_vector(t_vector *hashmap);

void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memchr(const void *memoryBlock, int searchedChar, size_t size);

int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strndup(char *s, size_t n);
uint64_t	ft_strlen(const char *s);
void		ft_freestr(char **s);

char 		*search(t_vector *map, char *key);
int   		insert(t_vector *map, char *key, char *value);

t_vector	*create_vector(size_t capacity, size_t datatype_size,
							void (*clear_array)(t_vector *));
bool		grow_vector(t_vector *vec);
bool		add_element(t_vector *vec, void *element);
void		clear_vector(t_vector **vec);

char		*get_next_line(void);

#endif
