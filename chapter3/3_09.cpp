#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    string word;
    vector<string> text;

    while (cin >> word)
        text.push_back(word);
    
    sort(text.begin(), text.end());

    for (int index = 0; index < text.size(); index++)
        cout << text[index] << " ";
    
    return 0;
}