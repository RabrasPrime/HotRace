/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grow_vector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 18:19:45 by abetemps          #+#    #+#             */
/*   Updated: 2026/03/01 18:05:09 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

bool	grow_vector(t_vector *vec)
{
	void	*old_array;

	if (vec->nb_elements + 1 > vec->capacity)
	{
		old_array = vec->array;
		while (vec->nb_elements + 1 > vec->capacity)
			vec->capacity <<= 1;
		vec->array = ft_calloc(vec->capacity, vec->datatype_size);
		if (!vec->array)
		{
			clear_vector(&vec);
			return (false);
		}
		ft_memcpy(vec->array, old_array, vec->nb_elements * vec->datatype_size);
		free(old_array);
	}
	return (true);
}
