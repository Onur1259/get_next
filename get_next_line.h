#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

char	*solsatirioku(int fd, char *kalan);
char	*get_next_line(int fd);
char	*yenisatir(char	*kalan);
char	*yenisolsatir(char *kalan);
//UTILS
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
#endif