#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == 0) {
        while(1)
        ;
        exit(123);
    } else if (pid > 0) {
        waitpid(pid, &status, 0);
        if (WIFEXITED(status)) {
            int exitStatus = WEXITSTATUS(status);
            printf("Child process exit with: %d\n", exitStatus);
        }
    }
    return 0;
}
