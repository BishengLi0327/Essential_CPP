#include <iostream>
#include <vector>
using namespace std;

bool is_size_ok(int size);
const vector<int> * fibon_seq(int size);
inline bool fibon_elem(int pos, int &elem);

int main()
{
    int pos;
    cout << "Please enter the position: ";
    while (cin >> pos)
    {
        int elem;
        if (fibon_elem(pos, elem))
        {
            cout << "the fibon elem on pos " << pos << " is: \n";
            cout << elem << endl;
        }else
        {
            cout << "Oops, could not calculate element # " << pos << endl;
        }
        cout << "Please enter another position: ";
    }
    return 0;
}

bool is_size_ok(int size)
{
    const int max_size = 1024;
    if (size <= 0 || size > max_size)
    {
        cerr << "Oops: requested size is not supported : "
             << size << " -- cannot fulfill request.\n";
        return false;
    }
    return true;
    
}

const vector<int> *fibon_seq(int size)
{
    const int max_size = 1024;
    static vector<int> elems;

    if (! is_size_ok(size))
    {
        return 0;
    }
    for (int index = elems.size(); index < size; index++)
    {
        if (index==0 || index==1)
        {
            elems.push_back(1);
        }else
        {
            elems.push_back(elems[index-1]+elems[index-2]);
        }
    }
    return &elems;
}

inline bool fibon_elem(int pos, int &elem)
{
    const vector<int> *pseq = fibon_seq(pos);

    if (! pseq)
    {
        elem = 0;
        return false;
    }else
    {
        elem = (*pseq)[pos-1];
        return true;
    }
}