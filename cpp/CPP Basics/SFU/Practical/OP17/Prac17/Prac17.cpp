#include <iostream>
#include <cmath>
#include <fstream>
#include <stdlib.h>
#include <ctime>
#include <time.h>

using namespace std;

struct node
{
    int data;
    node* next;
};

void print_list(node* top, ostream& out) {
    node *k = top;
    for (k = top; k != 0; k = k->next)
    {
        out << k->data;
    }
    cout << endl;
    cout << "print_list";
}
//node* insert_node(node* head, node* prev, node* n) { }

int main()
{
    int i, stime; // рандом
    long ltime;
    ltime = time(NULL);
    stime = (unsigned int)ltime / 2;
    srand(stime);

    setlocale(0, "");

    ifstream in;
    in.open("in.txt");
    ofstream out("out.txt");

    node* top, * k;
    int w;
    top = NULL;
    in >> w;
    int count = 1;

    while (!in.eof()) { // создание списка из потока
        k = new node;
        k->next = top;
        k->data = w;
        top = k;
        in >> w;
        count += 1;
    }
    cout << "count = " << count << endl;

    k = top;
    while (k != NULL) { // cout
        cout << k->data << " ";
        k = k->next;
    }
    cout << "удаление: " << endl;
    k = top;
    node* l = top;
    node* newnode;
    while (k != NULL) { // cout
        if (k->data == 6 or k->data == 28 or k->data == 496) {
            for (int j = 0; j < 5; ++j) {
                newnode = new node;
                // Добавление узла
                newnode->next = k->next;
                k->next = newnode;
                newnode->data = (rand() % k->data);
            }
            if (k == top) {
                // Если максимальный - вершина
                top = k->next;
                delete k;
                k = top;
            }
            else
            { // Ecли максимальный не веpшина
                l->next = k->next;
                delete k;
                k = l->next;
            }
        }
        else
        { // Eсли не максимальный
            l = k;
            k = k->next;
        }
    }
    cout << "final:" << endl;
    k = top;
    while (k != NULL) { // cout
        cout << k->data<< " ";
        k = k->next;
    }
    print_list(top, out);
}