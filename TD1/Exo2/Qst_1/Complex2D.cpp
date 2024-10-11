#include<iostream>
#include"Complex2D.h"

using namespace std;


Complex2D::Complex2D():
    x(0), y(0)
    {}

Complex2D::Complex2D(double c):
    x(c), y(c)
    {}

Complex2D::Complex2D(double a, double b):
    x(a), y(b)
    {}

Complex2D::Complex2D(Complex2D& c):
    x(c.getX()), y(c.getY())
    {}

void Complex2D::setX(double _x){
    x = _x;
}

void Complex2D::setY(double _y){
    y = _y;
}

void Complex2D::print(){
    cout << "Complex2D = " << x << " + i" << y << endl;
}
        
double Complex2D::getX() const {
    return x;
}

double Complex2D::getY() const{
    return y;
}

Complex2D Complex2D::operator + (const Complex2D& c) const{
    return Complex2D(x + c.x, y + c.y);
}

Complex2D Complex2D::operator - (const Complex2D& c) const{
    return Complex2D(x - c.x, y - c.y);
}

Complex2D Complex2D::operator * (const Complex2D& c) const{
    return Complex2D(x * c.x - y * c.y, x * c.y + y * c.y);
}
