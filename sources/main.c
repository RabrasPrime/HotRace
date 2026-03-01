/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 10:54:44 by tjooris           #+#    #+#             */
/*   Updated: 2026/03/01 12:35:29 by tjooris          ###   ########.fr       */ /*                                                                            */
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

void search_mode(char *input, t_vector *map)
{
    const char *value = search(map, input);
	char *tmp;

	tmp = input;
    if (!value)
    {
        tmp[ft_strlen(tmp) - 1] = '\0';
        write(STDOUT_FILENO, tmp, ft_strlen(tmp));
        write(STDOUT_FILENO, ": Not found.\n", 13);
    }
    else
        write(STDOUT_FILENO, value, ft_strlen(value));
}

void data_mode(char *input, t_vector *map)
{
    char *key = input;
    char * value = get_next_line();
    insert(map, key, value);
}

int main(void)
{
	void			(*f_modes[MODE_QTY])(char *, t_vector *);
	char			*input;
	t_vector		*map;
	unsigned char	mode;

	f_modes[DATA]= &data_mode;
	f_modes[SEARCH]= &search_mode;
	map = create_vector(DEFAULT_VEC_CAP, sizeof(t_vector *), &clear_bucket);
	if (!map)
		return (1);
	mode = DATA;
	input = get_next_line();
	while (input)
	{
        if (!ft_strcmp(input, "exit!\n"))
            break;
        if (input[0] == '\n' && input[1] == '\0')
        {
            ft_freestr(&input);
            switch_mode(&mode);
        }
        else
            f_modes[mode](input, map);
        input = get_next_line();
	}
	clear_vector(&map);
	return (0);
}
