#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <time.h>

#define PORT 1125
#define MAX_TICKETS 100
#define WINNING_NUMBER 7 // Счастливое число

int tickets[MAX_TICKETS];
int tickets_left = MAX_TICKETS;
int winning_tickets = 0;

void init_tickets() {
    for (int i = 0; i < MAX_TICKETS; i++) {
        tickets[i] = i + 1;
    }
    srand(time(NULL)); // Инициализация генератора случайных чисел
}

int is_winning_ticket(int ticket_number) {
    // Определение счастливого билета (например, если номер делится на 7)
    return ticket_number % WINNING_NUMBER == 0;
}

void process_client(int client_socket) {
    char buf[256];
    int num;

    // Получаем запрос от клиента
    num = recv(client_socket, buf, sizeof(buf), 0);
    if (num <= 0) {
        fprintf(stdout, "\nОшибка чтения данных от клиента\n");
        close(client_socket);
        return;
    }

    buf[num] = '\0'; // Убедимся, что строка завершена
    printf("Получен запрос от клиента: %s\n", buf);

    // Обрабатываем запрос
    if (strncmp(buf, "GET_TICKET", 10) == 0) {
        if (tickets_left > 0) {
            int ticket = tickets[MAX_TICKETS - tickets_left];
            tickets_left--;

            if (is_winning_ticket(ticket)) {
                winning_tickets++;
                sprintf(buf, "Вы получили билет №%d (счастливый!)", ticket);
            } else {
                sprintf(buf, "Вы получили билет №%d (не счастливый)", ticket);
            }
        } else {
            sprintf(buf, "Билеты закончились!");
        }
    } else if (strncmp(buf, "GET_STATS", 9) == 0) {
        sprintf(buf, "Осталось %d билетов. Выигрышных билетов: %d", tickets_left, winning_tickets);
    } else {
        sprintf(buf, "Неизвестная команда");
    }

    // Отправляем ответ клиенту
    num = send(client_socket, buf, strlen(buf), 0);
    if (num < 0) {
        fprintf(stdout, "\nОшибка отправки данных клиенту\n");
    }

    close(client_socket); // Закрываем соединение с клиентом
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len;

    // Инициализация билетов
    init_tickets();

    // Создаем сокет
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        fprintf(stdout, "\nНевозможно создать сокет\n");
        return 1;
    }

    // Настройка адреса сервера
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Привязка сокета к адресу
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        fprintf(stdout, "\nОшибка привязки сокета\n");
        return 1;
    }

    // Ожидание подключений
    if (listen(server_socket, 5) < 0) {
        fprintf(stdout, "\nОшибка вызова listen()\n");
        return 1;
    }

    printf("Сервер запущен и ожидает подключения...\n");

    // Основной цикл работы сервера
    while (1) {
        client_len = sizeof(client_addr);
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_len);
        if (client_socket < 0) {
            fprintf(stdout, "\nОшибка accept()\n");
            continue;
        }

        printf("Клиент подключен\n");

        // Создаем процесс для обработки клиента
        if (fork() == 0) {
            close(server_socket); // Закрываем серверный сокет в дочернем процессе
            process_client(client_socket);
            exit(0);
        }

        close(client_socket); // Родительский процесс не использует клиентский сокет
    }

    close(server_socket); // Закрываем серверный сокет при завершении работы
    return 0;
}

