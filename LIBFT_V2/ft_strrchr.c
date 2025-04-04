/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbardet- <rbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 08:42:02 by rbardet-          #+#    #+#             */
/*   Updated: 2024/10/22 14:39:13 by rbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				a;
	char			*str;
	char unsigned	c1;

	str = (char *)s;
	c1 = (char unsigned)c;
	a = 1;
	while (*str != '\0')
	{
		str++;
		a++;
	}
	while (a != 0)
	{
		if ((char unsigned)*str == c1)
			return (str);
		str--;
		a--;
	}
	return (NULL);
}
// int main(void)
// {
// 	const char str[] = "jbbbbbbbb";
// 	printf("%s", ft_strrchr(str, 'j'));
// 	return(0);
// }
