
#include "get_next_line.h"

int	new_storage(char **storage, char *str, int start)               очищает старый и записывает новый
{
	char	*temp;

	temp = *storage;
	if (!(*storage = ft_substr(str, start, ft_strlen(str) - start)))             //записывается новый остаток строки
	{
		free(temp);
		return (-1);
	}
	free(temp);
	return (0);
}

int	follow_str(char *str, char *sym)                            //проходит по массиву находит \0 или \n, возвращает порядковый номер
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')                    //перебираем  str и ищем \n , дошли до \n
		i++;
	*sym = str[i];                                              //записали в sym или строку \0 или строку \n
	return (i);                                                 //функция вернула  размер
}

int	write_line(char *buf, char **line, char **storage)
{
	char	*str;
	char	*tmp;
	char	sym;
	int		i;

	i = follow_str(buf, &sym);
	if (!(str = ft_substr(buf, 0, i)))                      
		return (-1);
	tmp = *line;
	if (!(*line = ft_strjoin(*line, str)))
	{
		free(tmp);
		free(str);
		return (-1);
	}
	free(tmp);
	free(str);
	if (buf[i] != '\0')
		if (new_storage(storage, buf, i + 1) == -1)
			return (-1);
	if (buf[i] == '\n')
		return (1);
	return (2);
}

int	restorage(char **storage, char **line)
{
	char	*tmp;
	char	sym;

	temp = *line;
	if (!(*line = ft_substr(*storage, 0, follow_str(*storage, &sym))))                 в лайн записали кипер
	{
		free(temp);
		return (-1);
	}
	free(temp);
	if (follow_str(*storage, &sym) != (int)ft_strlen(*storage))                           если     мама\n  = 4   != 10   длина кипера
	{
		if (new_storage(storage, *storage, follow_str(*storage, &sym) + 1) == -1)                       если в кипере был слеш н, то в новый кипер записывается только то что шло после слеш н
			return (-1);
		if (sym == '\n')
			return (1);
	}
	else
	{
		free(*storage);                              почистили кипер
		*storage = NULL;                                 весь кипер записали и почисли
	}
	return (2);
}

 int	get_next_line(int fd, char **line)
{
	static char	*storage;                                //запоминает все что идет после \n
    
	char		buf[BUFFER_SIZE + 1];                   //объявляем буфер с + 1 пустая строка
	int			reading_result;                                    //

    
	if (fd < 0 || BUFFER_SIZE <= 0  || !line )          //если подан плохоц  fd, если подан отрицатетельный или нулевый буфер, если не подана строка
		return (-1);
	*line = ft_strdup("");                              //чтобы не попал мусор
    
	if (storage)                                        // storage  - если что-то есть, заходим в функцию и перезаписываем storage
	{
		reading_result = restorage(&storage, line);
		if (reading_result != 2)
			return (reading_result);
	}
	while ((reading_result = read(fd, buf, BUFFER_SIZE)) > 0)              //считываем информацию с буфера
                                                                  //   рид возвращает столько байт  колько удалось считать.
	{
		buf[reading_result] = '\0';                            // добавление терминирующего нуля. для последющего записи в строку
		if ((reading_result = write_line(buf, line, &storage)) != 2 && reading != 0)          //записываем считанную информацию в line (ghb помощи функции write_line
			return (reading_result);
		if (reading_result == 0)                    дошли до конца файлаЮ а слеш н не встретили.
			break ;
	}
	if (reading_result < 0)
		return (-1);
	free(storage);
	return (0);                                 дошел доконца
}

int    main(void)
{
    int        fd;
    char    *line;
    //int res;

    line = NULL;
    fd = open("new_file.txt", O_RDONLY);
    //fd = 42;
    //fd = - 42;



    while (get_next_line(fd, &line))
    {
        printf("%s\n", line);
        free(line);
    }

/*
    while ((res = get_next_line(fd, &line)) > 0)
    {
        printf("%s\n\n", line);
        printf("%d\n", res);
        free(line);
    }

*/
    free(line);
    //sleep(15);
    return (0);
    
    
}

//czbnsdftncz d ,eath

все что до \n  записываться в line, все что после в кипер.


сразу проверет есть ли кипер или запоминается
рекипер проверяет есть ли в этом кипере слеш \n,

файл из 9 символом 1123с \n  3456\n буфер 1500, за ожин раз считает все
123 \n в лайн, остальное перезапишем кипере     идем по рекиперу и ищем \n
если в ре киперу дошел до 0 , запише т в лайн вернет 2, освободит рекипер и пойдет в цикл while , будет считывать буфер и смотреть что находится в буфере

eife_line что находится в буфере и куда записывать.




