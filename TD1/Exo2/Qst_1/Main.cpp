#include<iostream>
#include"Complex2D.h"

using namespace std;

int main(){

    Complex2D x2(3.5);
    Complex2D x3(x2);
    Complex2D x4(x2 - x3);
    x4.print();

    return 0;
}