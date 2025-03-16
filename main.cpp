#include <iostream>
#include <fstream>
#include "Price.cpp"

using namespace std;

int main() {
    setlocale(LC_ALL, "uk-UA.UTF-8");

    ifstream file("C:/OOP/Lab_1_OOP/price.txt");
    if (!file) {
        cout << "Не вдалося відкрити файл!" << endl;
        return 1;
    }

    Price totalPrice = {0, 0};
    int grn, quantity;
    int short kop;
    
    while (file >> grn >> kop >> quantity) {
        Price price = {grn, kop};
        Price resultPrice;
        mulPrice(price, quantity, resultPrice);
        addPrice(totalPrice, resultPrice, totalPrice);
    }
    
    file.close();

    cout << "Загальна сума: ";
    printPrice(totalPrice);
    cout << endl;

    roundTo10Kop(totalPrice);
    cout << "Сума до оплати (заокруглена): ";
    printPrice(totalPrice);
    cout << endl;

    return 0;
}
