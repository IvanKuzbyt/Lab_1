#include <iostream>
#include <fstream>
#include "Price.cpp"

using namespace std;

int main() {
    setlocale(LC_ALL, "uk_UA.UTF-8");

    ifstream file("C:/OOP/Lab_1_OOP/price.txt");
    if (!file) {
        cerr << "Помилка відкриття файлу!" << endl;
        return 1;
    }

    Price total;
    Price totalSum;
    int c;

    while (file >> total.grn >> total.kop >> c) {
        total = total * c;
        //total.print();
        cout << endl;
        totalSum = totalSum + total;
    }

    cout << "Загальна сума = ";
    totalSum.print();
    cout << endl;
    cout << "Загальна сума з скороченням = ";
    totalSum.roundTo10Kop();
    totalSum.print();
    cout << endl << endl;

    file.close();
    return 0;
}
