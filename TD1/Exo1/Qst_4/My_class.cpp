#include<iostream>
#include"My_class.h"

using namespace std;

my_class::my_class(){
    st = "";
}
        
my_class::my_class(string _s):
    st(_s)
{}

void my_class::print_my_element(){
            cout << st << endl;
}

