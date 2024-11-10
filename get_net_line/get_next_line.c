#include <stdio.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int get_next_line(FILE *fd)
{
    static char buf[BUFSIZ];
    static char* bufp;
    static int n = 0;

    if (n == 0)
    {
        n = fread(buf, 1, sizeof(buf), fd);
        bufp = buf;
    }
    return (n-- > 0) ? (unsigned char) *bufp++ : EOF;
}

int main(void)
{
    FILE *fd;
    int c;

    fd = fopen("test.txt", "r");
    if (fd == NULL) {
        perror("Error opening file");
        return 1;
    }

    while (1) {
        c = get_next_line(fd);
        if (c == EOF)
            break;
        printf("%c", c);
    }

    fclose(fd);
    return 0;
}
