#include <iostream>
#include <fstream>
using namespace std;
void wrap_text(std::istream& ist, std::ostream& ost, int max_line_len) {

    char str[255];
    while (!ist.eof()) {
        ist.getline(str, 255);
        for (int i = 0; i < strlen(str); i++) {
            if (i % max_line_len == 0) ost << endl;
            ost << str[i];
        }
    }
}

int main()

{
    setlocale(0, "");

    ifstream ist("ist.txt");
    ofstream ost("ost.txt");
  
    int max_line_len;
    cout << "Задайте максимальную длину строки (Затем нажмите клавишу 'Enter')" << endl;
    cin >> max_line_len;
    wrap_text(ist, ost, max_line_len);
    ost.close();

    cout << "Результат программы в текстовом документе 'ost.txt'" << endl;
}