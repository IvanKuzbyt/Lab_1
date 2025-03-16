#include "Price.h"

using namespace std;

void addPrice(const Price& price1, const Price& price2, Price& result) {
    int totalKop = (price1.grn * 100 + price1.kop) + (price2.grn * 100 + price2.kop);
    result.grn = totalKop / 100;
    result.kop = totalKop % 100;
}

void mulPrice(const Price& price, int quantity, Price& result) {
    int totalKop = (price.grn * 100 + price.kop) * quantity;
    result.grn = totalKop / 100;
    result.kop = totalKop % 100;
}

void roundTo10Kop(Price& price) {
    int remainder = price.kop % 10;
    if (remainder < 5) {
        price.kop -= remainder;
    } else {
        price.kop += (10 - remainder);
    }

    if (price.kop >= 100) {
        price.grn += price.kop / 100;
        price.kop %= 100;
    }
}

void printPrice(const Price& price) {
    cout << price.grn << " грн " << price.kop << " коп";
}
