#ifndef PRICE_H
#define PRICE_H

#include <iostream>

class Price {
public:
    int grn;
    short int kop;

    Price();
    Price(int grn, short int kop);

    Price operator+(const Price& other);
    Price operator*(int num);
    void roundTo10Kop();
    void print() const;
};

#endif // PRICE_H
