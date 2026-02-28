/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 12:20:18 by abetemps          #+#    #+#             */
/*   Updated: 2026/02/28 12:28:37 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

#include <unistd.h>

size_t	read_input(char *buf)
{
	size_t	rv;

	rv = read(STDIN_FILENO, buf, BUFFER_SIZE);
	buf[rv] = '\0';
	return (rv);
}
