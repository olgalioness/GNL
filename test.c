#include <stdio.h>
#include <fcntl.h>              //open
#include <stdlib.h>
#include <unistd.h>             //write, read
#include "libft/libft.h"

char	*ft_strdup(char *s)
{
	int		len;
	char	*str;

	len = 0;
	while (s[len])
		len++;
	str = (char*)malloc(len + 1);
	if (str == NULL)
		return (NULL);
	while (len >= 0)
	{
		str[len] = s[len];
		len--;
	}
	return (str);
}

int get_next_line(int fd, char **line)              // line - буква,  *line - строка, ** итзменить строку
{                                                   //1- осталось что читать 0 - файл закончился -1 ошибка, память недостаточно, fd - испорчен
    char buf[10 + 1];
    int byte_was_read;

    while ((byte_was_read = read(fd, buf, 10))                      //возвращает кол-во прочитанных символов(байт) 
	{
	buf[byte_was_read] = '\0';
	*line = ft_strjoin(*line, buf);									//склеит две строки , что в лайне было до этого
	 											//считали 10 букв, алацируется новая память, пойдет второй круг считается еще 10, общие 20 положаться в line.
	}
    *line = ft_strdup(buf);              //возвращает указатель на новую строку
    return (0);                          //разымкеновывание указателя и запись в нее строки
}

int main(void)
{
    char *line;
    int fd;

	
    fd = open("text.txt", O_RDONLY);
    get_next_line(fd, &line);
    printf("%s\n", line);
}
