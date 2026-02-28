/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 10:54:44 by tjooris           #+#    #+#             */
/*   Updated: 2026/02/28 14:36:54 by abetemps         ###   ########.fr       */
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

void	switch_mode(unsigned char *mode)
{
	if (*mode & SEARCH)
	{
		// printf("SEARCH->DATA\n");
		*mode = DATA;
	}
	else
	{
		// printf("DATA->SEARCH\n");
		*mode = SEARCH;
	}
}

void	search_mode(char *input, t_vector *map, size_t *rv)
{
	(void)rv;
	char	*value = search(map, input); // returns value
	if (!value)
	{
		input[strlen(input) - 1] = '\0';
		write(STDERR_FILENO, input, strlen(input));
		write(STDERR_FILENO, ": Not found.\n", strlen(": Not found.\n"));
	}
	else
		write(STDOUT_FILENO, value, strlen(value));
}

void	data_mode(char *input, t_vector *map, size_t *rv)
{
	char value[BUFFER_SIZE + 1];

	*rv = read_input(value);		// read value
	insert(map, input, value);		// insert node
}

int main(void)
{
	void			(*f_modes[MODE_QTY])(char *, t_vector *, size_t *);
	t_vector		*map;
	char			input[BUFFER_SIZE + 1];
	unsigned char	mode;
	size_t			rv;

	f_modes[DATA]= &data_mode;
	f_modes[SEARCH]= &search_mode;
	map = create_vector(BUFFER_SIZE, sizeof(t_node *), &clear_bucket);
	mode = DATA;
	
	rv = 1;
	while (rv)
	{
		rv = read_input(input);
		if (input[0] == '\n' && input[1] == '\0')
			switch_mode(&mode);
		else
			f_modes[mode](input, map, &rv);
	}
	clear_vector(&map);
	return (0);
}
