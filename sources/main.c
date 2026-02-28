/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 10:54:44 by tjooris           #+#    #+#             */
/*   Updated: 2026/02/28 20:42:42 by abetemps         ###   ########.fr       */
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

void	search_mode(t_buff *input, t_vector *map)
{
	char	*key = input->valid_line;
	const char	*value = search(map, key);

	if (!value)
	{
		key[ft_strlen(key) - 1] = '\0';
		write(STDERR_FILENO, key, ft_strlen(key));
		write(STDERR_FILENO, ": Not found.\n", ft_strlen(": Not found.\n"));
	}
	else
		write(STDOUT_FILENO, value, ft_strlen(value));
}

void	data_mode(t_buff *input, t_vector *map)
{
	// char	*key = input->valid_line;
	char	*key = ft_strndup(input->valid_line, ft_strlen(input->valid_line));
	// ft_freestr(input->valid_line);

	get_next_line(input);
	insert(map, key, input->valid_line);
}

int main(void)
{
	void			(*f_modes[MODE_QTY])(t_buff *, t_vector *);
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
	get_next_line(&input);
	while (input.valid_line)
	{
		line = input.valid_line;
		if (!ft_strcmp(line, "exit!\n")) // DEBUG
			break;
		if (line[0] == '\n' && line[1] == '\0')
			switch_mode(&mode);
		else
			f_modes[mode](&input, map);
		get_next_line(&input);
	}
	ft_clear_struct(&input);
	clear_vector(&map);
	return (0);
}
