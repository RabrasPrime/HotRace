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
			char	*value = search(input); // returns value
			write(STDOUT_FILENO, value, strlen(value));
		}
		else
		{
			t_entry node = {input, NULL, NULL};
			read_input(input);	// read value
			node.value = input;
			insert(&node);		// insert node
		}
	}

	return (0);
}
