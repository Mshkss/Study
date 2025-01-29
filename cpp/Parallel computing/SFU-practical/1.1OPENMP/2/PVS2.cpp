#include <cmath>
#include <fstream>
#include <iostream>
#include <omp.h>
#include <string>

using namespace std;

static int single(double* a, double* b, double* c, double* d, const int Nmin, const int x, const int l) {
    cout << "SINGLE: " << endl;

    a[0] = x;
    b[0] = x;
    d[0] = 0;

    double start_time, end_time;
    start_time = omp_get_wtime(); // Измеряем время выполнения первого цикла

    for (int i = 1; i < Nmin; i++) {               // a, b, d
        for (int j = 0; j < l; j++) {
            a[i] = a[i - 1] + x;
            b[i] = (x * i) + x / (x * Nmin);
            d[i] = sin(d[i - 1] * i) + d[i - 1] + i / Nmin;
        }
    }

    for (int i = 0; i < Nmin; i++) {               // c
        for (int j = 0; j < l; j++) {
            c[i] = (a[i] * a[Nmin - i]) / (a[i] + b[i]);
        }
    }

    end_time = omp_get_wtime();
    double time_cycle_1 = end_time - start_time;
    cout << "Время 1 цикла = " << time_cycle_1 << " секунд" << endl;

    cout << "!ПЕРЕОПРЕДЕЛЕНИЕ!" << endl; // Измеряем время выполнения второго цикла

    start_time = omp_get_wtime();

    for (int i = 1; i < Nmin; i++) {               // b
        for (int j = 0; j < l; j++) {
            b[i] = (c[i] * i) + a[i] / i;
        }
    }

    for (int i = 0; i < Nmin; i++) {               // d
        for (int j = 0; j < l; j++) {
            d[i] = a[i] / (i + 1) + c[i] * Nmin;
        }
    }

    end_time = omp_get_wtime();
    double time_cycle_2 = end_time - start_time;
    cout << "Время 2 цикла = " << time_cycle_2 << " секунд" << endl;

    double total_time = time_cycle_1 + time_cycle_2; // Общее время выполнения программы
    cout << "Общее время выполнения = " << total_time << " секунд" << endl;

    ofstream outfile("outsingle.txt");
    if (outfile.is_open()) {
        for (int i = 0; i < Nmin; i++) {
            outfile << "a[" << i << "] = " << a[i] << endl;
        }
        outfile << "---------------------" << endl; // Разделитель между массивами
        for (int i = 0; i < Nmin; i++) {
            outfile << "b[" << i << "] = " << b[i] << endl;
        }
        outfile << "---------------------" << endl; // Разделитель между массивами
        for (int i = 0; i < Nmin; i++) {
            outfile << "c[" << i << "] = " << c[i] << endl;
        }
        outfile << "---------------------" << endl; // Разделитель между массивами
        for (int i = 0; i < Nmin; i++) {
            outfile << "d[" << i << "] = " << d[i] << endl;
        }
        outfile.close();

        return 0;
    }
}

