#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

vector<int> * fibon_seq(int pos, ofstream &ofil);

int main()
{
    int pos;
    ofstream outfile("fibon_seq.txt");
    vector<int> * elems;

    cout << "Please enter a position: ";
    while (cin >> pos)
    {  
        elems = fibon_seq(pos, outfile);
        if (elems)
        {
            cout << "the fibon num on pos " << pos << " is:\n";
            cout << (*elems)[pos-1] << "\n";
        }else
        {
            cout << "Sorry, could not calculate element # " << pos << endl;
        }
        cout << "Please enter another position: ";        
    }
    return 0;
}


vector<int> * fibon_seq(int pos, ofstream &ofil)
{
    static vector<int> elems;
    if (pos<=0 || pos > 1024)
    {
        return NULL;
    }
    for (int index = elems.size(); index < pos; index++)
    {
        if (index == 0 || index == 1)
        {
            elems.push_back(1);
            ofil << 1 << " ";
        }else
        {
            elems.push_back(elems[index-1]+elems[index-2]);
            ofil << (elems[index-1]+elems[index-2]) << " ";
        }
    }
    return &elems;
}