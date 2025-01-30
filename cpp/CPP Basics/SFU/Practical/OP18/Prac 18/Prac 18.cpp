#include <iostream>
#include <cmath>
#include <fstream>
#include <stdlib.h>
#include <ctime>
#include <time.h>
#include <stdio.h>

using namespace std;

struct node
{
    int data;
    node* rlink, * llink;
};
struct list
{
    node* first; // Первый узел
    node* last;  // Последний узел
};
list* List = new list;

void print_list(node* first, std::ostream& ost)
{
    node* k = first;
    while (k != NULL)
    {
        cout << k->data << ' ';
        ost << k->data << ' ';
        k = k->rlink;
    }
    cout << endl;
}
void print_list_rev(node* last, std::ostream& ost)
{
    node* k = last;
    while (k != NULL)
    {
        cout << k->data << ' ';
        ost << k->data << ' ';
        k = k->llink;
    }
    cout << endl;
}

int main()
{

    setlocale(0, "");

    ifstream in;
    in.open("in.txt");
    ofstream ost("out.txt");

    node* q, * k, * left, * right;
    int w;
    in >> w;
    k = new node;
    k->data = w;
    k->llink = NULL;
    k->rlink = NULL;
    right = k;
    q = k;
    in >> w;


    while (!in.eof()) { // создание списка из потока
        k = new node;
        k->data = w;
        k->rlink = q;
        // Связываем вновь созданный узел с предыдущим
        q->llink = k; // Связываем предыдущий узел с вновь созданным
        q = k;
        in >> w;
    }

    q->llink = NULL;
    left = q;

    print_list(List->first, ost);

    node* newnode; // Указатель на новый узел
    k = left;
    while (k != NULL)
    {
        if (k->data == 6 or k->data == 28 or k->data == 496)
        {
            newnode = new node;
            newnode->data = 228;
            newnode->rlink = k->rlink;
            newnode->llink = k;
            if (k == right)
                right = newnode; // Если добавляем после последнего
            else
                k->rlink->llink = newnode; // Добавляем в середину
            k->rlink = newnode;
        }
        k = k->rlink;
    }

    return 0;

}