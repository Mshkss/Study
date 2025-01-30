#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>

#define N 10000 

typedef struct {
    int sum1; 
    int sum2; 
    int matrix[N][N]; 
} SharedData;

int main() {
    key_t key = ftok("semfile", 65);
    int semid = semget(key, 1, IPC_CREAT | 0666);
    if (semid < 0) {
        perror("semget failed");
        exit(1);
    }

    semctl(semid, 0, SETVAL, 1); 

    key_t shmkey = ftok("shmfile", 65);
    int shmid = shmget(shmkey, sizeof(SharedData), IPC_CREAT | 0666);
    if (shmid < 0) {
        perror("shmget failed");
        exit(1);
    }

    SharedData *sharedData = (SharedData *) shmat(shmid, NULL, 0);
    if (sharedData == (SharedData *) -1) {
        perror("shmat failed");
        exit(1);
    }

    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            sharedData->matrix[i][j] = (i + j) % 2 == 0 ? rand() % 10 : -(rand() % 10);
        }
    }

    struct sembuf semOp;
    semOp.sem_num = 0;
    semOp.sem_flg = 0;

    
    for (int i = 0; i < 2; i++) {
        if (fork() == 0) {
            semOp.sem_op = -1;
            semop(semid, &semOp, 1); 

            if (i == 0) {

                for (int i = 0; i < N; i++) {
                    for (int j = i + 1; j < N - i - 1; j++) {
                        if (sharedData->matrix[i][j] > 0) {
                            sharedData->sum1 += sharedData->matrix[i][j];
                        }
                    }
                }
            } else {
                for (int i = 0; i < N; i++) {
                    for (int j = N - i - 1; j < N; j++) {
                        if (sharedData->matrix[i][j] < 0) {
                            sharedData->sum2 += abs(sharedData->matrix[i][j]);
                        }
                    }
                }
            }

            semOp.sem_op = 1;
            semop(semid, &semOp, 1); // Освобождение семафора
            exit(0);
        }
    }

    for (int i = 0; i < 2; i++) {
        wait(NULL);
    }

  
    printf("Сумма положительных чисел: %d\n", sharedData->sum1);
    printf("Сумма модулей отрицательных чисел: %d\n", sharedData->sum2);
    if (sharedData->sum1 > sharedData->sum2) {
        printf("Сумма положительных чисел больше.\n");
    } else {
        printf("Сумма модулей отрицательных чисел больше.\n");
    }

    semctl(semid, 0, IPC_RMID);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}

