#ifndef PRICE_H
#define PRICE_H

#include <iostream>
#include <fstream>

struct Price {
    int grn;
    int short kop;
};

void addPrice(const Price& price1, const Price& price2, Price& result);
void mulPrice(const Price& price, int quantity, Price& result);
void roundTo10Kop(Price& price);
void printPrice(const Price& price);

#endif