static int multi(double* a, double* b, double* c, double* d, const int Nmin, const int x, const int l, const int k) {
    cout << "MULTI: " << endl;

    a[0] = x;
    b[0] = x;
    d[0] = 0;

    double start_time, end_time;

    // Первый цикл: Вычисление a и b
    start_time = omp_get_wtime();
#pragma omp parallel for schedule(dynamic) num_threads(k)
    for (int i = 1; i < Nmin; i++) {
        for (int j = 0; j < l; j++) {
            b[i] = (x * i) + x / (x * Nmin);
            a[i] = a[i - 1] + x;
        }
    }

    // Второй цикл: последовательное вычисление d
    for (int i = 1; i < Nmin; i++) {
        for (int j = 0; j < l; j++) {         
            d[i] = sin(d[i - 1] * i) + d[i - 1] + i / Nmin;
        }
    }

    // Третий цикл: Вычисление c
#pragma omp parallel for schedule(dynamic) num_threads(k)
    for (int i = 0; i < Nmin; i++) {
        for (int j = 0; j < l; j++) {
            c[i] = (a[i] * a[Nmin - i]) / (a[i] + b[i]);
        }
    }

    end_time = omp_get_wtime();
    double time_cycle_1 = end_time - start_time;
    cout << "Время 1 цикла = " << time_cycle_1 << " секунд" << endl;

    // Переопределение: Вычисление b
    cout << "Переопределение" << endl;
    start_time = omp_get_wtime();
#pragma omp parallel for schedule(dynamic) num_threads(k)
    for (int i = 1; i < Nmin; i++) {
        for (int j = 0; j < l; j++) {
            b[i] = (c[i] * i) + a[i] / i;
        }
    }

    // Переопределение: Вычисление d
#pragma omp parallel for schedule(dynamic) num_threads(k)
    for (int i = 0; i < Nmin; i++) {
        for (int j = 0; j < l; j++) {
            d[i] = a[i] / (i + 1) + c[i] * Nmin;
        }
    }

    end_time = omp_get_wtime();
    double time_cycle_2 = end_time - start_time;
    cout << "Время 2 цикла = " << time_cycle_2 << " секунд" << endl;

    double total_time = time_cycle_1 + time_cycle_2;
    cout << "Общее время выполнения = " << total_time << " секунд" << endl;

    //return 0;
    // Запись в файл
    ofstream outfile("outmulti.txt");
    if (outfile.is_open()) {
        for (int i = 0; i < Nmin; i++) {
            outfile << "a[" << i << "] = " << a[i] << endl;
        }
        outfile << "---------------------" << endl;
        for (int i = 0; i < Nmin; i++) {
            outfile << "b[" << i << "] = " << b[i] << endl;
        }
        outfile << "---------------------" << endl;
        for (int i = 0; i < Nmin; i++) {
            outfile << "c[" << i << "] = " << c[i] << endl;
        }
        outfile << "---------------------" << endl;
        for (int i = 0; i < Nmin; i++) {
            outfile << "d[" << i << "] = " << d[i] << endl;
        }
        outfile.close();
    }

    return 0;
}


void compareFiles(const string& file1, const string& file2) {
    ifstream f1(file1);
    ifstream f2(file2);

    if (!f1.is_open() || !f2.is_open()) {
        cerr << "Ошибка при открытии файлов!" << endl;
        return;
    }

    string line1, line2;
    int lineNumber = 0;
    bool foundDifference = false;

    while (getline(f1, line1) && getline(f2, line2)) {
        lineNumber++;
        if (line1 != line2) {
            foundDifference = true;
            cout << "Расхождение на строке " << lineNumber << ":" << endl;
            cout << "outmulti.txt: " << line1 << endl;
            cout << "outsingle.txt: " << line2 << endl;
            cout << "------------------------------" << endl;
        }
    }

    while (getline(f1, line1)) {
        lineNumber++;
        foundDifference = true;
        cout << "Расхождение на строке " << lineNumber << ": outmulti.txt имеет дополнительную строку: " << line1 << endl;
    }

    while (getline(f2, line2)) {
        lineNumber++;
        foundDifference = true;
        cout << "Расхождение на строке " << lineNumber << ": outsingle.txt имеет дополнительную строку: " << line2 << endl;
    }

    if (!foundDifference) {
        cout << endl;
        cout << "ФАЙЛЫ ИДЕНТИЧНЫ." << endl;
    }

    f1.close();
    f2.close();
}

int main() {

    setlocale(0, "");

    const int C = 12; // число логических процессоров пк
    const int l = 1; // сложность операции
    const int x = 2; // вводимый параметр
    const int Nmin = 50; //5000000 //10000000 //15000000
    const int Nmax = 3 * Nmin;
    const int k = 8; // количество потоков

    double* a = new double[Nmin];
    double* b = new double[Nmin];
    double* c = new double[Nmin];
    double* d = new double[Nmin];

    single(a, b, c, d, Nmin, x, l);
    multi(a, b, c, d, Nmin, x, l, k);

    const string file1 = "outmulti.txt";
    const string file2 = "outsingle.txt";

    compareFiles(file1, file2);

    delete[] a;
    delete[] b;
    delete[] c;
    delete[] d;

    return 0;
}
