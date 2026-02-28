/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 11:00:21 by tjooris           #+#    #+#             */
/*   Updated: 2026/02/28 11:28:22 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
#define HOTRACE_H

#define TRUE 1
#define FALSE 0
#define BUFFER_SIZE 10

typedef struct s_entry
{
	char			*key;
	char			*value;
	struct s_entry	*next;
}	t_entry;

void	read_input(char *buf);
char 	*search(char *key);
void	insert(t_entry *node);

#endif
