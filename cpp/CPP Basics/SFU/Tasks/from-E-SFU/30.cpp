#include <iostream>
#include <cstring>
using namespace std;

size_t join(char* s_out, size_t len, char** s_in, size_t n_in, char* sep) {

    int New_len = 0;
    for (size_t i = 0; i < n_in; i++) {
        for (size_t j = 0; j < strlen(s_in[i]); j++) {
            if (New_len < len) {
                s_out[New_len] = s_in[i][j];
                New_len++;
            }
        }
        for (size_t k = 0; k < strlen(sep); k++){
            if (New_len < len && i != n_in - 1) {
                s_out[New_len] = sep[k];
                New_len++;
            }
        }
    }
    s_out[New_len] = '\0';
    cout << "Новая строка" << endl << s_out << endl << endl;
    return New_len;

}

int main()
{
    setlocale(0, "");

    size_t n_in;
    cout << "Задайте количество строк (Затем нажмите клавишу 'Enter')" << endl;
    cin >> n_in;
    char** s_in = new char* [n_in];
    for (size_t i = 0; i < n_in; i++) {
        s_in[i] = new char[255];
    }
    cin.get();

    cout << "Введите строки с клавиатуры (После каждой строки нажмите клавишу 'Enter')" << endl;
    for (size_t i = 0; i < n_in; i++) {
        cin.getline(s_in[i], 255);
    }

    char sep[255];
    cout << "Задайте строку разделитель (Затем нажмите клавишу 'Enter')" << endl;
    cin.getline(sep, 255);

    size_t len;
    cout << "Укажите длину конечной строки 's_out' (Затем нажмите клавишу 'Enter') " << endl;
    cin >> len;

    char* s_out = new char[len];
    size_t New_len = join(s_out, len, s_in, n_in, sep);
    cout << "Эффективная длина строки = " << New_len;
}
