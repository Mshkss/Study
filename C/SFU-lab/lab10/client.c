#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <unistd.h>

#define PORT 1125

void send_request(int socket, const char *request) {
    char buf[256];
    int num;

    // Отправляем запрос серверу
    num = send(socket, request, strlen(request), 0);
    if (num < 0) {
        fprintf(stdout, "\nОшибка отправки запроса\n");
        return;
    }

    // Получаем ответ от сервера
    num = recv(socket, buf, sizeof(buf), 0);
    if (num < 0) {
        fprintf(stdout, "\nОшибка получения ответа\n");
        return;
    }

    buf[num] = '\0'; // Убедимся, что строка завершена
    printf("Ответ от сервера: %s\n", buf);
}

int main() {
    int client_socket;
    struct sockaddr_in server_addr;

    // Создаем сокет
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0) {
        fprintf(stdout, "\nНевозможно создать сокет\n");
        return 1;
    }

    // Настройка адреса сервера
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY; // Подключение к локальному серверу

    // Устанавливаем соединение с сервером
    if (connect(client_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        fprintf(stdout, "\nНевозможно установить соединение с сервером\n");
        return 1;
    }

    printf("Подключение к серверу успешно\n");

    // Отправляем запросы
    send_request(client_socket, "GET_TICKET");
    send_request(client_socket, "GET_STATS");

    close(client_socket); // Закрываем сокет
    return 0;
}

