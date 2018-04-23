/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonroe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 20:13:34 by smonroe           #+#    #+#             */
/*   Updated: 2018/04/23 02:37:53 by smonroe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_make_2d(char const *s, char **bloc, char c)
{
	int	i;
	int	w;
	int	l;

	i = 0;
	w = 0;
	while (s[i])
	{
		l = 0;
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
		{
			i++;
			l++;
		}
		if (l)
			if (!(bloc[w++] = (char *)malloc(sizeof(bloc) * l + 1)) && s[i])
				return (NULL);
	}
	if (!(bloc[w] = (char *)malloc(sizeof(bloc) * 2)))
		return (NULL);
	return (bloc);
}

char		**ft_strsplit(char const *s, char c)
{
	int		w;
	int		l;
	char	**bloc;

	if (!(s && c))
		return (NULL);
	if (!(bloc = (char **)malloc(sizeof(char) * (ft_strlen(s)))))
		return (NULL);
	if (!(bloc = ft_make_2d(s, bloc, c)))
		return (NULL);
	w = 0;
	while (*s)
	{
		l = 0;
		while (*s == c && *s)
			s += 1;
		while (*s != c && *s)
			bloc[w][l++] = *s++;
		if (l)
			bloc[w++][l] = '\0';
	}
	bloc[w] = 0;
	return (bloc);
}
