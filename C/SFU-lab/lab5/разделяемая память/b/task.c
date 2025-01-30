#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>

int main() {
    int shmid = shmget(IPC_PRIVATE, 5 * sizeof(int), IPC_CREAT | 0666);
    if (shmid == -1) return 1;

    int *shared_memory = (int *)shmat(shmid, NULL, 0);
    if (shared_memory == (void *)-1) return 1;

    pid_t pids[3];

    while (1) {
        for (int i = 0; i < 3; i++) {
            if ((pids[i] = fork()) == 0) {
                // Seed the random number generator using the process ID (or any other unique value)
                srand(getpid());
                shared_memory[i] = rand() % 50;
                printf("potok %d: %d\n", i + 1, shared_memory[i]);
                shmdt(shared_memory);
                sleep(1.5);
                exit(0);
            }
        }

        for (int i = 0; i < 3; i++) waitpid(pids[i], NULL, 0);

        if (shared_memory[0] == shared_memory[1] ||
            shared_memory[0] == shared_memory[2] ||
            shared_memory[1] == shared_memory[2]) break;
    }

    shmdt(shared_memory);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}

