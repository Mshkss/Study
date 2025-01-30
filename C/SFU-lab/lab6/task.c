#include <stdio.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <stdlib.h>

#define DIGIT_COUNT 10
#define PROCESS_COUNT 10

struct message {
    long mtype;
    int digit_count;
};

int count_digit(const char *str, char digit) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == digit) {
            count++;
        }
    }
    return count;
}

int main() {
    char S[1024];
    printf("Введите строку: ");
    fgets(S, sizeof(S), stdin);
    S[strcspn(S, "\n")] = '\0';

    int msgid = msgget(IPC_PRIVATE, IPC_CREAT | 0666); //создание очереди сообщений
    if (msgid < 0) {
        perror("Ошибка очереди");
        return 1;
    }

    for (int i = 0; i < PROCESS_COUNT; i++) {
        if (fork() == 0) { 
            struct message msg;
            msg.mtype = 1; 
            msg.digit_count = count_digit(S, '0' + i); 

            if (msgsnd(msgid, &msg, sizeof(msg.digit_count), 0) < 0) {
                perror("Ошибка отправки сообщения");
                exit(1);
            }

            exit(0); 
        }
    }
  
    int counts[DIGIT_COUNT] = {0};   //род процесс
    struct message msg;

    for (int i = 0; i < PROCESS_COUNT; i++) {
        if (msgrcv(msgid, &msg, sizeof(msg.digit_count), 0, 0) < 0) {
            perror("Ошибка получения сообщения");
            return 1;
        }
        counts[i] = msg.digit_count;
    }

    // удаление очереди сообщений
    printf("очередь создана");
    sleep(5);
    if (msgctl(msgid, IPC_RMID, NULL) < 0) {
        perror("Ошибка удаления очереди сообщений");
        return 1;
    }

    printf("Результаты:\n");
    for (int i = 0; i < DIGIT_COUNT; i++) {
        printf("Цифра %d: %d раз(а)\n", i, counts[i]);
    }

    int max1 = -1, max2 = -1;
    int digit1 = -1, digit2 = -1;  //поиск двух цифр

    for (int i = 0; i < DIGIT_COUNT; i++) {
        if (counts[i] > max1) {
            max2 = max1;
            digit2 = digit1;
            max1 = counts[i];
            digit1 = i;
        } else if (counts[i] > max2) {
            max2 = counts[i];
            digit2 = i;
        }
    }

    printf("Две наиболее часто встречающиеся цифры: %d (%d раз) и %d (%d раз)\n",
           digit1, max1, digit2, max2);
    return 0;
}

