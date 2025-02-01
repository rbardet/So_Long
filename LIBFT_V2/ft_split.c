/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbardet- <rbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:46:00 by rbardet-          #+#    #+#             */
/*   Updated: 2024/11/08 04:39:31 by rbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_charset(char const c, char *charset)
{
	int	a;

	a = 0;
	while (charset[a])
	{
		if (c == charset[a])
			return (1);
		a++;
	}
	return (0);
}

static char	*ft_copy(char const *str, int deb, int f)
{
	char	*mot;
	int		a;

	mot = malloc((f - deb + 1) * sizeof(char));
	if (!mot)
		return (NULL);
	a = 0;
	while (deb < f)
	{
		mot[a] = str[deb];
		a++;
		deb++;
	}
	mot[a] = '\0';
	return (mot);
}

static void	*free_tab(char **tab, int a)
{
	while (a > 0)
	{
		free(tab[a]);
		a--;
	}
	free(tab);
	return (NULL);
}

static char	**ft_tab(char const *str, char *c, int nb_mot, char **tab)
{
	int		a;
	int		b;
	int		debut;

	a = 0;
	b = 0;
	while (str[a] && b < nb_mot)
	{
		while (str[a] && ft_charset(str[a], c))
			a++;
		debut = a;
		while (str[a] && !ft_charset(str[a], c))
			a++;
		if (a > debut)
		{
			tab[b] = ft_copy(str, debut, a);
			if (!tab[b])
				return (free_tab(tab, b));
			b++;
		}
	}
	tab[b] = NULL;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	int		nb_mots;
	char	tmp[2];
	char	**tab;
	int		a;

	tmp[0] = c;
	a = 0;
	nb_mots = 0;
	while (s[a])
	{
		if (!ft_charset(s[a], &c))
		{
			if (a == 0 || ft_charset(s[a - 1], &c))
				nb_mots++;
		}
		a++;
	}
	tab = malloc((nb_mots + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	return (ft_tab(s, tmp, nb_mots, tab));
}
	// int main(void)
	// {
	// char str[] = ";AAA;VVV;BBB;CCC";
	// char c = ';';
	// char **str2 = ft_split(str, c);
	// while (*str2 != 0)
	// {
	// 	printf("%s\n", *str2);
	// 	str2++;
	// }
	// return(0);
	// }
