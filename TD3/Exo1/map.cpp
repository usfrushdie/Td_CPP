#include<iostream>
#include<vector>
#include<map>

using namespace std ;

void countFrequencyBruteForce ( const vector<int>& numbers ) {
    int c;
    for (const auto& i : numbers) {
        c = 0;
        for (const auto& j : numbers) {
            if(i==j)
                c++;
        }
        cout << "Le Frequence d'apparaition de " << i << " est : " << c << endl;
    }
}

map<int, int> countFrequencyOptimal(const vector<int>& numbers) {
    map<int, int> m;
    for (const auto& i : numbers) {
        m[i]++;
    }
    return m;
}

int main ( ) {
vector<int> numbers = {1 , 2 , 3 , 2 , 4 , 1 , 5 , 5 , 6 } ;
// Tes t coun tFrequencyBru teForce
cout << " Frequency ( Brute Force ) : " << endl ;
countFrequencyBruteForce ( numbers ) ;
// Tes t coun tFrequencyOp t imal
cout << " \nFrequency ( Optimal ) : " << endl ;
map<int , int> frequencyMapOptimal = countFrequencyOptimal ( numbers ) ;
for ( const auto& entry : frequencyMapOptimal ) {
cout << entry.first << " : - " << entry.second << "time(s) " << endl ;
}
return 0 ;
}