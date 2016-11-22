/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdupless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 14:02:24 by qdupless          #+#    #+#             */
/*   Updated: 2015/12/08 18:17:23 by qdupless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_nb(const char *s, size_t i, char c)
{
	size_t	j;

	j = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		j++;
	}
	return (j);
}

static	size_t	ft_countwords(const char *s, size_t i, char c)
{
	size_t	j;

	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			j++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (j);
}

static	char	**ft_words(char **str, const char *s, char c, size_t nb)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			nb = ft_nb(s, i, c);
			str[j] = ft_strnew(nb);
			k = 0;
			while (s[i] != c && s[i] != '\0')
			{
				str[j][k] = s[i++];
				k++;
			}
			j++;
		}
		if (s[i])
			i++;
	}
	str[j] = NULL;
	return (str);
}

char			**ft_strsplit(const char *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	nb;
	char	**str;

	if (!s)
		return (NULL);
	i = 0;
	nb = 0;
	j = ft_countwords(s, i, c);
	if (!(str = (char**)malloc(sizeof(char*) * j + 1)))
		return (NULL);
	str = ft_words(str, s, c, nb);
	return (str);
}
