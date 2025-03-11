#include "Price.h"
#include <cmath>

using namespace std;

Price::Price() : grn(0), kop(0) {}

Price::Price(int grn, short int kop) : grn(grn), kop(kop) {}

Price Price::operator+(const Price& other) {
    int fullKop = kop + other.kop;
    int carry = fullKop / 100;
    return Price(grn + other.grn + carry, fullKop % 100);
}

Price Price::operator*(int num) {
    int fullKop = grn * 100 + kop;
    int resultKop = round(fullKop * num);
    return Price(resultKop / 100, resultKop % 100);
}

void Price::roundTo10Kop() {
    if (kop > 95) {
        grn++;
        kop = 0;
    } else if (kop < 5) {
        kop = 0;
    }
    if (kop % 10 < 5) kop -= kop % 10;
    else kop += 10 - (kop % 10);
}

void Price::print() const {
    cout << grn << " грн " << kop << " коп";
}
