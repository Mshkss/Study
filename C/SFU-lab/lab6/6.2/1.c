#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MATRIX_SIZE 4
#define MSG_KEY 1234 // фиксированный ключ для очереди сообщений

struct message {
    long mtype;
    int matrix[MATRIX_SIZE][MATRIX_SIZE];
};

int main() {
    int msgid = msgget(MSG_KEY, IPC_CREAT | 0666);
    if (msgid < 0) {
        perror("Ошибка при создании очереди сообщений");
        exit(1);
    }

    struct message msg;
    msg.mtype = 1; // Тип сообщения

    FILE *file = fopen("matrix.txt", "r");
    if (!file) {
        perror("Ошибка при открытии файла");
        exit(1);
    }

    // Считывание матрицы из файла
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            fscanf(file, "%d", &msg.matrix[i][j]);
        }
    }
    fclose(file);

    // Отправка сообщения
    if (msgsnd(msgid, &msg, sizeof(msg.matrix), 0) < 0) {
        perror("Ошибка при отправке сообщения");
        exit(1);
    }

    printf("Матрица успешно отправлена второму приложению.\n");
    return 0;
}

