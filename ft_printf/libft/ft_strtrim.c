/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdupless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 13:41:19 by qdupless          #+#    #+#             */
/*   Updated: 2016/02/12 09:03:51 by qdupless         ###   ########.fr       */
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
	str = NULL;
	if (!s)
		return (NULL);
	k = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (s[i] == '\0')
		return (ft_strdup(""));
	while (s[k] == ' ' || s[k] == '\n' || s[k] == '\t')
		k--;
	if (!(str = ft_strnew(k - i + 1)))
		return (NULL);
	while (s[i] && i <= k)
		str[j++] = s[i++];
	str[j] = '\0';
	return (str);
}
