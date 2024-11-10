#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

// int get_next_line(FILE *fd)
// {
//     static char buf[BUFSIZ];
//     static char* bufp;
//     static int n = 0;

//     if (n == 0)
//     {
//         n = fread(buf, 1, sizeof(buf), fd);
//         bufp = buf;
//     }
//     return (n-- > 0) ? (unsigned char) *bufp++ : EOF;
// }
int ft_getc(int fd)
{
    static int n = 0;
    static char buf[BUFSIZ];
    static char *bufp;

    if (n == 0)
    {
        n = read(fd, buf, sizeof(buf));
        if (n <= 0)
            return EOF; // End of file or read error
        bufp = buf;
    }
    return (--n >= 0) ? (unsigned char)*bufp++ : EOF;
}

int main(void) {
    int fd;
    int c;

fd = open("//wsl.localhost/Ubuntu/root/programming/42common_core/42common_core/42common_core/get_net_line/text.txt", O_RDONLY);

    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    while ((c = ft_getc(fd)) != EOF && c != '\n') {
        printf("%c", c);
    }
    
    close(fd);
    return 0;
}
