/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdupless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 13:41:19 by qdupless          #+#    #+#             */
/*   Updated: 2015/12/06 17:25:16 by qdupless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	if (!s || !(str = ft_strnew(ft_strlen(s) + 1)))
		return (NULL);
	while (s[k])
		k++;
	k--;
	while (s[i] == ' ' || s[i] == ',' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (s[k] == ' ' || s[k] == ',' || s[k] == '\n' || s[k] == '\t')
		k--;
	while (s[i] && i <= k)
		str[j++] = s[i++];
	str[j] = '\0';
	return (str);
}
