#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MATRIX_SIZE 4
#define MSG_KEY 1234 // тот же ключ

struct message {
    long mtype;
    int matrix[MATRIX_SIZE][MATRIX_SIZE];
};

int main() {
    int msgid = msgget(MSG_KEY, 0666);
    if (msgid < 0) {
        perror("Ошибка при подключении к очереди сообщений");
        exit(1);
    }

    struct message msg;

    // Получение сообщения
    if (msgrcv(msgid, &msg, sizeof(msg.matrix), 0, 0) < 0) {
        perror("Ошибка при получении сообщения");
        exit(1);
    }

    printf("Матрица получена. Вычисление сумм строк и столбцов:\n");

    // Вычисление сумм
    for (int i = 0; i < MATRIX_SIZE; i++) {
        int row_sum = 0, col_sum = 0;
        for (int j = 0; j < MATRIX_SIZE; j++) {
            row_sum += msg.matrix[i][j];
            col_sum += msg.matrix[j][i];
        }
        printf("Сумма строки %d: %d\n", i + 1, row_sum);
        printf("Сумма столбца %d: %d\n", i + 1, col_sum);
    }

    return 0;
}

