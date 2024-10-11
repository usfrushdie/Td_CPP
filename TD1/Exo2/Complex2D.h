#ifndef COMPLEX2D_H
#define COMPLEX2D_H

class Complex2D{
    private:
        double x,y;
    public:
        Complex2D();
        Complex2D(double);
        Complex2D(double, double);
        Complex2D(Complex2D&);
        void setX(double);
        void setY(double);
        void print();
        double getX() const;
        double getY() const; 
        Complex2D operator + (const Complex2D&) const;
        Complex2D operator - (const Complex2D&) const;
        Complex2D operator * (const Complex2D&) const;

};

#endif