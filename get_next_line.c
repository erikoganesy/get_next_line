#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"
// char	*get_next_line(int fd)
// int main()
// {
// 	char buffer[10];
//     int n = 10;
// 	int fd = open("test.txt", O_RDONLY);
//     if (fd == -1) {
//         perror("Ֆայլի բացման սխալ");
//         return 1;
//     }
//     while(n > 0){
//         int	readbyte = read(fd, buffer, sizeof(buffer) - 1);
//         if (readbyte == -1) {
//             perror("Ֆայլի սխալ");
//             return 1;
//         }
//         buffer[readbyte] = '\0';
//         printf(" readed text is -  %s\n", buffer);
//         n--;
//     }
// 
//     close(fd);
//     return 0;
// }


int main()
{
    int fd;
    int readbyte; 
    char *buff;
    char *str;

    str = NULL;
    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("error with open file");
        return (1);
    }
    str = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    while (1)
    {
        readbyte = read(fd, buff, sizeof(buff) - 1);
        if (readbyte == -1)
            return (0);
        if (readbyte == 0)
            break;
        buff[readbyte] = '\0';
        str = ft_strjoin(str, buff);
        if (ft_strchr(str, '\n')){
            printf("%s", str);
            break;
        }
    }
    printf("%s", str);
    free(buff);
    free(str);
    return (0);   
}
