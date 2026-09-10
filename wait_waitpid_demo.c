#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define NUM_CHILDREN 3

int main()
{
    pid_t child_pid[NUM_CHILDREN];
    int status;
    int i;

    printf("Parent Process: PID = %d\n", getpid());

    for (i = 0; i < NUM_CHILDREN; i++)
    {
        child_pid[i] = fork();

        if (child_pid[i] < 0)
        {
            perror("fork failed");
            exit(EXIT_FAILURE);
        }

        if (child_pid[i] == 0)
        {
            printf("Child %d: PID = %d, PPID = %d\n",
                   i + 1, getpid(), getppid());

            sleep(i + 1);

            printf("Child %d: Completed after %d seconds.\n",
                   i + 1, i + 1);

            exit((i + 1) * 10);
        }
    }

    printf("\nParent: Waiting for any child using wait()...\n");

    pid_t waited_pid = wait(&status);

    if (waited_pid > 0)
    {
        printf("Parent: wait() collected child PID = %d\n",
               waited_pid);

        if (WIFEXITED(status))
        {
            printf("Parent: Child exit status = %d\n",
                   WEXITSTATUS(status));
        }
    }

    printf("\nParent: Waiting specifically for Child 2 using waitpid()...\n");

    if (waitpid(child_pid[1], &status, 0) > 0)
    {
        printf("Parent: waitpid() collected Child 2, PID = %d\n",
               child_pid[1]);

        if (WIFEXITED(status))
        {
            printf("Parent: Child 2 exit status = %d\n",
                   WEXITSTATUS(status));
        }
    }

    for (i = 0; i < NUM_CHILDREN; i++)
    {
        if (child_pid[i] != waited_pid && child_pid[i] != child_pid[1])
        {
            waitpid(child_pid[i], &status, 0);

            printf("Parent: Remaining child PID = %d collected.\n",
                   child_pid[i]);
        }
    }

    printf("\nParent: All children have completed.\n");

    return 0;
}
