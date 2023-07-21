#include "get_next_line.h"

int				ft_strchrs(const char *s, char c)
{
	size_t		i;

	if (NULL == s)
		return (-1);
	i = 0;
	if ('\0' == c)
	{
		while (s[i] != '\0')
			i++;
		return (i);
	}
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int				recording(char **storage, char **line)
{
	size_t		i;
	char		*buffer;

	i = 0;
	i = (0 <= ft_strchrs(*storage, '\n')) ?
		ft_strchrs(*storage, '\n') : ft_strchrs(*storage, '\0');
	if (!(*line = ft_strndup(*storage, i)))
		return (-1);
	if (!(buffer = ft_strdup(*storage + i + 1)))
		return (-1);
	free(*storage);
	*storage = buffer;
	return (1);
}

int				reading(const int fd, char **storage)
{
	int			ret;
	char		buffer[BUFF_SIZE + 1];
	char		*temp;

	while (0 > ft_strchrs(*storage, '\n'))
	{
		if (((ret = read(fd, buffer, BUFF_SIZE)) == 0)
				&& (0 < ft_strchrs(*storage, '\0')))
			return (1);
		else if (ret == 0)
			return (0);
		buffer[ret] = '\0';
		if (NULL == *storage)
			*storage = ft_strdup(buffer);
		else
		{
			temp = ft_strjoin(*storage, buffer);
			free(*storage);
			*storage = temp;
		}
		if (NULL == storage)
			return (-1);
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	int			ret;
	static char	*storage;
	char		str[10];

	ret = 1;
	if ((fd < 0) || !line || read(fd, str, 0))
		return (-1);
	if (0 <= ft_strchrs(storage, '\n'))
		ret = recording(&storage, line);
	else
	{
		ret = reading(fd, &storage);
		if (1 == ret)
			ret = recording(&storage, line);
	}
	return (ret);
}