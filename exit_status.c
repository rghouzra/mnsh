#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
# include <fcntl.h>
int main() {
    int fd = open("Makefile", O_RDWR, 0);
    printf("%d\n", fd);
    return 0;
}
