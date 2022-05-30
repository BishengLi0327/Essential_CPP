#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <string>
using namespace std;

int main()
{
    map<string, int> words;
    set<string> word_exclusion = {"a", "an", "or", "the", "and", "but"};
    string word;
    ifstream in_file("input_data.txt");
    if (! in_file)
    {
        cerr << "!! unable to open the necessary file.";
        return -1;
    }else
    {
        while (in_file >> word)
        {
            if (word_exclusion.count(word))
                continue;
            words[word]++;
        }
    }
    
    map<string, int>::iterator it = words.begin();
    cout << "The word and the corresponding frequency are listed below:\n";
    for (; it != words.end(); it++)
    {
        cout << "key: " << it->first << ", value: " << it->second << endl;
    }
    
    return 0;
}