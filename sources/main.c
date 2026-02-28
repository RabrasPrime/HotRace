/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 10:54:44 by tjooris           #+#    #+#             */
/*   Updated: 2026/02/28 20:10:29 by abetemps         ###   ########.fr       */
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
		printf("====DATA MODE====\n");
		*mode = DATA;
	}
	else
	{
		printf("====SEARCH MODE====\n");
		*mode = SEARCH;
	}
}

void	search_mode(char *input, t_vector *map)
{
	const char	*value = search(map, input);

	if (!value)
	{
		input[strlen(input) - 1] = '\0';
		write(STDERR_FILENO, input, strlen(input));
		write(STDERR_FILENO, ": Not found.\n", strlen(": Not found.\n"));
	}
	else
		write(STDOUT_FILENO, value, strlen(value));
}

void	data_mode(char *key, t_vector *map)
{
	t_buff	tmp;

	get_next_line(&tmp);
	insert(map, key, tmp.valid_line);
}

int main(void)
{
	void			(*f_modes[MODE_QTY])(char *, t_vector *);
	t_buff			input;
	t_vector		*map;
	char			*line;
	unsigned char	mode;

	f_modes[DATA]= &data_mode;
	f_modes[SEARCH]= &search_mode;
	map = create_vector(DEFAULT_VEC_CAP, sizeof(t_vector *), &clear_bucket);
	if (!map)
		return (1);
	mode = DATA;
	input.read_value = 1;
	while (input.read_value)
	{
		get_next_line(&input);
		line = input.valid_line;
		if (!ft_strcmp(line, "exit!\n")) // DEBUG
			break;
		if (line[0] == '\n' && line[1] == '\0')
			switch_mode(&mode);
		else
			f_modes[mode](line, map);
	}
	clear_vector(&map);
	return (0);
}
