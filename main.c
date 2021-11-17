#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    // initializing randompid
    srand(time(NULL));
    int pid = fork();

    if (pid > 0)
    {
        int pid_2 = fork();
        if (pid_2 > 0)
        {
            int status;
            int child_pid = wait(&status);
            int sleep_time = WEXITSTATUS(status);
            printf("Child pid: %d\tChild sleep time: %d\n", child_pid, sleep_time);
            printf("Parent is done\n");
        }
        else
        {
            printf("Child 1 pid: %d\n", getpid());
            // in the range [2,5]
            int sleep_time_1 = rand() % 4 + 2;
            sleep(sleep_time_1);
            printf("Child 1 is done\n");
            return sleep_time_1;
        }
    }

    if (pid == 0)
    {
        printf("Child 0 pid: %d\n", getpid());
        int sleep_time_0 = rand() % 4 + 2;
        sleep(sleep_time_0);
        printf("Child 0 is done\n");
        return sleep_time_0;
    }

    return 0;
}
