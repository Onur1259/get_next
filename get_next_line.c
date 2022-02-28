#include "get_next_line.h"
#include <stdio.h>

char	*yenisatir(char	*kalan)
{
	char	*str;
	int		i;

	i = 0;
	if(!kalan[i])
		return(NULL);
	while(kalan[i] && kalan[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if(!str)
		return(NULL);
	i = 0;
	while(kalan[i] && kalan[i] != '\n')
	{
		str[i] = kalan[i];
		i++;
	}
	if(kalan[i] == '\n')
	{
		str[i] = kalan[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
char	*yenisolsatir(char *kalan)
{
	int	i;
	int	j;
	char	*str;

	i = 0;
	while(kalan[i] && kalan[i] != '\n')
		i++;
	if (!kalan[i])
	{
		free(kalan);
		return (NULL);
	}
	str =(char *)malloc(sizeof(char) * (ft_strlen(kalan) - i + 1));
	if(!str)
		return(NULL);
	i++;
	j = 0;
	while(kalan[i])
		str[j++] = kalan[i++];
	str[j] = '\0';
	free(kalan);
	return(str);
}

char	*solsatirioku(int fd, char *kalan)
{
	char	*buff;
	int		okunan_byte;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if(!buff)
		return (0);
	okunan_byte = 1;
	while(!ft_strchr(kalan, '\n') && okunan_byte != 0)
	{
		okunan_byte = read(fd, buff, BUFFER_SIZE);
		if(okunan_byte == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[okunan_byte] = '\0';
		kalan = ft_strjoin(kalan, buff);
	}
	free(buff);
	return (kalan);
}

char	*get_next_line(int fd)
{
	char	*str;	
	static char	*kalan;

	if(fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	kalan = solsatirioku(fd,kalan);
	if(!kalan)
		return (NULL);
	str = yenisatir(kalan);
	kalan =yenisolsatir(kalan);
	return(str);

}

int	main(void)
{
	char *line;
	int fd;
	
	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
		line = get_next_line(fd);
	printf("%s", line);
		line = get_next_line(fd);
	printf("%s", line);
		line = get_next_line(fd);
}