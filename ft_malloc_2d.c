/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_2d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonroe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 22:05:16 by smonroe           #+#    #+#             */
/*   Updated: 2018/04/21 12:40:27 by smonroe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_malloc_2d(size_t col, size_t row)
{
	char **array;

	if (!(array = (char **)malloc(sizeof(char *) * col)))
		return (NULL);
	while (col > 0)
	{
		if (!(array[col--] = (char *)malloc(sizeof(char) * row)))
			return (NULL);
		ft_bzero(array[col], row);
	}
	return (array);
}
