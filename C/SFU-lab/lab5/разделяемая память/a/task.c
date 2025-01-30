#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/wait.h>


int digit_count_check(int num, int n, int k) {
    int count = 0;
    while (num != 0) {
        if (abs(num % 10) == n) {
            count++;
        }
        num /= 10;
    }
    return count == k;
}

int main() {
    
    int n, k, A, B;

    printf("цифра n:");
    scanf("%d", &n);
    printf("сколько раз встречается k: ");
    scanf("%d", &k);
    printf("Введите начало интервала A: ");
    scanf("%d", &A);
    printf("Введите конец интервала B: ");
    scanf("%d", &B);
    
    key_t key = IPC_PRIVATE;
    int shm_id = shmget(key, sizeof(int), IPC_CREAT | 0666);
    if (shm_id < 0) {
        perror("shmget error");
        return 1;
    }

    int *shared_min = (int *)shmat(shm_id, NULL, 0);
    if (shared_min == (int *)-1) {
        perror("shmat error");
        return 1;
    }

    *shared_min = -1; 

    int num_processes = 4; 
    int range = (B - A + 1) / num_processes;

    for (int i = 0; i < num_processes; i++) {
        pid_t pid = fork();
        if (pid < 0) {
            perror("fork error");
            return 1;
        } else if (pid == 0) {
            int local_min = -1;
            int start = A + i * range;
            int end = (i == num_processes - 1) ? B : start + range - 1;

            for (int num = start; num <= end; num++) {
                if (digit_count_check(num, n, k) && num % 2 == 0) {
                    if (local_min == -1 || num < local_min) {
                        local_min = num;
                    }
                }
            }

            if (local_min != -1) {
                if (*shared_min == -1 || local_min < *shared_min) {
                    *shared_min = local_min;
                }
            }

            shmdt(shared_min); 
            exit(0);
        }
    }

    for (int i = 0; i < num_processes; i++) {
        wait(NULL);
    }

    if (*shared_min != -1) {
        printf("Минимальное четное значение из выбранного промежутка: %d\n", *shared_min);
    } else {
        printf("не найдено.\n");
    }

    shmdt(shared_min);
    shmctl(shm_id, IPC_RMID, NULL);

    return 0;
}

