/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonroe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 14:35:34 by smonroe           #+#    #+#             */
/*   Updated: 2018/04/23 02:33:03 by smonroe          ###   ########.fr       */
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
	char	*zero;

	num = n;
	i = 0;
	s = 0;
	zero = "0\0";
	if (!(rev = ft_strnew(ft_intlen(num))))
		return (NULL);
	if (num < 0)
	{
		num = -num;
		s = -1;
	}
	if (num == 0)
		return (zero);
	rev[i++] = (num % 10) + '0';
	while (num /= 10)
		rev[i++] = (num % 10) + '0';
	if (s == -1)
		rev[i++] = '-';
	ft_strrev(rev);
	return (rev);
}
