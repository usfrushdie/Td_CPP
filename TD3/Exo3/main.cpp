#include <iostream>
#include <queue>
#include <stack>
#include <cctype>
#include <string>
using namespace std;

bool isPalindrome(const string& input) {
    int i;
    stack<char> s;
    queue<char> q;
    
    for(i=0; i<size(input); i++){
        s.push(input.at(i));
        q.push(input.at(i));
    }

    while (s.size()!=0)
    {
        if(s.top()!=q.front())
            break;
        s.pop();
        q.pop();
    }
    
    if(s.size()==0)
        return true;

    return false;
}

int main() {
    cout << boolalpha;
    cout << "Is 'racecar' a palindrome? " << isPalindrome("racecar") << endl;
    cout << "Is 'hello' a palindrome? " << isPalindrome("hello") << endl;
    return 0;
}
