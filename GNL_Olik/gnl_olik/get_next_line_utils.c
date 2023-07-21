/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreina <sreina@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 17:06:04 by sreina            #+#    #+#             */
/*   Updated: 2020/07/25 17:06:13 by sreina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int		ft_strlcpy(char *dest, const char *source, size_t n)
{
	unsigned int	i;
	size_t			size;

	if (!dest && !source)
		return (0);
	i = 0;
	size = ft_strlen(source);
	if (n == 0)
		return (size);
	while (source[i] && (i < (n - 1)))
	{
		dest[i] = source[i];
		i++;
	}
	dest[i] = '\0';
	return (size);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	i;
	size_t	s1_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	if (!(result = (char*)malloc((s1_len + ft_strlen(s2) + 1) * sizeof(char))))
		return (NULL);
	ft_strlcpy(result, s1, s1_len + 1);
	i = 0;
	while (s2[i] != '\0')
	{
		result[i + s1_len] = s2[i];
		i++;
	}
	result[i + s1_len] = '\0';
	return (result);
}

char	*ft_strdup(const char *s)
{
	unsigned int	i;
	int				len;
	char			*str;

	i = 0;
	while (s[i] != '\0')
		i++;
	len = 1 + i;
	str = (char*)malloc(sizeof(char) * len);
	if (str)
	{
		i = 0;
		while (s[i] != '\0')
		{
			str[i] = s[i];
			i++;
		}
		str[i] = '\0';
	}
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)			// создает подстроку
{
	char	*str;
	size_t	i;
	size_t	len_s;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);								//записывает размер переданного буфера
	if (start >= len_s)									//если буфер пустой - запишет новую строку
		return (ft_strdup(""));
	if (len > len_s)									//если размер строки до  \n больше чем размер буфера, то отрежем по размеру строки
		len = len_s - start;
	str = (char*)malloc((len + 1) * sizeof(char));		 // алацируем память
	if (!str)
		return (NULL);
	i = 0;
	while (s[i + start] != '\0' && i < len)				  // создаем массив под размер строки и запишем туда туда строку до \n
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
