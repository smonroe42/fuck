/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonroe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 14:35:34 by smonroe           #+#    #+#             */
/*   Updated: 2018/04/23 05:33:39 by smonroe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int n)
{
	int	l;

	l = (n <= 0) ? 1 : 0;
	while (n != 0)
	{
		n /= 10;
		l++;
	}
	return (l);
}

char		*ft_itoa(int n)
{
	char	*rev;
	int		s;
	int		i;
	long	num;

	if (n == 0)
		return (ft_strdup("0"));
	num = n;
	i = 0;
	if (!(rev = ft_strnew(ft_intlen(num))))
		return (NULL);
	s = 0;
	if (num < 0)
	{
		num *= -1;
		s = 1;
	}
	rev[i++] = (num % 10) + '0';
	while (num /= 10)
		rev[i++] = (num % 10) + '0';
	if (s)
		rev[i] = '-';
	ft_strrev(rev);
	return (rev);
}
