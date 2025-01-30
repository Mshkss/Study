#include <stdio.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 1125

int main() {
    int sd, num;
    char buf[60];
    struct sockaddr_in saddr;

    // Установка соединения с сервером
    sd = socket(AF_INET, SOCK_STREAM, 0);
    if (sd < 0) {
        fprintf(stdout, "\nНевозможно создать сокет\n");
        return 0;
    }

    bzero(&saddr, sizeof(saddr));
    saddr.sin_family = AF_INET;
    saddr.sin_port = PORT;
    saddr.sin_addr.s_addr = INADDR_ANY; // Подключение к локальному серверу

    if (connect(sd, (struct sockaddr *)&saddr, sizeof(saddr)) < 0) {
        fprintf(stdout, "\nНевозможно установить соединение с сервером\n");
        return 0;
    }

    // Отправляем запрос на получение билета
    sprintf(buf, "GET_TICKET");
    num = send(sd, buf, sizeof(buf), 0);
    if (num < 0) {
        fprintf(stdout, "\nОшибка отправки запроса\n");
        return 0;
    }

    // Получаем ответ от сервера
    num = recv(sd, buf, sizeof(buf), 0);
    if (num < 0) {
        fprintf(stdout, "\nОшибка получения ответа\n");
        return 0;
    }
    printf("Ответ от сервера: %s\n", buf);

    // Запрос статистики
    sprintf(buf, "GET_STATS");
    num = send(sd, buf, sizeof(buf), 0);
    if (num < 0) {
        fprintf(stdout, "\nОшибка отправки запроса\n");
        return 0;
    }

    // Получаем статистику
    num = recv(sd, buf, sizeof(buf), 0);
    if (num < 0) {
        fprintf(stdout, "\nОшибка получения статистики\n");
        return 0;
    }
    printf("Статистика от сервера: %s\n", buf);

    close(sd);
    return 0;
}

