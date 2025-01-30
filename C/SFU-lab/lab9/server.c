#include <stdio.h>
#include <strings.h>
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
    srand(time(NULL));  // Инициализация генератора случайных чисел
}

int is_winning_ticket(int ticket_number) {
    // Определение счастливого билета (например, если номер делится на 7)
    return ticket_number % WINNING_NUMBER == 0;
}

void process_client(int sd2) {
    char buf[60];
    int num;

    // Получаем запрос от клиента
    num = recv(sd2, buf, sizeof(buf), 0);
    if (num < 0) {
        fprintf(stdout, "\nОшибка чтения данных от клиента\n");
        close(sd2);
        return;
    }

    // Обрабатываем запрос
    if (strncmp(buf, "GET_TICKET", 10) == 0) {
        if (tickets_left > 0) {
            // Выдаем билет
            int ticket = tickets[MAX_TICKETS - tickets_left];
            tickets_left--;

            // Проверяем, является ли билет счастливым
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
        // Отправляем статистику
        sprintf(buf, "Осталось %d билетов. Выигрышных билетов: %d", tickets_left, winning_tickets);
    } else {
        sprintf(buf, "Неизвестная команда");
    }

    // Отправляем ответ клиенту
    num = send(sd2, buf, sizeof(buf), 0);
    if (num < 0) {
        fprintf(stdout, "\nОшибка отправки данных клиенту\n");
    }

    close(sd2);
}

int main() {
    int sd, sd2;
    struct sockaddr_in saddr, caddr;
    socklen_t addrlen;

    // Инициализация билетов
    init_tickets();

    // Создаем сокет
    sd = socket(AF_INET, SOCK_STREAM, 0);
    if (sd < 0) {
        fprintf(stdout, "\nНевозможно создать сокет\n");
        return 0;
    }

    // Настройка адреса сервера
    bzero(&saddr, sizeof(saddr));
    saddr.sin_family = AF_INET;
    saddr.sin_addr.s_addr = INADDR_ANY;
    saddr.sin_port = PORT;

    // Привязка сокета к адресу
    if (bind(sd, (struct sockaddr *)&saddr, sizeof(saddr)) < 0) {
        fprintf(stdout, "\nНевозможно связать сокет с адресом\n");
        return 0;
    }

    // Ожидание подключений
    if (listen(sd, 3) < 0) {
        fprintf(stdout, "\nОшибка вызова listen()\n");
        return 0;
    }

    printf("Сервер запущен и ожидает подключения...\n");

    while (1) {
        bzero(&caddr, sizeof(caddr));
        addrlen = sizeof(caddr);
        sd2 = accept(sd, (struct sockaddr *)&caddr, &addrlen);
        if (sd2 < 0) {
            fprintf(stdout, "\nОшибка accept()\n");
            continue;
        }

        // Обработка клиента в отдельном процессе
        if (fork() == 0) {
            close(sd);
            process_client(sd2);
            return 0;
        }

        close(sd2);  // Родительский процесс не использует сокет клиента
    }

    close(sd);
    return 0;
}

