#include <iostream>
#include <fstream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
using namespace std;

bool shorter_than(string v1, string v2);

int main()
{
    ifstream infile("input_data.txt");
    string word;
    vector<string> words;
    if (! infile)
    {
        cerr << "!! unable to open necessary file.";
        return -1;
    }else
    {
        while (infile >> word)
        {
            words.push_back(word);
        }
    }

    sort(words.begin(), words.end(), shorter_than);

    vector<string>::iterator iter = words.begin();
    for (; iter != words.end(); iter++)
    {
        cout << *iter << " ";
    }
    cout << endl;   
    
    return 0;
}

bool shorter_than(string v1, string v2)
{
    return v1.length() < v2.length() ? true : false;
}
