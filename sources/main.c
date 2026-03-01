/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 10:54:44 by tjooris           #+#    #+#             */
/*   Updated: 2026/03/01 19:03:22 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

#include <string.h>
#include <unistd.h>

// - read
// - write
// - malloc
// - free
// - strerror
// - The compiler directive: __asm__

#include <stdio.h>

static inline void	switch_mode(unsigned char *mode)
{
	if (*mode & SEARCH)
		*mode = DATA;
	else
		*mode = SEARCH;
}

static inline void	search_mode(char *input, t_vector *map)
{
	const char		*key = input;
	const char		*value = search(map, input);
	const size_t	klen = ft_strlen(key);

	if (!value)
	{
		write(STDOUT_FILENO, key, klen - 2);
		write(STDOUT_FILENO, ": Not found.\n", 13);
	}
	else
		write(STDOUT_FILENO, value, ft_strlen(value));
}

static inline int	data_mode(char *input, t_vector *map)
{
	return (insert(map, input, get_next_line()));
}

static inline int	main_loop(char *input, t_vector *map, unsigned char mode)
{
	while (input)
	{
		if (input[0] == '\n' && input[1] == '\0')
		{
			ft_freestr(&input);
			switch_mode(&mode);
		}
		else if (mode == DATA)
		{
			if (data_mode(input, map) == -1)
			{
				clear_vector(&map);
				return (1);
			}
		}
		else
		{
			search_mode(input, map);
			ft_freestr(&input);
		}
		input = get_next_line();
	}
	clear_vector(&map);
	return (0);
}

int	main(void)
{
	char			*input;
	t_vector		*map;
	unsigned char	mode;

	map = create_vector(DEFAULT_VEC_CAP, sizeof(t_vector *), &clear_bucket);
	if (!map)
		return (1);
	mode = DATA;
	input = get_next_line();
	return (main_loop(input, map, mode));
}
