/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreina <sreina@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 17:06:19 by sreina            #+#    #+#             */
/*   Updated: 2020/07/25 17:06:25 by sreina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_new_keep(char **keep, char *str, int start)							// в новый кипер передаем . все что было в кипере, количество символов до  \n, и размер
{																			очищает старый и записывает новый
	char	*temp;

	temp = *keep;
	if (!(*keep = ft_substr(str, start, ft_strlen(str) - start)))			//записывается новый остаток строки
	{
		free(temp);
		return (-1);
	}
	free(temp);
	return (0);
}

int	ft_follow_str(char *str, char *sym)				// проходит по строке ищет \0  или  \n и возвращает указатель на конец
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	*sym = str[i];
	return (i);
}

int	ft_write_line(char *buf, char **line, char **keep)
{
	char	*str;
	char	*temp;
	char	sym;
	int		i;

	i = ft_follow_str(buf, &sym);							//размер до  \т \0
	if (!(str = ft_substr(buf, 0, i)))						//записывает указатель от ночала до 0  (i указатель на конец)
		return (-1);
	temp = *line;											// создаем временную переменную temp - записываем туда line
	if (!(*line = ft_strjoin(*line, str)))					// он соединяет line (пустую строку с этой строкой  str)
	{
		free(temp);										 все очищаем и возвращаем
		free(str);
		return (-1);
	}
	free(temp);
	free(str);
	if (buf[i] != '\0')
		if (ft_new_keep(keep, buf, i + 1) == -1)		// в новый кипер передаем . все что было в кипере, количество символов до  \n, и размер
			return (-1);
	if (buf[i] == '\n')
		return (1);
	return (2);
}

int	ft_re_keep(char **keep, char **line)								 перезапишет содержание кипера
{
	char	*temp;
	char	sym;

	temp = *line;
	if (!(*line = ft_substr(*keep, 0, ft_follow_str(*keep, &sym))))
	{
		free(temp);
		return (-1);
	}
	free(temp);
	if (ft_follow_str(*keep, &sym) != (int)ft_strlen(*keep))
	{
		if (ft_new_keep(keep, *keep, ft_follow_str(*keep, &sym) + 1) == -1)
			return (-1);
		if (sym == '\n')
			return (1);
	}
	else
	{
		free(*keep);
		*keep = NULL;
	}
	return (2);
}

int	get_next_line(int fd, char **line)
{
	static char	*keep;														//массви keep хранит все что после /n
	char		buf[BUFFER_SIZE + 1];
	int			res;

	if (!line || fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	*line = ft_strdup("");													//обнуляем лайн
	if (keep)																//проверем есть ли что в keep
	{
		res = ft_re_keep(&keep, line);
		if (res != 2)
			return (res);
	}
	while ((res = read(fd, buf, BUFFER_SIZE)) > 0)							//считываем информацию в буфер (вернет столько сколько байт удалось считать)
	{
		buf[res] = '\0';
		if ((res = ft_write_line(buf, line, &keep)) != 2 && res != 0)		 // информацию с буфера записываем в line, при помощи функции  write_line
			return (res);
		if (res == 0)														//дошли до конца файлаЮ а слеш н не встретили.
			break ;
	}
	if (res < 0)															//если read вернул ошибку
		return (-1);
	free(keep);																//очищает keep и возвращает 0 потому что дошел до конца
	return (0);
}


считает 100 символов в буфер и поставить \0

все что до \n  записываться в line, все что после в кипер.


сразу проверет есть ли кипер или запоминается
рекипер проверяет есть ли в этом кипере слеш \n,

файл из 9 символом 1123с \n  3456\n буфер 1500, за ожин раз считает все
123 \n в лайн, остальное перезапишем кипере     идем по рекиперу и ищем \n
если в ре киперу дошел до 0 , запише т в лайн вернет 2, освободит рекипер и пойдет в цикл while ,
 будет считывать буфер и смотреть что находится в буфере

eife_line что находится в буфере и куда записывать.



считывается в буфер, в буфере проверяется есть ли  \т \0
все что до слеш \n записывает в лайн, се что после в keep (хранилище)

первый делом он заходит и проверяет есть ли кипер, если кипер есть

если туда чтото записалось заходит в рекипере и проверяет есть ли там  \n
123456789
а буфер 1,500  он за один  он считает все.

до \n он запишет в  line, после \n все  переза запишет в keep , удалим до ж

\n - выкинет 1
если \0 то он вернет 2, запишет все в line, keep полностью освободит и пойдет в цикл while и будет считывать буфер


