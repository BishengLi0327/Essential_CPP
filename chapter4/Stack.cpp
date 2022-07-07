#include "Stack.h"
#include <iostream>

int main()
{
    Stack s;
    string str;

    while (cin >> str && !s.full())
    {
        s.push(str);
    }

    cin.clear();

    cout << "What word to search for?";
    cin >> str;

    bool found = s.find(str);
    int count = found? s.count(str): 0;

    cout << str << (found ? " is " : " isn\'t " ) << "in the stack. ";
    if (found)
        cout << "It occurs " << count << "times.";    

    if (s.empty())
    {
        cout << '\n' << "Ooops: no strings were read -- balling out\n ";
        return 0;
    }
    
    s.peek(str);
    cout << '\n' << "The length of the last string is: " << str.size() << endl;

    // 将内容全部输出
    while (s.size()){
        if (s.pop(str) ){
            cout << str << ' ';
        }
    }
    cout << '\n' << "There are now " << s.size()
         << " elements in the stack!\n";
    return 0;
}