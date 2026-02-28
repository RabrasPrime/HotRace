/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 10:54:44 by tjooris           #+#    #+#             */
/*   Updated: 2026/02/28 11:39:15 by tjooris          ###   ########.fr       */
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

int main(void)
{
	char	input[BUFFER_SIZE];

	while (TRUE)
	{
		read_input(input);
		if (input[0] == '\n' && input[1] == '\0')
		{
			read_input(input);
			char	*value = search(input); // returns value
			if (!value)
			{
				input[strlen(input) - 1] = '\0';
				write(STDERR_FILENO, input, strlen(input));
				write(STDERR_FILENO, ": Not found.\n", strlen(": Not found.\n"));
				continue;
			}
			else
				write(STDOUT_FILENO, value, strlen(value));
		}
		else
		{
			t_entry node = {input, NULL, NULL}; // where input == value
			read_input(input);	// read value
			node.value = input;
			insert(&node);		// insert node
			write(STDOUT_FILENO, "Key + Value registered\n", strlen("Key + Value registered\n"));
		}
	}
	return (0);
}
